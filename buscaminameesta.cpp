	#include "iostream"
	using namespace std;
	int main() {
		int arr[10][10] = {0};

		srand(time(0));
		int contador = 1;
		int x;
		cout << "Ingresa la cantidad de numeros aleatorios (maximo 10): ";
		cin >> x;
		while (contador<=x){
			int (*q)[10] = arr + rand() % 10;
			int* z = *q + rand() % 10;
			*z = rand() % 1 - 1;
			contador++;
		}
		//fila
		
	/*	int num=5565;
		int* puntero = &num;
		cout << &puntero ;
		int* q = puntero;*/
		
		for (int (*y)[10] = arr; y < arr+10; y++)
		{
			
			//columna
			for (int *i = *y; i < *(y+1); i++)
			{
				int fila = y - arr;  
				int col = i - *y;
				
					if (fila > 0) //cuando existe un arriba 
					{
						int* cicloarriba = *(arr + fila - 1) + col;
							if (*cicloarriba==-1)
							{
								*i = 1;
							}
						if (col <= 8) {
							int* cicloarribaderecha = (*(arr + fila - 1) + col) + 1;
							if (*cicloarribaderecha == -1) {
								*i = 1;
							}
						}
						if (col > 0) {
							int* cicloarribaizquierda = (*(arr + fila - 1) + col) - 1;
							if (*cicloarribaizquierda == -1) {
								*i = 1;
							}
						}
					}
					if (fila < 9) { // cuando existe un abajo
						int* cicloabajo = *(arr + fila + 1) + col;
						if (*cicloabajo == -1) {
							*i = 1;
							}
						if (col <= 8) {
							int* cicloabajoderecha = (*(arr + fila + 1) + col) +1 ;
							if (*cicloabajoderecha == -1) {
								*i = 1;
							}
						}
						if (col > 0) {
							int* cicloabajoizquierda = (*(arr + fila + 1) + col) -1 ;
							if (*cicloabajoizquierda == -1) {
								*i = 1;
							}
						}
					}
					// derecha e izquierda
					if (col <=8 )
					{
						int* derecha = i + 1;
						if (*derecha == -1)
						{
							*i = 1;
						}
					}

					if (col > 0) {
						int* izquierda = i - 1;
						if (*izquierda == -1)
						{
							*i = 1;
						}
					}






					//casos especiales: primera fila y la ultima fila , al igual que la primera columna y la ultima columna
					//caso mas especial son las esquinas , no hay casos especiales lptmre
					/*if (fila == 1) { 

					}*/
			}
		}
		for (int (*p)[10] = arr; p < arr+10; p++){
			for (int *q = *p; q < *(p+1); q++){
				cout << *q << " ";
			}
			cout << endl;
		}


	}
