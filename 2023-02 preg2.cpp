#include <iostream>
using namespace std;


struct CBinNode
{
    CBinNode(int _v)
    {
        value = _v; nodes[0] = nodes[1] = 0;
    }
    int value;
    CBinNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    bool Remove(int x);
    void Print();
    int cabeza();
    void Clear(CBinNode* n);
    CBinNode** max;
    CBinNode** padre;
    int valn;
private:
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrder(CBinNode* n);
    CBinNode* m_root;
    bool m_b;
};

CBinTree::CBinTree()
{
    m_root = 0;
    m_b = 1;
    max = &m_root;
    valn = 0;
    padre = 0;
}

CBinTree::~CBinTree()
{
    Clear(m_root);
}
void CBinTree::Clear(CBinNode* n)
{
    if (!n) return;
    Clear(n->nodes[0]);
    Clear(n->nodes[1]);
    delete n;
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for (p = &m_root;
        *p && (*p)->value != x;
        p = &((*p)->nodes[(*p)->value < x]));
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if (Find(x, p)) return 0;
    *p = new CBinNode(x);
    
    if ( !max || (*max)->value < x)
    {
        padre = max;
        max = p;
    }
    return 1;
}
bool CBinTree::Remove(int x)
{
    CBinNode** p;
    if (!Find(x, p)) return 0;
    if ((*p)->nodes[0] && (*p)->nodes[1])
    {
        CBinNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    CBinNode* t = *p;
    *p = (*p)->nodes[(*p)->nodes[0] == 0];
    if (p == max) {
        max = padre;
    }
    if (padre == max)
    {
        padre = &m_root;
    }

    delete t;
    return 1;
}

CBinNode** CBinTree::Rep(CBinNode** q)
{
    m_b = !m_b;
    q = &((*q)->nodes[!m_b]);
    while ((*q)->nodes[m_b])
        q = &((*q)->nodes[m_b]);
    return q;
}

void CBinTree::InOrder(CBinNode* n)
{
    if (!n) return;
    InOrder(n->nodes[0]);
    cout << n->value << " ";
    InOrder(n->nodes[1]);
}

void CBinTree::Print()
{
    InOrder(m_root);
    cout << endl;
}

int CBinTree::cabeza()
{
    int val = (*max)->value;
    return val;
}





class CMaxHeap
{
public:
    bool push(int x);
    int pop();
    int top();
    void print();
private:
    CBinTree inser;
};


bool CMaxHeap::push(int x) //método que inserte un elemento en la estructura [ O(lg n) ]
{
   
    return inser.Insert(x);
}

int CMaxHeap::pop() // método que remueva el elemento mayor de todo el conjunto [ O(k) ]
{
    int val = inser.cabeza();
    inser.Remove(val);
    return val;
}

int CMaxHeap::top() // método que retorna el elemento mayor de todo el conjunto [ O(k) ]
{
    return inser.cabeza();
}

void CMaxHeap::print()
{
    inser.Print();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{


    CMaxHeap mh;
    
    mh.push(50); mh.push(30); mh.push(60);
    mh.push(80); mh.push(55); mh.push(11);
    mh.push(33); mh.push(5); mh.push(14);
    mh.push(31); mh.push(48);

    cout << mh.top(); mh.pop(); cout << endl;
    cout << mh.top(); mh.pop(); cout << endl;
    cout << mh.top(); mh.pop(); cout << endl;
    cout << mh.top(); mh.pop(); cout << endl;

    cout << endl;
    mh.print();
}
