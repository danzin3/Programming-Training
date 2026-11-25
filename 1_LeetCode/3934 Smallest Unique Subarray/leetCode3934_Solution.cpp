#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution
{
public:
    int smallestUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();

        // 1. Configuração do Double Rolling Hash
        // Escolhemos bases primas maiores que o valor máximo de nums[i] (10^5)
        const uint64_t B1 = 1315423911ULL;
        const uint64_t M1 = 1000000007ULL; // 10^9 + 7

        const uint64_t B2 = 133311ULL;
        const uint64_t M2 = 1000000009ULL; // 10^9 + 9

        // Vetores de potências (B^i % M) e hashes de prefixo
        vector<uint64_t> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<uint64_t> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            pow1[i + 1] = (pow1[i] * B1) % M1;
            pow2[i + 1] = (pow2[i] * B2) % M2;

            // Desloca o hash anterior para a esquerda (* B) e soma o novo número
            pref1[i + 1] = (pref1[i] * B1 + nums[i]) % M1;
            pref2[i + 1] = (pref2[i] * B2 + nums[i]) % M2;
        }

        // 2. Função lambda para obter o hash único de 64 bits do subarray nums[l ... r] em O(1)
        auto get_hash = [&](int l, int r) -> uint64_t
        {
            int len = r - l + 1;

            // Subtrai o prefixo anterior ajustado pela potência do tamanho da janela
            // (+ M garante que o resultado nunca seja negativo antes do módulo)
            uint64_t h1 = (pref1[r + 1] + M1 - (pref1[l] * pow1[len]) % M1) % M1;
            uint64_t h2 = (pref2[r + 1] + M2 - (pref2[l] * pow2[len]) % M2) % M2;

            // Junta os dois hashes de 32 bits em um único inteiro de 64 bits
            return (h1 << 32) | h2;
        };

        // 3. Função de validação: existe algum subarray de tamanho L que é único?
        auto check = [&](int L) -> bool
        {
            int num_subarrays = n - L + 1;
            vector<uint64_t> hashes;
            hashes.reserve(num_subarrays); // Evita realocações de memória

            // Janela deslizante de tamanho L
            for (int i = 0; i <= n - L; ++i)
            {
                hashes.push_back(get_hash(i, i + L - 1));
            }

            // Ordena todos os hashes para colocar os idênticos lado a lado
            sort(hashes.begin(), hashes.end());

            // Verifica se algum hash não possui vizinhos iguais
            for (int k = 0; k < num_subarrays; ++k)
            {
                bool diff_left = (k == 0 || hashes[k] != hashes[k - 1]);
                bool diff_right = (k == num_subarrays - 1 || hashes[k] != hashes[k + 1]);

                if (diff_left && diff_right)
                {
                    return true; // Encontramos um subarray único de tamanho L!
                }
            }
            return false;
        };

        // 4. Busca Binária na resposta (menor tamanho L possível)
        int left = 1, right = n;
        int ans = n; // No pior caso, o array inteiro (tamanho n) é sempre único

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (check(mid))
            {
                ans = mid;       // mid funciona! Guardamos a resposta...
                right = mid - 1; // ...e tentamos achar um tamanho ainda menor.
            }
            else
            {
                left = mid + 1; // mid não tem nenhum único, precisamos aumentar o tamanho.
            }
        }

        return ans;
    }
};
