function main() {
  const canvas = document.getElementById("canvas");
  /** @type {WebGLRenderingContext} */
  const gl = canvas.getContext("webgl");

  const vShaderSource = document.getElementById("vertex-shader").textContent;
  const fShaderSource = document.getElementById("fragment-shader").textContent;

  // Cria e compila shaders
  const vShader = gl.createShader(gl.VERTEX_SHADER);
  gl.shaderSource(vShader, vShaderSource);
  gl.compileShader(vShader);
  if (!gl.getShaderParameter(vShader, gl.COMPILE_STATUS)) {
    console.error("Erro no Vertex Shader:", gl.getShaderInfoLog(vShader));
    return;
  }

  const fShader = gl.createShader(gl.FRAGMENT_SHADER);
  gl.shaderSource(fShader, fShaderSource);
  gl.compileShader(fShader);
  if (!gl.getShaderParameter(fShader, gl.COMPILE_STATUS)) {
    console.error("Erro no Fragment Shader:", gl.getShaderInfoLog(fShader));
    return;
  }

  // Cria e linka programa
  const program = gl.createProgram();
  gl.attachShader(program, vShader);
  gl.attachShader(program, fShader);
  gl.linkProgram(program);

  if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
    console.error("Erro ao linkar programa:", gl.getProgramInfoLog(program));
    return;
  }

  gl.useProgram(program);

  // Localiza o atributo de posição
  const positionLocation = gl.getAttribLocation(program, "a_position");
  if (positionLocation === -1) {
    console.error("Atributo 'a_position' não encontrado no shader!");
    return;
  }

  // Cria e envia dados
  const buffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
  const vertex = new Float32Array([
    -0.5,  0.5,
    -0.5, -0.5,
     0.5,  0.5,
     0.5,  0.5,
    -0.5, -0.5,
     0.5, -0.5
  ]);
  gl.bufferData(gl.ARRAY_BUFFER, vertex, gl.STATIC_DRAW);

  // Configura o atributo
  gl.enableVertexAttribArray(positionLocation);
  gl.vertexAttribPointer(positionLocation, 2, gl.FLOAT, false, 0, 0);

  // Desenha
  gl.clearColor(0, 0, 0, 1);
  gl.clear(gl.COLOR_BUFFER_BIT);
  gl.drawArrays(gl.TRIANGLES, 0, 6);
}
