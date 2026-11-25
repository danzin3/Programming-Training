var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');
const gcd = (a, b) => (b ? gcd(b, a % b) : a);
const N = parseInt(lines[0].trim(), 10);
const resultados = [];

for (let i = 1; i <= N; i++) {
  const [F1, F2] = lines[i].trim().split(' ').map(Number);
  resultados.push(gcd(F1, F2));
}

console.log(resultados.join('\n'));
