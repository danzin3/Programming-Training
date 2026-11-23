var input = require("fs").readFileSync("/dev/stdin", "utf8");
var lines = input.split("\n");

// Remove possível '\r' (quebra de linha do Windows presente em muitos testes do beecrowd)
const N = parseInt(lines[0].trim(), 10);
const resultados = [];

for (let l = 1; l <= N; l++) {
  // Evita usar .trim() na linha inteira para não apagar espaços válidos no início/fim da mensagem
  const texto = lines[l].replace(/\r$/, "");
  const len = texto.length;
  const metade = Math.floor(len / 2);

  // Array pré-alocado para montar a resposta já invertida
  const saida = new Array(len);

  for (let i = 0; i < len; i++) {
    let code = texto.charCodeAt(i);

    // 1ª Passada: Apenas letras (A-Z: 65-90 | a-z: 97-122) deslocam +3 na ASCII
    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122)) {
      code += 3;
    }

    // 2ª Passada: A posição final após inverter será (len - 1 - i)
    const posInvertida = len - 1 - i;

    // 3ª Passada: Se na posição invertida ele estiver da metade (truncada) em diante, desloca -1
    if (posInvertida >= metade) {
      code -= 1;
    }

    saida[posInvertida] = String.fromCharCode(code);
  }

  resultados.push(saida.join(""));
}

// Um único console.log no final é muito mais rápido que chamar dentro do loop
console.log(resultados.join("\n"));
