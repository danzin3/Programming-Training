var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const n = +lines[0]; // or Number(lines[0]);
const s = lines[1];
let total = 0;
let streak = 0;

for (let i = 0; i < n; i++) {
    if (s[i] === 'a') {
        streak++;
        if (streak === 2) total += 2;
        else if (streak > 2) total++;
    } else {
        streak = 0;
    }
}

console.log(total);
