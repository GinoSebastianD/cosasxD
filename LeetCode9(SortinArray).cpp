class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::priority_queue<int,vector<int>,greater<int>> minH;
        for(int it: nums){
            minH.push(it);
        }
        std::vector<int> vector;
        while(!minH.empty()){
            vector.push_back(minH.top());
            minH.pop();
        }

        return vector;
    }
};
