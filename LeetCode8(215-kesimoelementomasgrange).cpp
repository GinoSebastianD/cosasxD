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


        //std::priority_queue<int, std::vector<int>, std::greater<int>> minH(nums.begin(), nums.begin()+k);
    //for (int i = k; i < minH.size(); i++)
    //{
    //    if (nums[i] > minH.top())
    //    {
    //        minH.pop();
    //        minH.push(nums[i]);
    //    }
    //}
    //return minH.top();
}


int main() {
    piedra pi;
    vector<int> vec = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    cout << pi.kele(vec, 4);

}


