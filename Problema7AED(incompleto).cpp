#include <iostream>
#include <cstdlib> 
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
    Node* arbol(T*& ini, T*& fin);
    void inorden(Node* n);

};

template<class T, int N>
bool Cola<T, N>::vacio()  {
 
    if (head == tail && head!= nullptr &&tail != nullptr)
    {
        return true;
    }
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



template<class T, int N>
Node* Cola<T, N>::arbol(T*& ini, T*& fin)  
{  
    srand(time(NULL)); 
    Node* raiz = nullptr;
    for (int i = 0; i < N; i++) {
        Node* nuevo = new Node(rand() % 10);
        this->push(nuevo);
    }
    while (!this->vacio())
    {
        Node* i, * d;
        this->pop(i);
        this->pop(d);

        Node* padre = new Node(i->x + d->x);
        padre->izq = i;
        padre->der = d;

        this->push(padre);
        raiz = padre;
      
    }
    return raiz;    
}

template<class T, int N>
void Cola<T, N>::inorden(Node* n)
{
    if (!n)
    {
        return;
    }
    inorden(n->izq);
    cout << n->x << " ";
    inorden(n->der);
}



int main() {

    
    Cola<Node*, 4> c;
   
    c.inorden(c.arbol(c.head, c.tail));

}
