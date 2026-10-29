//! Estudo Dirigido — Tratamento de Exceções em Rust
//!
//! Lê um arquivo texto com registros no formato `nome;nota1;nota2`,
//! calcula a média de cada estudante e trata os erros encontrados
//! sem encerrar a execução desnecessariamente.
//!
//! Uso: cargo run -- <arquivo>

use std::env;
use std::fmt;
use std::fs::File;
use std::io::{self, BufRead, BufReader};
use std::num::ParseFloatError;
use std::process;

/// Erros possíveis no processamento de UM registro (uma linha).
/// Cada variante corresponde a uma "classe de exceção" de uma
/// linguagem com tratamento tradicional.
#[derive(Debug)]
enum ErroRegistro {
    /// Um dos campos esperados não está presente na linha.
    CampoAusente { campo: &'static str },
    /// A linha possui mais campos que o esperado.
    CamposExcedentes,
    /// Um campo de nota não pôde ser convertido para f64.
    NotaInvalida {
        campo: &'static str,
        valor: String,
        causa: ParseFloatError,
    },
}

impl fmt::Display for ErroRegistro {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            ErroRegistro::CampoAusente { campo } => {
                write!(f, "campo ausente: '{}'", campo)
            }
            ErroRegistro::CamposExcedentes => {
                write!(f, "registro possui mais de três campos")
            }
            ErroRegistro::NotaInvalida { campo, valor, causa } => {
                write!(f, "valor inválido em '{}': \"{}\" ({})", campo, valor, causa)
            }
        }
    }
}

struct Estudante {
    nome: String,
    nota1: f64,
    nota2: f64,
}

impl Estudante {
    fn media(&self) -> f64 {
        (self.nota1 + self.nota2) / 2.0
    }
}

/// Obtém o próximo campo da linha.
/// `next()` devolve Option<&str>: None indica que o campo não existe.
/// O `match` converte esse Option em Result, associando um erro ao None
/// (campo vazio também é tratado como ausente).
fn proximo_campo<'a, I>(campos: &mut I, nome: &'static str) -> Result<&'a str, ErroRegistro>
where
    I: Iterator<Item = &'a str>,
{
    match campos.next() {
        Some(texto) if !texto.trim().is_empty() => Ok(texto.trim()),
        _ => Err(ErroRegistro::CampoAusente { campo: nome }),
    }
}

/// Converte o texto de uma nota para f64.
/// `parse` devolve Result<f64, ParseFloatError>; `map_err` traduz o erro
/// de baixo nível para o erro do domínio da aplicação.
fn converter_nota(texto: &str, campo: &'static str) -> Result<f64, ErroRegistro> {
    texto.parse::<f64>().map_err(|causa| ErroRegistro::NotaInvalida {
        campo,
        valor: texto.to_string(),
        causa,
    })
}

/// Analisa uma linha e constrói um Estudante.
/// Cada `?` propaga imediatamente o Err para quem chamou esta função.
fn analisar_linha(linha: &str) -> Result<Estudante, ErroRegistro> {
    let mut campos = linha.split(';');

    let nome = proximo_campo(&mut campos, "nome")?;
    let nota1 = converter_nota(proximo_campo(&mut campos, "nota1")?, "nota1")?;
    let nota2 = converter_nota(proximo_campo(&mut campos, "nota2")?, "nota2")?;

    if campos.next().is_some() {
        return Err(ErroRegistro::CamposExcedentes);
    }

    Ok(Estudante {
        nome: nome.to_string(),
        nota1,
        nota2,
    })
}

/// Processa o arquivo inteiro. Erros de E/S (abrir/ler o arquivo) são
/// propagados com `?`; erros de registro são tratados aqui mesmo com
/// `match`, permitindo continuar nas linhas seguintes.
/// Retorna (registros válidos, registros inválidos).
fn processar_arquivo(caminho: &str) -> io::Result<(usize, usize)> {
    let arquivo = File::open(caminho)?;
    let leitor = BufReader::new(arquivo);

    let mut validos = 0;
    let mut invalidos = 0;

    for (indice, linha) in leitor.lines().enumerate() {
        let linha = linha?;
        let numero = indice + 1;

        if linha.trim().is_empty() {
            continue;
        }

        match analisar_linha(&linha) {
            Ok(estudante) => {
                println!("{:<10} média: {:5.2}", estudante.nome, estudante.media());
                validos += 1;
            }
            Err(erro) => {
                eprintln!("[linha {}] registro ignorado — {}  => \"{}\"", numero, erro, linha);
                invalidos += 1;
            }
        }
    }

    Ok((validos, invalidos))
}

fn main() {
    let caminho = match env::args().nth(1) {
        Some(c) => c,
        None => {
            eprintln!("Uso: estudo-excecoes <arquivo>");
            process::exit(2)
        }
    };

    println!("Processando '{}'...", caminho);

    match processar_arquivo(&caminho) {
        Ok((validos, invalidos)) => {
            println!(
                "Concluído: {} registro(s) válido(s), {} inválido(s).",
                validos, invalidos
            );
        }
        Err(erro) if erro.kind() == io::ErrorKind::NotFound => {
            eprintln!("Erro: o arquivo '{}' não foi encontrado.", caminho);
            process::exit(1);
        }
        Err(erro) => {
            eprintln!("Erro ao ler '{}': {}", caminho, erro);
            process::exit(1);
        }
    }
}

#[cfg(test)]
mod testes {
    use super::*;

    #[test]
    fn registro_valido() {
        let e = analisar_linha("Maria;8.5;7.0").unwrap();
        assert_eq!(e.nome, "Maria");
        assert_eq!(e.media(), 7.75);
    }

    #[test]
    fn nota_invalida() {
        assert!(matches!(
            analisar_linha("Pedro;dez;8.5"),
            Err(ErroRegistro::NotaInvalida { campo: "nota1", .. })
        ));
    }

    #[test]
    fn campo_ausente() {
        assert!(matches!(
            analisar_linha("Pedro;10.0"),
            Err(ErroRegistro::CampoAusente { campo: "nota2" })
        ));
    }

    #[test]
    fn campos_excedentes() {
        assert!(matches!(
            analisar_linha("Pedro;10.0;8.0;9.0"),
            Err(ErroRegistro::CamposExcedentes)
        ));
    }

    #[test]
    fn arquivo_inexistente() {
        let erro = processar_arquivo("inexistente.txt").unwrap_err();
        assert_eq!(erro.kind(), io::ErrorKind::NotFound);
    }
}
