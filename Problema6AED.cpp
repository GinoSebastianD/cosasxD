
#include "iostream"
using namespace std;


struct Node
{

    //atributos de cada nodo
    Node* next;
    int v;

    Node(int x) { //constructor 
        v = x;
        next = 0;
    }

};


class FL
{
public:
    Node* head;

    FL() { //constructor
        head = 0;
        nelem = 0;
    }
    void push_front(int x);
    void push_back(int x);
    void pop_back();
    void pop_front();

    void merge(Node* A, Node* B);

    void print();
    ~FL(); //destructor

private:
    int nelem;
};

FL::~FL()
{
    Node* p = head;
    while (p) {
        p = p->next;
        delete head;
        head = p;
    }

}

void FL::push_back(int x) { // agregar al final
    Node* n = new Node(x);
    Node** q;
    for (q = &head; *q != 0; q = &((*q)->next));
    *q = n;
}
void FL::push_front(int x) { //agregar al inicio
    Node* n = new Node(x);
    n->next = head;
    n->v = x;
    head = n;
    nelem++;
}
void FL::pop_back() { //eliminar al final

    //con puntero doble
    Node** y;
    for (y = &head; *y != 0 && (*y)->next != 0; y = &((*y)->next));
    delete* y;
    *y = 0;
    //Creando un tmp auxiliar usando un puntero simple
    /*  Node* tmp = 0;
      Node* y;
      for ( y = head; y->next != 0; y = y->next)
              tmp = y;
      tmp->next = 0;

      delete y;*/
}
void FL::pop_front() { //eliminar al inicio

    Node* tmp = 0;
    tmp = head;
    head = tmp->next;
    delete tmp;
}

void FL::merge(Node* A, Node* B)
{
    Node* tmpA = A;
    Node* tmpB = B;
    while (tmpA)
    {
        if (tmpA->v<tmpB->v)
        {
            x
        }

    }


}


void FL::print()
{
    for (Node* i = head; i; i = i->next)
    {
        cout << i->v << "->";
    }
    cout << "NULL";


}
int main() {
    FL fl;
    fl.push_front(9);
    fl.push_front(7);
    fl.push_front(5);
    fl.push_front(3);
    fl.push_front(1);

    fl.print();
    cout << endl;

    FL fl2;
    fl2.push_front(10);
    fl2.push_front(8);
    fl2.push_front(6);
    fl2.push_front(4);
    fl2.push_front(2);
    fl2.print();
  /*  FL fl3;
    fl3.merge(fl.head, fl2.head);*/
    
    return 0;
}
