var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const costs = new Int32Array(1000);
const out = [];
let idx = 0;

while (idx < lines.length) {
    const header = lines[idx++].trim();
    if (header === '') continue;

    const n = +header;
    if (n === 0) break;

    let sum = 0;
    for (let i = 0; i < n; i++) {
        const raw = lines[idx++].trim();
        const dot = raw.indexOf('.');
        // Parsing inteiro direto: evita truncamento por imprecisão binária IEEE 754
        const val = (+raw.slice(0, dot)) * 100 + (+raw.slice(dot + 1));
        costs[i] = val;
        sum += val;
    }

    const low = Math.floor(sum / n);
    const high = sum % n === 0 ? low : low + 1;

    let posDiff = 0;
    let negDiff = 0;
    for (let i = 0; i < n; i++) {
        if (costs[i] > high) posDiff += costs[i] - high;
        else if (costs[i] < low) negDiff += low - costs[i];
    }

    const ans = posDiff > negDiff ? posDiff : negDiff;
    const dollars = Math.floor(ans / 100);
    const remCents = String(ans % 100).padStart(2, '0');
    out.push(`$${dollars}.${remCents}`);
}

console.log(out.join('\n'));
