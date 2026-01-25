#include <iostream>
#include <vector>
#include <queue>



class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::priority_queue<int, std::vector<int> , std::greater<int>> ord(nums.begin(), nums.end());
        std::priority_queue<int> ord2(nums.begin(), nums.end());

        std::vector<int> sol;
        for (int i = 0 ; i < nums.size()/2; i++)
        {
            auto top = ord.top();
            auto top2 = ord2.top();
            int s = top + top2;
            sol.push_back(s);
            ord.pop();
			ord2.pop();

        }
        auto ele = std::max_element(sol.begin(),sol.end());
        return *ele;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {4, 1, 5, 1, 2, 5, 1, 5, 5, 4};
    int result = sol.minPairSum(nums);
    std::cout << "Minimum pair sum: " << result << std::endl;
    return 0;
}
