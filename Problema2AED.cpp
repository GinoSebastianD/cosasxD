#include <iostream>
#include <thread>

using namespace std;


int arr[10][10] = { 0 };

void cuentaporfilas(int ini, int fin) {
    for (int (*y)[10] = arr + ini; y < arr + fin; y++) {
        for (int* i = *y; i < *(y + 1); i++) {
            int fila = y - arr;
            int col = i - *y;

            if (*i == -1) continue;
            int contador = 0;

            if (fila > 0) {
                if (*(*(arr + fila - 1) + col) == -1)
                    contador++;
                if (col < 10 - 1 && *(*(arr + fila - 1) + col + 1) == -1)
                    contador++;
                if (col > 0 && *(*(arr + fila - 1) + col - 1) == -1)
                    contador++;
            }
            if (fila < 10 - 1) {
                if (*(*(arr + fila + 1) + col) == -1)
                    contador++;
                if (col < 10 - 1 && *(*(arr + fila + 1) + col + 1) == -1)
                    contador++;
                if (col > 0 && *(*(arr + fila + 1) + col - 1) == -1)
                    contador++;
            }
            if (col < 10 - 1 && *(i + 1) == -1)
                contador++;
            if (col > 0 && *(i - 1) == -1)
                contador++;

            *i = contador;
        }
    }
}

int main() {


    int x;
    cout << "Ingresa la cantidad de numeros aleatorios (maximo 10): ";
    cin >> x;

    int contador = 1;
    while (contador <= x) {
        int (*q)[10] = arr + rand() % 10;
        int* z = *q + rand() % 10;
        *z = -1; // mina
        contador++;
    }

    thread t1(cuentaporfilas, 0, 3);
    thread t2(cuentaporfilas, 3, 6);
    thread t3(cuentaporfilas, 6, 8);    
    thread t4(cuentaporfilas, 8, 10);   
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    for (int (*p)[10] = arr; p < arr + 10; p++) {
        for (int* q = *p; q < *(p + 1); q++) {
            cout << *q << "  ";
        }
        cout << endl;
    }

    return 0;
}
