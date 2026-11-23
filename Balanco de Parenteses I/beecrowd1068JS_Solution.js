var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');
const out = [];
for (let i = 0; i < lines.length; i++) {
    const expr = lines[i].trim();
    if (expr.length === 0) continue;

    let balance = 0;
    for (let j = 0; j < expr.length; j++) {
        const ch = expr[j];
        if (ch === '(') {
            balance++;
        } else if (ch === ')') {
            if (--balance < 0) break;
        }
    }

    out.push(balance === 0 ? 'correct' : 'incorrect');
}
console.log(out.join('\n'));
