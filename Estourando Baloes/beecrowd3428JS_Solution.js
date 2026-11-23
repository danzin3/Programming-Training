var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const n = Number(lines[0]);
const heights = lines[1].split(' ');
const arrows = new Int32Array(1000001);
let total = 0;

for (let i = 0; i < n; i++) {
    const h = +heights[i];
    if (arrows[h] > 0) {
        arrows[h]--;
    } else {
        total++;
    }
    arrows[h - 1]++;
}

console.log(total);
