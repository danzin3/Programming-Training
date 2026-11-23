// String - Snippet string search

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    long n;
    int j = 0, count = 0;
    string line;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);
    for (size_t i = 0; i < n; i++)
    {
        if (line[i] == 'a' && line[i + 1] == 'a')
        {
            j = i;
            while (line[j] == 'a')
            {
                count++;
                j++;
                if (j == n)
                {
                    break;
                }
            }
            i = j;
            j = 0;
        }
    }
    cout << count << endl;
    return 0;
}

// Quest o --> https://judge.beecrowd.com/pt/problems/view/3424
