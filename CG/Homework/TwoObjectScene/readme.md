# WebGL – Transformações 2D (Translação, Rotação e Escala)

Este projeto demonstra **transformações 2D em WebGL**, permitindo mover, rotacionar e escalar objetos (no caso, a letra F) diretamente em um canvas HTML.

O código utiliza **shaders** escritos em GLSL e JavaScript para aplicar as transformações por meio de **matrizes 3x3**.


## Como Executar

Para visualizar o projeto?

### Abrir Diretamente no Navegador

1.  Certifique-se de ter os arquivos do projeto (baixados ou clonados).
2.  Localize o arquivo `index.html`.
3.  Abra o arquivo dando um **duplo clique** nele, ou usando o menu contextual:
    > Botão direito → Abrir com → Seu Navegador Preferido (Chrome, Edge, Firefox, etc.)

## Como Usar

O programa renderiza uma letra **F** no canvas WebGL.

Você pode controlar as transformações (posição, rotação e escala) por meio dos **sliders** exibidos na interface.

É possível ajustar os parâmetros em tempo real e observar o resultado imediato na tela.

## Conceitos Envolvidos

Este projeto aborda os seguintes conceitos fundamentais de computação gráfica e WebGL:

*   **Vertex e Fragment Shaders** (GLSL)
*   **Matrizes de transformação** (translação, rotação, escala)
*   **Projeção 2D** com WebGL
*   Ligação de variáveis da CPU (JavaScript) com a GPU (Shader)
*   Uso de **VAOs** (Vertex Array Objects) e Buffers

## Requisitos

*   Navegador com suporte a **WebGL2** (Chrome, Edge, Firefox, Opera, etc.)
*   Conexão com a internet (para carregar as dependências externas da biblioteca `webgl-utils.js`)

## Créditos

*   Baseado nas lições de [WebGL Fundamentals](https://webglfundamentals.org/ ).