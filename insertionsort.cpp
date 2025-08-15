// buscar posicio y retornar true o false si existe el key, junto con un insertion sort

#include <iostream>
using namespace std;

bool busquedaBinaria(int* inicio, int* fin, int key) {
    int* principio = inicio;
    while (inicio <= fin) {
        int* mid = inicio + (fin - inicio) / 2;
        if (*mid == key) {  
            cout << "True" << endl; 
            cout <<(mid-principio )<< endl; 
            return true;
        }
        else if (*mid < key) {
            inicio = mid + 1;
        }
        else {
            fin = mid - 1;
		}
    }
}

void insertionsort(int *inicio , int tam) {
    for (int *j = inicio +1 ; j < inicio +tam; j++)
    {
        int key = *j;
        int* i = j - 1;
        while (i< inicio+tam && key < *i)
        {
            swap(*i, *(i + 1));
            i--;
        }
    }
    for (int  *i = inicio; i < inicio + tam; i++)
    {
        cout << *i << " ";
    }

}

int main() {
    int arr[] = { 6,3,5,4,7,9,10 };
    int tam = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    busquedaBinaria(arr, arr + tam - 1, key);
    insertionsort(arr, tam);


    return 0;
}




