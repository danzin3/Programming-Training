var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const freq = new Int32Array(128);
const casesOut = [];

for (let i = 0; i < lines.length; i++) {
    const line = lines[i];
    if (line.length === 0 || line === '\r') continue;

    freq.fill(0);
    const chars = [];

    for (let j = 0; j < line.length; j++) {
        const code = line.charCodeAt(j);
        // Ignora '\r' (13); o enunciado garante caracteres no intervalo [32, 127]
        if (code >= 32 && code <= 127) {
            if (freq[code] === 0) chars.push(code);
            freq[code]++;
        }
    }

    if (chars.length === 0) continue;

    // Ordem crescente de frequência; empate: valor ASCII decrescente
    chars.sort((a, b) => freq[a] - freq[b] || b - a);

    const block = new Array(chars.length);
    for (let j = 0; j < chars.length; j++) {
        const codeSecond = chars[j];
        block[j] = `${codeSecond} ${freq[codeSecond]}`;
    }
    casesOut.push(block.join('\n'));
}

console.log(casesOut.join('\n\n'));
