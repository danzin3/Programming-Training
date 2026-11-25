#include <vector>

using namespace std;

class ProductOfNumbers
{
public:
    vector<int> vet = {1};
    ProductOfNumbers()
    {
        //
    }

    void add(int num)
    {
        if (num == 0)
        {
            vet.clear();
            vet.push_back(1);
        }
        else
        {
            vet.push_back(vet.back() * num);
        }
    }

    int getProduct(int k)
    {
        if (k >= vet.size())
            return 0;
        return vet.back() / vet[vet.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
