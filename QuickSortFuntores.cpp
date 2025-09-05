
class asc
{
public:
	bool operator () (int z, int i) {
		return z > i;
	}
};
class des
{
public:
	bool operator () (int z, int i) {
		return z < i;
	}
};




#include "iostream"
using namespace std;

template<class T>
int* particion(int* ini, int* fin, T comp) {
	int pivot = *fin;
	int* i = ini - 1;
	for (int* z = ini; z <= fin; z++)
	{
		if (comp(*z,pivot))
		{
			i++;
			swap(*z, *i);
		}

	}
	swap(*(i + 1), *fin);
	return i + 1;

}

template<class T>
void quicksort(int* ini, int* fin,T comp) {
	if (ini < fin) {
		int* p = particion(ini, fin,comp);
		quicksort(p + 1, fin,comp);
		quicksort(ini, p - 1,comp);


	}

}



int main() {
	int arr[] = { 4,2,3,6,7,8,9 };
	int tam = sizeof(arr) / sizeof(arr[0]);
	int* ini = arr;
	int* fin = arr + tam - 1;
	asc comp;
	quicksort(ini,fin,comp);
	for (int* i = arr; i < arr + tam; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << "------------------------------------"<< endl;

	des des;
	quicksort(ini, fin, des);
	for (int *i = arr; i < arr+tam; i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	cout << "------------------------------------";

}
