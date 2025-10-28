#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T , class comp>
class Heap
{
public:
	std::vector<int> max;
	comp comparator;
	void push(T x);
	void print();

	auto begin() { return max.begin(); }
	auto end() { return max.end(); }


private:

};

template<class T>
struct asc
{
	bool operator() (T x , T y) {
		return x < y;
	}
};

template<class T>
struct des
{
	bool operator() ( T x, T y) {
		return x > y;
	}

};

template<class T , class comp>
void Heap<T,comp>::push(T x)
{
	max.push_back(x);
	int count = max.size() - 1;
	while (count > 0)
	{
		int p = ((count) - 1) / 2;
		if ( comparator(max[p], max[count]) ) 
		{
			swap(max[p], max[count]);
			count = p;
		}
		else
		{
			break;
		}
	}
}

template<class T, class comp>
void Heap<T,comp>::print()
{
}


int main() {
	Heap<int ,des<int>> max;
	max.push(1);
	max.push(2);
	max.push(3);
	max.push(4);
	max.push(5);
	max.push(6);
	max.push(7);
	max.push(8);
	max.push(9);
	max.push(10);
	for (int ele: max)
	{
		cout << ele << " ";
	}

}
