#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class piedra
{
public:

	int ultima(vector<int>& stones);
private:

};
int piedra::ultima(vector<int>& stones)
{
	//mejor manera de agregar elementos a la cola de prioridad.
	// std::priority_queue<int> pq(stones.begin(),stones.end());
    std::priority_queue<int> pq;
    for (int n : stones)
    {
        pq.push(n);
    }
    int max = 0;
    int max2 = 0;
    while (pq.size() > 1) {
         max = pq.top(); pq.pop();
         max2 = pq.top(); pq.pop();
        if (max != max2) {
            int nuevo = max - max2;
            pq.push(nuevo);
        }
        if (pq.empty())
        {
            return 0;
        }
    }
    return pq.top();


}



int main() {
	piedra pi;
	vector<int> vec = { 2,7,4,1,8,1 };
	cout<< pi.ultima(vec);

}

