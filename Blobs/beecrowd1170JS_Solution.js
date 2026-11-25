var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const N = parseInt(lines[0].trim(), 10);
const resultados = [];

for (let i = 1; i <= N; i++) {
  let comida = parseFloat(lines[i].trim());
  let dias = 0;

  while (comida > 1.0) {
    comida /= 2;
    dias++;
  }

  resultados.push(`${dias} dias`);
}

console.log(resultados.join('\n'));
