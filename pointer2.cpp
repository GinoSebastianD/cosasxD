/*Ejercicio 3: Rellenar un array de 10 números, posteriormente utilizando punteros
indicar cuales son números pares y su posicion en memoria. */


int main() {

    int arr[10];
	int val;
	for (int *p = arr; p < arr+10; p++)
	{
		cout << "Ingresar valores para el array: ";
		cin >> val;
		if (val%2==0)
		{
			cout << "Par "<< endl;
			cout << p << endl;
		}

	}
	
}
