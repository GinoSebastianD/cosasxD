/*Ejercicio 6: Hacer una función para almacenar N números en un arreglo dinámico, 
posteriormente en otra función buscar un número en particular. 
NOTA: Puedes utilizar cualquier método de búsqueda(Secuencial o Binaria)*/ 
#include <iostream>
using namespace std;
void fun1(int x, int* & ptr) {
	ptr = new int[x];
	for (int *p = ptr; p < ptr+x; p++)
	{
		cout << "ingresar numeros: ";
		cin >> *p;
	}
	for (int *z= ptr; z < ptr+x; z++)
	{
		cout << *z << " ";
	}
}

int busqueda(int* ptr, int n, int y) {
	for (int i = 0; i < n; i++) {
		if (ptr[i] == y) {
			return i;
		}
	}
	return -1;
}


int main() {
	int n;
	cout << "ingrese el tam: ";
	cin >> n;
	int* ptr = nullptr;

	fun1(n, ptr);

	int y;
	cout << "numeor a buscar: ";
	cin >> y;
	busqueda(ptr, n, y);

	if (busqueda(ptr, n, y) != -1)
	{
		cout << "encontrado ";
	}
	else
	{
		cout << "no encontrado";
	}

	delete[] ptr;
	return 0;

}
