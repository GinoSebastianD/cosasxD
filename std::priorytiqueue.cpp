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
	std::priority_queue<int> pq;
	for (int n: stones)
	{
		pq.push(n);
	}

	while (!pq.empty()) {
		cout << pq.top()<< " ";
		pq.pop();
	}


	return 0;
}



int main() {
	piedra pi;
	vector<int> vec = {2,7,4,1,8,1};
	pi.ultima(vec);
}

