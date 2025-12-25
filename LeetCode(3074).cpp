#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        std::priority_queue<int> capa(capacity.begin(), capacity.end());
        std::priority_queue<int> aple(apple.begin(), apple.end());
        int n_veces = 0;
        int acumulado = 0;
        int tope = capa.top();
        while (!aple.empty())
        {
            auto topp = aple.top();
           
            
           
            if (acumulado+ topp <=  tope  )
            {
                acumulado = acumulado + topp;
                aple.pop();
                continue;
            }
            else
            {
                capa.pop();
                tope = tope + capa.top();
                n_veces++;

            }
            
        }
        n_veces++;



        /*while (!aple.empty())
        {
            auto top = aple.top();
            aple.pop();

            cout << top << " ";
        }*/


        return n_veces;
    }
};


int main() {
    
    Solution s;
    std::vector<int> apple = {1,3,2};
    std::vector<int> capacity = {4,3,1,5,2};
    
    cout<< s.minimumBoxes(apple, capacity);
    return 0;
}
