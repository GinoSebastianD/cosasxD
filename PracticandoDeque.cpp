#include "iostream"
using namespace std;

class Deque
{
public:

	Deque(int siz_map, int siz_vec);
	void push_back(int x);
	void push_front(int x);
	int pop_back();
	int pop_front();
	int& operator [] (int x);
	void print(Deque *p);
	~Deque();
	int nelem;


private:
	int size_map;
	int size_vec;
	int** ini;
	int** fin;
	int* ini_array;
	int* fin_array;
	int** map;




};

Deque::Deque(int siz_map, int siz_vec)
{
	size_map = siz_map;
	size_vec = siz_vec;
	map = new int* [size_map];
	ini = map + (size_map / 2);
	fin = ini;
	ini_array = nullptr;
	fin_array = nullptr;
	nelem = 0;
}

void Deque::push_back(int x)
{
	if (ini_array == nullptr && fin_array == nullptr)
	{
		*fin = new int[size_vec];
		ini_array = *fin + (size_vec/2);
		fin_array = ini_array;
		*fin_array = x;
		nelem++;
	
	}
	else if(fin_array == *fin+size_vec-1)
	{
		if (fin == map+size_map-1)
		{
			cout << "expansion";
		}
		fin++;
		*fin = new int[size_vec];
		fin_array = *fin;
		*fin_array = x;
		nelem++;
	}
	else
	{
		fin_array++;
		*fin_array = x;
		nelem++;
	}
}

void Deque::push_front(int x)
{
	if (ini_array == nullptr && fin_array == nullptr)
	{
		*ini = new int[size_vec];
		ini_array = *ini + (size_vec / 2);
		fin_array = ini_array;
		*ini_array = x;
		nelem++;

	}
	else if (ini_array == *ini)
	{
		if (ini == map)
		{
			cout << "expansion";
		}
		ini--;
		*ini = new int[size_vec];
		ini_array = *ini+size_vec-1;
		*ini_array = x;
		nelem++;
	}
	else
	{
		ini_array--;	
		*ini_array = x;
		nelem++;
	}
}
int Deque::pop_back()
{
	int elemento = 0;

	if (ini_array == fin_array)
	{
		elemento = *fin_array;
		fin_array = nullptr;
		ini_array = nullptr;
		delete* fin;
		nelem--;
	}
	else if (fin_array == *fin)
	{
		elemento = *fin_array;
		delete *fin;
		fin--;
		fin_array = *fin + size_vec-1;
		nelem--;
	}
	else
	{
		elemento = *fin_array;
		fin_array--;
		nelem--;
	}
	
}
int Deque::pop_front()
{
}
int& Deque::operator[](int x)
{
	int offset = ini_array - *ini;
	int total = offset + x;
	return *(*(ini + (total / size_vec)) + (total% size_vec));
}
void print(Deque* p)
{
	for (int i = 0; i < p->nelem; i++)
		std::cout << (*p)[i] << " ";
	std::cout << "\n";
}
Deque::~Deque()
{



}

int main() {
	Deque v(5, 5);
	v.push_back(3); v.push_back(8); v.push_back(1);
	v.push_back(4); v.push_back(9); v.push_back(6);
	v.push_back(7);
	print(&v);
	return 0;
}
