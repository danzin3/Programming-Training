var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const N = parseInt(lines[0].trim(), 10);
const resultados = [];

for (let i = 1; i <= N; i++) {
  // Remove apenas o '\r' final para preservar espaços da mensagem (ex: "I ENIL...")
  const linha = lines[i].replace(/\r$/, '');
  const len = linha.length;
  const metade = len / 2; // O enunciado garante que o tamanho é sempre par

  const decifrada = [];

  // 1ª metade: do meio para a margem esquerda
  for (let j = metade - 1; j >= 0; j--) {
    decifrada.push(linha[j]);
  }

  // 2ª metade: da margem direita para o meio
  for (let j = len - 1; j >= metade; j--) {
    decifrada.push(linha[j]);
  }

  resultados.push(decifrada.join(''));
}

console.log(resultados.join('\n'));
