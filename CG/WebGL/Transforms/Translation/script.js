const vertexShaderSource = `#version 300 es
    in vec2 a_position;
    uniform vec2 u_resolution;
    uniform vec2 u_translation;

    void main() {
      vec2 position = a_position + u_translation;
      vec2 zeroToOne = position / u_resolution;
      vec2 zeroToTwo = zeroToOne * 2.0;
      vec2 clipSpace = zeroToTwo - 1.0;
      gl_Position = vec4(clipSpace * vec2(1, -1), 0, 1);
    }
  `;

const fragmentShaderSource = `#version 300 es
    precision highp float;
    uniform vec4 u_color;
    out vec4 outColor;

    void main() {
      outColor = u_color;
    }
  `;

function main() {
  const canvas = document.querySelector("#canvas");
  /** @type {WebGL2RenderingContext} */
  const gl = canvas.getContext("webgl2");
  if (!gl) {
    console.log("WebGL not supported!")
  }

  const program = webglUtils.createProgramFromSources(gl, [vertexShaderSource, fragmentShaderSource]);

  const positionAttributeLocation = gl.getAttribLocation(program, "a_position");
  const resolutionUniformLocation = gl.getUniformLocation(program, "u_resolution");
  const colorLocation = gl.getUniformLocation(program, "u_color");
  const translationLocation = gl.getUniformLocation(program, "u_translation");

  const positionBuffer = gl.createBuffer();
  const vao = gl.createVertexArray();
  gl.bindVertexArray(vao);
  gl.enableVertexAttribArray(positionAttributeLocation);
  gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);

  setGeometry(gl);

  const size = 2;
  const type = gl.FLOAT;
  const normalize = false;
  const stride = 0;
  const offset = 0;

  gl.vertexAttribPointer(positionAttributeLocation, size, type, normalize, stride, offset);

  // VARIÁVEIS DE TRANSLAÇÃO //
  const translation = [0, 0];
  const color = [Math.random(), Math.random(), Math.random(), 1];

  drawScene();

  webglLessonsUI.setupSlider("#x", { slide: updatePosition(0), max: gl.canvas.width });
  webglLessonsUI.setupSlider("#y", { slide: updatePosition(1), max: gl.canvas.height });

  function updatePosition(index) {
    return function (event, ui) {
      translation[index] = ui.value;
      console.log("New Draw!")
      drawScene();
    }
  }

  function drawScene() {
    webglUtils.resizeCanvasToDisplaySize(gl.canvas);

    gl.viewport(0, 0, gl.canvas.width, gl.canvas.height);

    gl.clearColor(0, 0, 0, 0);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    gl.useProgram(program);

    gl.bindVertexArray(vao);

    gl.uniform2f(resolutionUniformLocation, gl.canvas.width, gl.canvas.height);

    gl.uniform4fv(colorLocation, color);

    gl.uniform2fv(translationLocation, translation);

    var primitiveType = gl.TRIANGLES;
    var offset = 0;
    var count = 18;
    gl.drawArrays(primitiveType, offset, count);
  }
}

function setGeometry(gl) {
  gl.bufferData(
    gl.ARRAY_BUFFER,
    new Float32Array([
      0, 0,
      30, 0,
      0, 150,
      0, 150,
      30, 0,
      30, 150,
      30, 0,
      100, 0,
      30, 30,
      30, 30,
      100, 0,
      100, 30,
      30, 60,
      67, 60,
      30, 90,
      30, 90,
      67, 60,
      67, 90,
    ]),
    gl.STATIC_DRAW);
}

main();