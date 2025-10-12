
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    void sobrinos_de(int x);

    void del(CBinNode* raiz);
private:
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrder(CBinNode* n);
    void inor(CBinNode* n, int x);

    CBinNode* m_root;
    bool m_b;
};

CBinTree::CBinTree()
{
    m_root = 0;
    m_b = 0;
}

void CBinTree::del(CBinNode* raiz)
{
    if (!raiz)
    {
        return;
    }
    del(raiz->nodes[0]);
    del(raiz->nodes[1]);
    delete raiz;
}
CBinTree::~CBinTree()
{
    del(m_root);
    
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
    return 0;
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

void CBinTree::inor(CBinNode* n, int x)
{
    if (!n) return;
    InOrder(n->nodes[0]);
    if (n->value != x)
    {
        cout << n->value << " ";
    }

    InOrder(n->nodes[1]);
}



void CBinTree::Print()
{
    InOrder(m_root);
    cout << endl;
}



void CBinTree::sobrinos_de(int x)
{
    CBinNode** pos;
    if (!Find(x,pos))
    {
        return;
    }
    CBinNode* sig = *pos;
    *pos = (*pos)->nodes[0];
    inor(*pos , (*pos)->value);
    *pos = sig;

    *pos = (*pos)->nodes[1];
    inor(*pos, (*pos)->value);
    *pos = sig;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    t.Insert(50); t.Insert(30); t.Insert(60);
    t.Insert(80); t.Insert(55); t.Insert(11);
    t.Insert(35); t.Insert(5);  t.Insert(14);
    t.Insert(32); t.Insert(48);
    t.Insert(51); t.Insert(56);
    t.Insert(70); t.Insert(85);
    t.Insert(1); t.Insert(6);
    t.Insert(12); t.Insert(16);
    t.Insert(31); t.Insert(33);
    t.Insert(42); t.Insert(49);

    t.Print();
    cout << endl;

    t.sobrinos_de(11);
    cout << endl;
    t.sobrinos_de(50);
   


}
