#include "iostream"
using namespace std;




int* particion(int* ini, int* fin) {
	int pivote = *fin;
	int* ant = ini - 1;
	for (int* z = ini; z <= fin ; z++)
	{
		if (*z < pivote)
		{
			ant++;
			swap(*z, *ant);
		}
	}
	swap(*(ant + 1), *fin);
	return ant + 1;
}




void quick_sort(int * ini , int * fin) {
	if (ini<fin)
	{
		int* p = particion(ini, fin);
		quick_sort(p + 1, fin);
		quick_sort(ini, p - 1);

	}
}




int main() {

	int arr[] = { 9,8,7,5,2,6,1,3,4,10 };
	int tam = sizeof(arr) / sizeof(arr[0]);
	int* ini = arr;
	int* fin = arr + tam-1;
	quick_sort(ini, fin);

	for (int *i = arr; i < arr+tam; i++)
	{
		cout << *i << " ";
	}
}
