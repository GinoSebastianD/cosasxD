#include <iostream>
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


#include <iostream>
using namespace std;

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
    Node* arbol(T*& ini, T* fin);

private:

};

template<class T, int N>
bool Cola<T, N>::vacio()  {
    return head == nullptr;
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
        head = tail = nullptr;
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
        cout << p->x << " ";  // imprimimos el valor del nodo
        if (p == tail) break;
        if (p == arr + (N - 1))
            p = arr;
        else
            p++;
    }
    cout << endl;
}


template<class T, int N>
Node* Cola<T, N>::arbol(T*& ini, T* fin)
{
    
    for (int i = 0; i < 16; i++)
    {
        ini = push(Node(rand() % 10));
    }

    
    Node* pa = new Node(5);
    
    return ini;
}



int main() {
    Cola<Node, 16> ar;
    ar.arbol(ar.head,ar.tail);
    ar.print();
}
