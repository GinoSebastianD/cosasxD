#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class piedra
{
public:
    int kele(vector<int>& nums, int k);
private:

};

int piedra::kele(vector<int>& nums, int k)
{
    int mayor = 0;
    int cont = 0;
    std::priority_queue<int> col(nums.begin(),nums.end());
    
    while (cont != k)
    {
        mayor = col.top();
        col.pop();
        cont++;
    }
    return mayor;
}


int main() {
    piedra pi;
    vector<int> vec = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    cout << pi.kele(vec, 4);

}


