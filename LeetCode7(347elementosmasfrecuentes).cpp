#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class piedra
{
public:
    vector<int> topk(vector<int>&nums ,int k);
private:

};

vector<int> piedra::topk(vector<int>& nums, int k)
{
    std::unordered_set<int> uni;
    std::vector<std::pair<int, int>> col;
    std::vector<int>vec;
    int num = 0;
    for (int n : nums)
    {
        if (uni.insert(n).second) 
        {
            col.push_back({ n, 0 });
        }
    }
    for ( auto& act : col  )
    {
        int rep = count(nums.begin(),nums.end() , act.first);
        act.second = rep;
    }
    std::sort(col.begin(), col.end(), [](auto& a, auto& b) {
        return a.second > b.second;
   });

    while (num != k)
    {
        vec.push_back(col.front().first);
        col.erase(col.begin());
        num++;
    }
    return vec;
}


int main() {
    piedra pi;
    vector<int> vec = { 3,2,2,2,1,1,1 };
    std::vector<int> otro = pi.topk(vec,2 );
    for (auto ele: otro)
    {
        std::cout << ele << " ";
    }

}


