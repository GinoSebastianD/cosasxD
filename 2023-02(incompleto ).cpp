#include <iostream>

template <class T>
struct CForwardNode
{
    CForwardNode(T x)
    {
        value = x;  next = 0;
    }
    T value;
    CForwardNode<T>* next;
};

template <class T>
class CForwardList
{
public:

    CForwardList();
    ~CForwardList();
    bool Find(T x, CForwardNode<T>**& p);
    bool Ins(T x);
    bool Rem(T x);
    void Print();


    CForwardNode<T>* getHead() {
        return head;
    }

private:
    CForwardNode<T>* head; // cuando esta en privado debemos de crear un metodo get.
};

template <class T>
CForwardList<T>::CForwardList()
{
    head = 0;
}

template <class T>
CForwardList<T>::~CForwardList()
{
    //...
}

template <class T>
bool CForwardList<T>::Find(T x, CForwardNode<T>**& p)
{
    for (p = &head; *p && (*p)->value < x; p = &(*p)->next);
    return *p && (*p)->value == x;
}

template <class T>
bool CForwardList<T>::Ins(T x)
{
    CForwardNode<T>** p;
    if (Find(x, p)) return 0;
    CForwardNode<T>* t = new CForwardNode<T>(x);
    t->next = *p;
    *p = t;
    return 1;
}

template <class T>
bool CForwardList<T>::Rem(T x)
{
    CForwardNode<T>** p;
    if (!Find(x, p)) return 0;
    CForwardNode<T>* t = *p;
    *p = t->next;
    delete t;
    return 1;
}

template <class T>
void CForwardList<T>::Print()
{
    for (CForwardNode<T>* t = head; t; t = t->next)
        std::cout << t->value << " ";
    std::cout << "\n";
}

template<class T>
class mult
{
public:
    T val;
    mult():val(3) {};
    int  operator () (T x) {
        if (x%val == 0)
        {
            return x + 10;
        }
        return x;
    }
};




void proc1(CForwardList<int>* l)
{
    mult<int> opera;

    for (CForwardNode<int> * i = l->getHead() ; i ; i = i->next)
    {
       i->value =  opera(i->value);
    }
}

void proc2(CForwardList<int>* l)
{

}

int main()
{
    CForwardList<int> l;
    l.Ins(6);   l.Ins(18);  l.Ins(26);  l.Ins(17);
    l.Ins(3);   l.Ins(4);   l.Ins(27);  l.Ins(30);
    l.Ins(7);   l.Ins(11);  l.Ins(24);  l.Ins(25);
    l.Ins(1);   l.Ins(2);   l.Print();
    proc1(&l);  l.Print();
    proc2(&l);  l.Print();
}
