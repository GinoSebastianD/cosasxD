// SortLeX.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

template <class T>
struct nodo
{
    T valor[3];
    nodo* next;
    nodo()
    {
        next = nullptr;
    }
};


template<class T>
struct SortLeX
{
    nodo<T>* head = nullptr;
    int nro_elementos = 0; //cantidad de elementos en la estructura
    ~SortLeX()
    {
        nodo<T>* tmp;

        while (head)
        {
            tmp = head;
            head = tmp->next;
            //cout << "Destruyendo " << tmp->valor << endl;
            delete tmp;
        }
    };
    void add(T v);
    void print();
    bool find(T v, nodo<T>*& pos, int& recorridos); //pos - posición del nodo, recorridos - items recorridos
    void remove(T v);
};

template<class T>
void SortLeX<T>::print()
{
    int cont = 0;
    int elem_round = 0;

    if (nro_elementos % 3 != 0)
        elem_round = nro_elementos + (3 - nro_elementos % 3);
    else
        elem_round = nro_elementos;
    cout << "Head->";
    for (nodo<T>* p = head; p; p = p->next)
    {
        cout << "[ ";
        for (int i = 0; i < 3 && cont < elem_round; i++, cont++)
        {
            if (cont < nro_elementos)
            {
                cout << p->valor[i];
                if (i < 2)
                    cout << " | ";
                else
                    cout << " ] ";

            }
            else
            {
                if (i < 2)
                    cout << " | ";
                else
                    cout << " ] ";
            }

        }
        cout << " -> ";
    }
    cout << "NULL" << endl;
}
template<class T>
bool SortLeX<T>::find(T v, nodo<T>*& pos, int& recorridos)
{
    nodo<T>* p = head;
    pos = p;

    int cont = 0;
    int i = 0;

    for (; cont < nro_elementos && p && p->valor[i] < v; cont++, i++)
        if (i == 2)
        {
            i = -1;
            p = p->next;
            if (p)
                pos = p;
        };

    recorridos = cont;

    if (p && p->valor[i] == v)
        return true;
    return false;
}

template<class T>
void SortLeX<T>::add(T v)
{
    nodo<T>* pos;
    int recor = 0, i;
    T t;
    if (!find(v, pos, recor))
    {
        if (!pos)
        {
            head = new nodo<int>;
            head->valor[0] = v;
            nro_elementos++;
        }
        else
        {
            i = recor % 3;
            if (i == 0 && recor == nro_elementos)
            {
                pos->next = new nodo<int>;
                pos->next->valor[0] = v;
            }
            else
            {
                for (; recor <= nro_elementos; recor++, i++)
                {
                    if (i > 2)
                    {
                        i = 0;
                        if (pos->next)
                        {
                            pos = pos->next;
                            i = 0;
                        }
                        else
                        {
                            pos->next = new nodo<int>;
                            pos = pos->next;
                        }
                    }
                    t = pos->valor[i];
                    pos->valor[i] = v;
                    v = t;
                }
            }
            nro_elementos++;
        }

    }
}

template<class T>
void SortLeX<T>::remove(T v)
{
    nodo<T> *busca;
    int recorridos = 0 , i;
    int tmp;
    if (find(v,busca, recorridos) )
    {
        i = recorridos % 3;
        nodo<T>* act = busca;
        nodo<T>* sig = busca;
        while (act)
        {
            for (; i<2; i++)
            {
                act->valor[i] = act->valor[i + 1];
            }
            
                sig = sig->next;
                if (sig)
                {
                    act->valor[i] = sig->valor[0];  
                }
                else
                {
                    break;
                }
            act = act->next;
            i = 0;
        }
        nro_elementos--;

        int bloques = (nro_elementos + 2) / 3;
        nodo<T>* ult = head;
        nodo<T>* prev = nullptr;
        for (int i = 1; i <= bloques; i++)
        {
            prev = ult;
            ult = ult->next;
        }
        if (ult && (nro_elementos % 3 == 0)) {
            if (prev)
                prev->next = nullptr;
            else
                head = nullptr;
            delete ult;
        }



    }
}

int main() {
    SortLeX<int> lista;
    int Entrada[10] = { 5, 1, 6, 3, 9 , 2, 4, 8, 10, 7 };
    //int Entrada[10] = { 5, 1, 6, 7, 9 , 2, 4, 8, 10, 7 };

    lista.print();
    for (int i = 0; i < 10; i++)
    {
        lista.add(Entrada[i]);
        cout << "add(" << Entrada[i] << ") \n";
        lista.print();
    }

    cout << endl << "<------------------------------------>" << endl;

  /*  lista.remove(Entrada[0]);
    lista.print();*/
    for (int i = 0; i < 10; i++)
    {
        lista.remove(Entrada[i]);
        cout << "remove(" << Entrada[i] << ") \n";
        lista.print();
    }

    return 0;
}

