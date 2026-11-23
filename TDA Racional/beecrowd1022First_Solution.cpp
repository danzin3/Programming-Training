// Math - Simplifying Fractions

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>

using namespace std;

static int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

static void simplificarFracao(int& numerador, int& denominador) {
    int divisorComum = mdc(numerador, denominador);

    if (divisorComum == 0)
        return;

    if (divisorComum < 0) {
        divisorComum *= -1;
    }

    numerador /= divisorComum;
    denominador /= divisorComum;
}

int main()
{
    long n;
    int nFinal = 0, dFinal = 0;
    string linha, operacoes;
    vector<int> vet;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (size_t i = 0; i < n; i++)
    {
        getline(cin, linha);
        for (size_t j = 0; j < linha.length(); ++j) {
            if (linha[j] == '/' || linha[j] == '+' || linha[j] == '-' || linha[j] == '*') {
                operacoes += linha[j];
                linha.erase(j, 2);
                --j;
            }
        }
        istringstream iss(linha);
        int numero;
        while (iss >> numero) {
            vet.push_back(numero);
        }
        // Para mostrar o vector:
        /*cout << "vet = ";
        for (auto& v : vet) {
            cout << v << " ";
        }
        cout << endl;*/
        switch (operacoes[1])
        {
        case '+':
            nFinal = (vet[0] * vet[3]) + (vet[2] * vet[1]);
            dFinal = (vet[1] * vet[3]);
            break;
        case '-':
            nFinal = (vet[0] * vet[3]) - (vet[2] * vet[1]);
            dFinal = (vet[1] * vet[3]);
            break;
        case '*':
            nFinal = (vet[0] * vet[2]);
            dFinal = (vet[1] * vet[3]);
            break;
        case '/':
            nFinal = (vet[0] * vet[3]);
            dFinal = (vet[2] * vet[1]);
            break;
        default:
            break;
        }
        operacoes.clear();
        vet.clear();
        cout << nFinal << '/' << dFinal << " = ";
        simplificarFracao(nFinal, dFinal);
        cout << nFinal << '/' << dFinal << endl;
    }
    return 0;
}

//Quest o --> https://judge.beecrowd.com/pt/problems/view/1022

/**
* Recebi um erro de "Runtime error" e esse cara de um forun me ajudou a solucionar:
* 
* "Um provavel runtime error talvez esteja vinculado sobre como voce faz a leitura dos numeradores,
  denominadores e caractere auxiliar [ + - * / ].
  Esteja atento. lembre-se de que numeros de 2 ou 5 digitos farao parte da entrada."
  Exemplo:
  1234 / 12345 + 4321 / 12344
  Ent o depois de testar com esses valores a aplicacao realmente quebrava

  * Depois de procurar por alguns dias... Encontrei as bibliotecas:
  * #include <vector>
  * #include <sstream>
  * E entao ficou mais facil de resolver.
*/

// Sites de Referencia:
// https://learn.microsoft.com/pt-br/cpp/standard-library/list-class?view=msvc-170
// https://learn.microsoft.com/pt-br/cpp/standard-library/vector?view=msvc-170
// https://learn.microsoft.com/pt-br/cpp/standard-library/sstream?view=msvc-170
