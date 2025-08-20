/*Ejercicio 1: Comprobar si un número es par o impar, y señalar la posicion de memoria 
donde se está guardando el número. Con punteros.*/

#include <iostream>
using namespace std;
int main() {
    
    int num = 6;
    int * p = &num;
    if(num%2==0){
        cout <<"Par" << endl;
        cout << p;
    }
    else{
        cout <<"Impar"<< endl;
        cout <<p;
    }
    return 0;
}
