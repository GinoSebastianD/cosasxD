#include "iostream"
using namespace std;


class CVector {


private:
    int* v;
    int size, nelem;
    int* y;

public:
    CVector(int z) { //declaro el constructor dentro del class
        size = z;
        nelem = 0;
        v = new int[size];
        y = v;
    }
    void push_back(int x); //agregar elemento al final
    void push_front(int x); //agregar elemento al inicio
    void pop_back(); // eliminar elemento al final
    void pop_front(); //eliminar elemento al inicio
    void expand(bool offset);
    void print();

};
//CVector::CVector(int z) { // constructor fuera del class
//    size = z;
//    nelem = 0;
//    v = new int[size];
//}


void CVector::expand(bool offset) {
    int* nv = new int[size * 2];
    int cont = 0;
    for (int* np = nv, i = 0; i < size && np < nv + (size * 2); np++, i++)
    {
        *(np + offset) = *(v + i);
        cont++;
    }

    delete[] v;
    size = size * 2;
    cout << "\nexpand()\n";
    v = nv;
    y = nv +cont ;
}
void CVector::push_back(int x) { //agregar al final
    if (size == nelem)
    {
        expand(0);
        *(v + nelem) = x;
        y++;
        return;
    }
    *(v + nelem) = x;
    nelem++;
    
    y++;
}
void CVector::push_front(int x) { //agregar al inicio
    if (size == nelem)
    {
        expand(1);
        *v = x;
        y++;
        return;
    }
    for (int *q = v+nelem; q > v ; q--)
    {
        *q = *(q - 1);
    }
    *v = x;
    y++;
}
void CVector::pop_back() { //eliminar elemento al final
    y--;
    
}


void CVector::pop_front() { //eliminar elemento al inicio
    nelem--;
    
    for (int *z= v; z < v + nelem; z++)
    {
        *z = *(z + 1);
        
    }
    y--;
} 


void CVector::print() {
    
    for (int* p = v; p < y; p++) 
    {
        cout << *p << " ";
    }
}




int main() {
    CVector vec(4);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    vec.pop_front();
    vec.print();


    return 0;
}






