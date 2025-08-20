/*Ejercicio 5: Pedir al usuario N números, almacenarlos en un arreglo dinámico
posteriormente ordenar los números en orden ascendente y mostrarlos en pantalla.
NOTA: Utilizar cualquier método de ordenamiento. */
#include <iostream>
using namespace std;
int main() {
	
	int n;
	cout << "ingrese n numeros: ";
	cin >> n;

	int* arr = new int[n];

	for (int *p = arr; p < arr+n; p++)
	{
		cout << "Ingrese los numeros: ";
		cin >> *p;
	}

	for (int  *q= arr;  q< arr+n; q++)
	{
		cout << *q << " ";
	}

	for (int *z = arr+1; z < arr + n; z++)
	{
		int key = *z;
		int* i = z - 1;
		while (i < arr + n && key < *i)
		{
			swap(*i,*(i+1));
			i--;
		}
	}
	cout << endl;
	for (int* q = arr; q < arr + n; q++)
	{
		
		cout << *q << " ";
	}




	delete[] arr;

	return 0;
}
