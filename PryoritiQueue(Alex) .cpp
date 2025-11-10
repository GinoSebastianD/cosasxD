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
	void pop();
	void print();




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
void Heap<T, comp>::pop()
{
	int tam = max.size();
	max[0] = max[tam-1];
	max.pop_back();
	tam--;
	int ini = 0;
	while (true)
	{
		int izq = 2 * ini + 1;
		int der = 2 * ini + 2;
		int cam = ini;
		if (izq < tam && max[izq] > max[cam])
		{
			cam = izq;
		}
		if (der< tam && max[der] > max[cam])
		{
			cam = der;
		}
		if (cam != ini)
		{
			swap(max[ini],max[cam]);
			ini = cam;
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
	for (int elem: max)
	{
		cout << elem << " ";
	}
}


int main() {
	Heap<int ,asc<int>> max;
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
	max.print();
	std::cout << endl;
	max.pop();
	max.print();

}


#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class heap
//{
//public:
//	std::vector<int> max;
//	void push(int x);
//	void pop();
//	int top();
//	void print();
//private:
//
//};
//
//
//
//void heap::push(int x)
//{
//	max.push_back(x);
//	int count = max.size() - 1;
//	while (count > 0)
//	{
//		int p = (count - 1) / 2;
//		if (max[p] < max[count])
//		{
//			std::swap(max[p], max[count]);
//			count = p;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void heap::pop()
//{
//	int tam = max.size();
//	max[0] = max[tam - 1];
//	tam--;
//	max.pop_back();
//	int ini = 0;
//	while (true)
//	{
//		int izq = 2 * ini + 1;
//		int der = 2 * ini + 2;
//		int cam = ini;
//		if (izq < tam && max[izq] > max[cam])
//		{
//			cam = izq;
//		}
//		if (der < tam && max[der] > max[cam])
//		{
//			cam = der;
//		}
//		if (ini != cam)
//		{
//			std::swap(max[ini], max[cam]);
//			ini = cam;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//int heap::top()
//{
//	return max.front();
//}
//
//void heap::print()
//{
//	for (auto i : max)
//	{
//		std::cout << i << " ";
//	}
//}
//
//
//
//
//
//int main() {
//	heap max;
//	max.push(90);
//	max.push(88);
//	max.push(77);
//	max.push(73);
//	max.push(70);
//	max.push(66);
//	max.push(60);
//	max.push(49);
//	max.push(51);
//	max.push(50);
//	max.push(36);
//	max.push(43);
//	max.push(30);
//	max.push(40);
//	max.push(23);
//	max.push(35);
//	max.push(21);
//	max.print();
//	std::cout << std::endl;
//	std::cout <<max.top() << std::endl;
//	max.pop();
//	max.print();
//	std::cout << std::endl;
//	std::cout << max.top() << std::endl;
//}

























