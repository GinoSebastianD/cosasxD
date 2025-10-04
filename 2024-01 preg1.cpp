#include <iostream>

using namespace std;

class node
{
public:
    int data = 0;
    node* next = nullptr;

    // Se le puede agregar constructor

    node(int x) {
        data = x;
        next = nullptr;
    }
    node(int x, node* a) {
        data = x;
        next = a;
    }
};

class CircularLinkedList
{
    node* head = NULL;
public:
    void add(int value)
    {
        node* nuevo = new node(value);
        if (!head)
        {
            head = nuevo;
            head->next = head;
            return;
        }
        else if (nuevo->data < head->data)
        {
            node* ant = head;
            while (ant->next!=head)
            {
                ant = ant->next;
            }
            nuevo->next = head;
            ant->next = nuevo;
            head = nuevo;
        }
        else
        {
            node* ant = head;
            while (ant->next != head && ant->next->data < value)
            {
                ant = ant->next;
            }
            nuevo->next = ant->next;
            ant->next = nuevo;
        }

    }

    void del(int value)
    {
        node* act = head;
        while (act->next != head && act->next->data != value)
        {
            act = act->next;
        }
        if (head->next == head)
        {
            head = nullptr;
            delete act;
        }
        else
        {
            node* tmp = act->next;
            act->next = tmp->next;
            if (head->data == value) {
                head = tmp->next;
            }
            delete tmp;
    }

    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        if (ptr->next == nullptr) return;
        while (head && cont < 1)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout << " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

   /* for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }*/
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
