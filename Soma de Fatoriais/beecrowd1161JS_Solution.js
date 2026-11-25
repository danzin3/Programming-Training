var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

// Pré-cálculo usando BigInt (sufixo 'n') para evitar perda de precisão acima de 16 dígitos
const fat = new Array(21);
fat[0] = 1n;
for (let i = 1n; i <= 20n; i++) {
  fat[Number(i)] = fat[Number(i - 1n)] * i;
}

const resultados = [];

for (let i = 0; i < lines.length; i++) {
  const linha = lines[i].trim();
  
  // Ignora linhas vazias causadas pelo '\n' final antes do EOF
  if (linha === '') continue;

  const [m, n] = linha.split(/\s+/).map(Number);
  const soma = fat[m] + fat[n];
  
  // .toString() remove o 'n' do final do BigInt na hora de imprimir
  resultados.push(soma.toString());
}

console.log(resultados.join('\n'));
