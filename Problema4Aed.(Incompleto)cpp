//usar recursividad  y solo verificar arriba abajo , izquierda y derecha
//doble for para encontrar A automaticamente en td la matriz
//
#include <iostream>
using namespace std;

bool encontrar(char matriz[10][10], char* x) {
    int fil = (x - &matriz[0][0]) / 10;
    int col = (x - &matriz[0][0]) % 10;
    if (*x == 'X' || *x == '.')
        return false;
    if (*x == 'B')
        return true;

    char tmp = *x;
    if (*x != 'A')
        *x = '.'; 
    if (fil > 0 && encontrar(matriz, x - 10)) { //recursividad abajo
        
        return true;
    }
    if (fil < 9 && encontrar(matriz, x + 10)) { //recursividad arriba
        return true;
    }
    if (col > 0 && encontrar(matriz, x - 1)) { //recursividad a la izquierda
        return true;
    }
    if (col < 9 && encontrar(matriz, x + 1)) { //recursividad a la derecha
        return true;
    }

    if (tmp == ' ')
        *x = ' ';
    
    return false;
}

int main() {
    char caminos[10][10] = {
        {' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
        {' ','X',' ',' ',' ',' ','X','X',' ','X'},
        {' ','X',' ','X','X',' ','X','X','X','X'},
        {' ','X',' ','X',' ',' ','X',' ',' ',' '},
        {' ',' ',' ','X',' ',' ',' ',' ','X','X'},
        {' ','X','X','X','X','X',' ',' ','X',' '},
        {' ',' ',' ',' ','X',' ',' ',' ',' ',' '},
        {' ','X','X',' ','X',' ',' ','X','X','X'},
        {'X','X',' ',' ','X',' ',' ','X',' ',' '},
        {'A',' ',' ','X','X',' ',' ',' ',' ','B'},
    };

    char* x = nullptr;

    for (char (*p)[10] = caminos; p < caminos + 10; p++) {
        for (char* q = *p; q < *p + 10; q++) {
            if (*q == 'A') {
                x = q;
                break;
            }
        }
      /*  if (x) {
            break;
        }*/
    }

    encontrar(caminos, x);
   

    for (char (*p)[10] = caminos; p < caminos + 10; p++) {
        for (char* q = *p; q < *p + 10; q++) {
            cout << *q;
        }
        cout << endl;
    }
}

