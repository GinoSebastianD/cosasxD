#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;


struct Node
{
    Node* izq;
    Node* der;
    int x;
    Node(int v = 0) {
        izq = nullptr;
        der = nullptr;
        x = v;
    }
};
template<class T, int N> 
class Cola {
public:
    T arr[N];
    T* head;
    T* tail;
    Cola() {
        head = nullptr;
        tail = nullptr;

    }

    bool pop(T& x);
    bool push(T x);
    bool lleno() ;
    bool vacio() ;
    void print() ;

};

template<class T, int N>
bool Cola<T, N>::vacio()  {
 
  
    return (head == nullptr && tail == nullptr);

}

template<class T, int N>
bool Cola<T, N>::lleno()  {
    if (!head) return false;
    if (tail + 1 == head) return true;
    if (tail == arr + (N - 1) && head == arr) return true;
    return false;
}

template<class T, int N>
bool Cola<T, N>::push(T x) {
    if (lleno()) {
        cout << "se lleno" << endl;
        return false;
    }

    if (!head) { 
        head = tail = arr;
    }
    else if (tail == arr + (N - 1)) { 
        tail = arr;
    }
    else {
        tail++;
    }

    *tail = x;
    return true;
}

template<class T, int N>
bool Cola<T, N>::pop(T& x) {
    if (vacio()) {
        cout << "ta vacio" << endl;
        return false;
    }
    x = *head;  

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }

  
    else if (head == arr + (N - 1)) {
        head = arr;
    }
    else {
        head++;
    }

    return true;
}

template<class T, int N>
void Cola<T, N>::print() {
    if (vacio()) {
        cout << "Cola vacía" << endl;
        return;
    }

    T* p = head;
    cout << "Cola: ";
    while (true) {
        cout << (*p)->x << " ";
        if (p == tail) break;
        if (p == arr + (N - 1))
            p = arr;
        else
            p++;
    }
    cout << endl;
}

void inorden(Node* n)
{
    if (!n)
    {
        return;
    }
    inorden(n->izq);
    cout << n->x << " ";
    inorden(n->der);
}



template<class T, int N>
Node* arbol(int* ini, int* fin)  
{  
    Cola<Node*, N> col;
    Node* raiz = nullptr;
    for (int* p = ini; p <= fin; p++)
    {
        Node* nuevo = new Node(*p);
        col.push(nuevo);
    }

    while (!col.vacio())
    {
        Node* i, * d;
        col.pop(i);
        col.pop(d);

        Node* padre = new Node(i->x + d->x);
        padre->izq = i;
        padre->der = d;

        if (col.head != nullptr)
        {
            col.push(padre);
        }
         raiz = padre;

    }


    return raiz;
}





int main() {
    srand(time(NULL));
    const int N = 4;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 10;
    }
    int* ini = arr;
    int* fin = arr + N - 1;
    
    inorden(arbol<Node*,N>(ini,fin));
}
