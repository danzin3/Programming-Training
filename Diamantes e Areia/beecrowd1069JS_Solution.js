var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const n = parseInt(lines[0], 10);

for (let i = 1; i <= n; i++) {
    const mina = lines[i] || '';
    const pilha = [];
    let diamantes = 0;

    for (let j = 0; j < mina.length; j++) {
        const caractere = mina[j];

        if (caractere === '<') {
            pilha.push('<');
        } else if (caractere === '>' && pilha.length > 0) {
            pilha.pop();
            diamantes++;
        }
    }

    console.log(diamantes);
}
