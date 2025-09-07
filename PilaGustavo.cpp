#include <iostream>

using namespace std;

template <class T>
struct Stack
{
	T arr[10] = {};
	T* top = NULL;

	bool lleno()
	{
		return top == arr + 9;
	}
	bool vacio()
	{
		return !top;
	}
	bool push(T a)
	{
		if (lleno())
		{
			cout << "pila llena" << endl;
			return 0;
		}
		else
		{
			if (!top)
			{
				top = arr;
			}
			else
			{
				top++;
			}
			*top = a;
			return 1;
		}
	}
	bool pop(T& a)
	{
		if (vacio())
		{
			cout << "pila vacia" << endl;
			return 0;
		}
		else
		{
			a = *top;
			top--;
			if (top < arr)
			{
				top = NULL;
			}
			return 1;
		}
	}
	void print()
	{
		for (T* i = arr; i < arr + 10; i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
};

int main()
{
	Stack<int> pila;
	int a;
	cout << "agregando elementos con push()" << endl;
	pila.push(16);	
	pila.push(18);	
	pila.push(11);	
	pila.push(14);	
	pila.push(17);	
}
