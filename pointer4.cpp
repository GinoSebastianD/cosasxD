/*Ejercicio 4: Rellenar un arreglo con n numeros, posteriormente utilizando punteros
determinar el menor elemento del vector.*/
#include <iostream>
using namespace std;

int main() {
	
	int n;
	cout << "Ingresa tam del array: ";
	cin >> n;
	
	int* arr = new int[n];
	
	int x;
	for (int *p = arr; p < arr + n; p++)
	{
		cout << "ingrese numeros: ";
		cin >> x;
		*p = x;
	}

	int menor=1000000000;
	for (int *p = arr; p < arr+n; p++)
	{
		if (*p < menor)
		{
			menor = *p;
		}
		
	}
	cout << menor;
	delete[] arr;
	return 0;
}
