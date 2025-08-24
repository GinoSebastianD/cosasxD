#include "iostream"
using namespace std;


class CVector {

public:
    CVector(int z) ;
    ~CVector();
    void expand(bool offset); // expandir el vector
    void push_back(int x); // agregar elemento al final
    void push_front(int x); // agregar elemento al inicio
    void pop_back(); // sacar elemento al final
    void pop_front(); //sacar elemento al inicio
    
    int& operator[](int i); // para acceder a un elemento
    void print();
private:
    int* v;
    int size, nelem;
};
    
CVector::CVector(int z) {
    size = z;
    nelem = 0;
    v = new int[size];
}

CVector::~CVector(){
    delete[] v;
}

void CVector::expand(bool offset) {
    int* nv = new int[size*2];
    for (int i = 0; i < size; i++)
    {
        nv[i+offset] = v[i]; //copio elementos
    }
    delete[] v;
    v = nv; // q "v" apunte al nuevo "nv"
    size = size * 2;
    cout << "\nexpand\n";
}


void CVector::push_back(int x)
{

    if (nelem==size)
    {
        expand(0);
        v[nelem]=x;
        return;
    }
    v[nelem] = x;
    nelem++;
    //v[nelem++]=x; es lo mismo
}
void CVector::push_front(int x)
{
    if (nelem == size)
    {
        expand(1);
         v[0] = x;
         
         return ;
    }
    for (int i = nelem; i > 0; i--)
    {
        v[i] = v[i - 1];
    }
    v[0] = x;
}

void CVector::pop_back()
{
    nelem--;
}
void CVector::pop_front()
{
    nelem--;
    for (int i = 0; i < nelem; i++)
    {
        v[i] = v[i + 1];
    }
    /*for (int i = 0; i < nelem-1; i++)
    {
        v[i] = v[i + 1];
    }
    nelem--;*/

}

int& CVector::operator[](int i){
    
    return    *(v + i);
    //return v[i];
}

void CVector::print() {
    for (int i = 0; i <= nelem; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}



int main() {
    CVector vec(4);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(2);
    vec.print();



}
