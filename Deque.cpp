#include "iostream"
using namespace std;


struct Deque
{
	int tam = 5;
	int** mapa = new int* [tam];
	int** ini = mapa+(tam/2);
	int** fin = ini;
	int* ini_array = nullptr;
	int* fin_array = nullptr;
	int numarrays = 0;
	void push_front(int x);
	void push_back(int x);
	int pop_back();
	int pop_front();
	void print();
};



void Deque::push_front(int x)
{
	if (ini_array == nullptr)
	{
		*ini = new int[5];
		ini_array = *ini+2;
		fin_array = ini_array;
		fin_array++;
	}
	if (ini_array == *ini)
	{
		*ini_array = x;
		ini--;
		*ini = new int[5];
		ini_array = *ini+(tam-1);
		
	}
	else
	{
		*ini_array = x;
		ini_array--;
	}

}

void Deque::push_back(int x)
{
	if (fin_array == nullptr && fin == ini)
	{
		*fin = new int[5];
		fin_array = *fin + 2;
		ini_array = fin_array;
		ini_array--;
	}
	if (fin_array == *fin+(tam-1))
	{
		*fin_array = x;
		fin++;
		*fin = new int[5];
		fin_array = *fin;
		
	}
	else
	{
		*fin_array = x;
		fin_array++;
	}
}

int Deque::pop_front() {
	int eliminado = 0;
	if (ini_array == nullptr && fin_array == nullptr)
	{
		return -1;
	}
	if (ini_array == fin_array)
	{
		eliminado = *ini_array;
		ini_array = nullptr;
		fin_array = nullptr;
		delete[] * ini;
		
	}
	if (*ini+(tam-1) == ini_array)
	{
		eliminado = *ini_array;
		delete [] *  ini;
		ini++;
		ini_array = *ini;
			
	}
	else
	{
		ini_array++;
		eliminado = *ini_array;

	}
	return eliminado;
}

int Deque::pop_back() {
	int eliminado = 0;

	if (ini_array == nullptr && fin_array == nullptr)
	{
		return -1;
	}
	if (ini_array == fin_array)
	{
		eliminado = *fin_array;
		ini_array = nullptr;
		fin_array = nullptr;
		delete[] * fin;
		cout << "fin del array";
	}
	if (*fin == fin_array)
	{
		eliminado = *fin_array;
		delete[] * fin;
		fin++;
		fin_array = *fin;

	}
	else
	{
		fin_array--;
		eliminado = *fin_array;

	}
	return eliminado;
}

void Deque::print()
{
	
}


int main() {
	Deque dq;
	dq.push_front(5);
	dq.push_front(6);
	dq.push_front(7);
	dq.push_front(8);
	dq.push_front(9);
	dq.push_front(10);
	dq.push_front(11);
	cout << dq.pop_front()<< " ";
	cout << dq.pop_front()<< " ";
	cout << dq.pop_front()<< " ";
	cout << dq.pop_front()<< " ";
	cout << dq.pop_back() << " ";
	cout << dq.pop_back() << " ";
	cout << dq.pop_back() << " ";
	cout << dq.pop_back() << " ";


}
