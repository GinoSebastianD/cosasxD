#include <iostream>
#include <queue>
#include <string_view>
#include <vector>
#include <functional>

int main() {

	std::vector<int> data = { 1,8,5,6,3,4,0,9,7,2 };
			
	for (int element: data)
	{	
		std::cout << element << " ";
	}
	std::priority_queue<int> max_pri_queue;

	for (int n : data)
	{
		max_pri_queue.push(n);
	}

	std::cout << std::endl;
	for (; !max_pri_queue.empty(); max_pri_queue.pop())
	{
		std::cout << max_pri_queue.top() << " ";
	}
	std::cout << std::endl;
	std::cout << "Cola de prioridad minima: ";
	
	std::priority_queue <int ,std::vector<int>,std::greater<int>>
		min_priority_queue1(data.begin(), data.end());
	for (; !min_priority_queue1.empty(); min_priority_queue1.pop())
	{
		std::cout << min_priority_queue1.top() << " ";
	}
}
