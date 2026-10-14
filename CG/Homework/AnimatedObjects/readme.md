# WebGL – Animação 2D (Rotação Automática)

Este projeto demonstra uma **animação contínua de transformações 2D em WebGL**, onde os objetos (no caso, a letra F) rotacionam automaticamente no canvas HTML.

O código utiliza **shaders** escritos em GLSL e JavaScript para aplicar as transformações por meio de **matrizes 3x3** e a função `requestAnimationFrame` para criar o loop de animação.

## Como Executar

Para visualizar o projeto?

### Abrir Diretamente no Navegador

1.  Certifique-se de ter os arquivos do projeto (baixados ou clonados).
2.  Localize o arquivo `index.html`.
3.  Abra o arquivo dando um **duplo clique** nele, ou usando o menu contextual:
    > Botão direito → Abrir com → Seu Navegador Preferido (Chrome, Edge, Firefox, etc.)

## Como Usar

Ao abrir o `index.html`, o programa renderizará duas letras **F** no canvas WebGL, que começarão a **rotacionar automaticamente** em um loop contínuo.

A animação é pré-programada no `script.js` e não requer interação do usuário.

## Conceitos Envolvidos

Este projeto aborda os seguintes conceitos fundamentais de computação gráfica e WebGL:

*   **Vertex e Fragment Shaders** (GLSL)
*   **Matrizes de transformação** (translação, rotação, escala)
*   **Projeção 2D** com WebGL
*   **Loop de Animação** com `requestAnimationFrame`
*   Ligação de variáveis da CPU (JavaScript) com a GPU (Shader)
*   Uso de **VAOs** (Vertex Array Objects) e Buffers

## Requisitos

*   Navegador com suporte a **WebGL2** (Chrome, Edge, Firefox, Opera, etc.)
*   Conexão com a internet (para carregar as dependências externas da biblioteca `webgl-utils.js`)

## Créditos

*   Baseado nas lições de [WebGL Fundamentals](https://webglfundamentals.org/ ).
