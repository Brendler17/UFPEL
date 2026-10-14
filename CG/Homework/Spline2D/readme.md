# Spline Catmull-Rom Interativa (Canvas 2D)

Este projeto demonstra o desenho de uma **Spline Catmull-Rom** utilizando o **Canvas 2D** do HTML. A curva é gerada de forma interativa, onde o usuário define os pontos de controle através de cliques na tela.

A Spline Catmull-Rom é uma curva de interpolação que passa por todos os pontos de controle definidos, sendo amplamente utilizada em computação gráfica para suavização de caminhos e modelagem.

## Estrutura do Projeto

O projeto é composto por um único arquivo, contendo todo o HTML, CSS (inline) e JavaScript:


## Como Executar

Para visualizar e interagir com o projeto:

### Abrir Diretamente no Navegador

1.  Certifique-se de ter o arquivo `index.html` salvo.
2.  Abra o arquivo dando um **duplo clique** nele, ou usando o menu contextual:
    > Botão direito → Abrir com → Seu Navegador Preferido (Chrome, Edge, Firefox, etc.)

## Como Usar

O programa renderiza um canvas branco em um fundo preto.

1.  **Definir Pontos de Controle:** Clique no canvas para adicionar os pontos de controle da spline. Cada clique desenhará um pequeno círculo preto no local.
2.  **Desenho da Spline:** O código está configurado para aceitar um máximo de **10 pontos** (`maxDots = 10`).
3.  **Animação:** Após o décimo clique, o desenho da Spline Catmull-Rom será iniciado automaticamente, traçando a curva em vermelho entre os pontos definidos.

## Conceitos Envolvidos

Este projeto aborda os seguintes conceitos:

*   **Spline Catmull-Rom:** Implementação da fórmula paramétrica para gerar a curva.
*   **Canvas 2D:** Utilização da API de desenho 2D do HTML para renderizar pontos e linhas.
*   **Interatividade:** Captura de eventos de clique (`click`) para definir os pontos de controle.
*   **Animação:** Uso de `requestAnimationFrame` para desenhar a curva progressivamente.
*   **Geometria Computacional:** Cálculo de coordenadas da curva baseadas nos pontos de controle.
