var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');
const out = [];

for (let i = 0; i + 1 < lines.length; i += 2) {
  const s1 = lines[i], s2 = lines[i + 1];
  if (!s1 && !s2) break;

  let ans = 0;
  for (let l = 0; l < s1.length; l++)
    for (let r = l + ans + 1; r <= s1.length; r++)
      if (s2.includes(s1.slice(l, r))) ans = r - l;

  out.push(ans);
}

console.log(out.join('\n'));
