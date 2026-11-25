var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const resultados = [];

for (let i = 0; i < lines.length; i++) {
  const linha = lines[i].trim();

  // Ignora linhas vazias no final do arquivo antes do EOF
  if (linha === '') continue;

  const [hashmat, oponente] = linha.split(/\s+/).map(Number);

  // Abordagem 1: Valor absoluto nativo com Math.abs()
  resultados.push(Math.abs(hashmat - oponente));

  // Abordagem 2 (Alternativa para números maiores que 2^53 usando BigInt):
  // const [h, op] = linha.split(/\s+/).map(BigInt);
  // const diff = op > h ? op - h : h - op;
  // resultados.push(diff.toString());
}

console.log(resultados.join('\n'));
