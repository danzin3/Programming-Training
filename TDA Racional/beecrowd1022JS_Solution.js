var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

function gcd(a, b) {
    while (b !== 0) {
        const t = b;
        b = a % b;
        a = t;
    }
    return a;
}

const n = Number(lines[0]);
const out = new Array(n);

for (let i = 1; i <= n; i++) {
    // Desestruturação ignora as barras '/' nos índices 1 e 5
    const [n1, , d1, op, n2, , d2] = lines[i].trim().split(/\s+/);
    const a = +n1, b = +d1, c = +n2, d = +d2;

    let num, den;
    if (op === '+') {
        num = a * d + c * b;
        den = b * d;
    } else if (op === '-') {
        num = a * d - c * b;
        den = b * d;
    } else if (op === '*') {
        num = a * c;
        den = b * d;
    } else {
        num = a * d;
        den = c * b;
    }

    const g = gcd(Math.abs(num), Math.abs(den));
    out[i - 1] = `${num}/${den} = ${num / g}/${den / g}`;
}

console.log(out.join('\n'));
