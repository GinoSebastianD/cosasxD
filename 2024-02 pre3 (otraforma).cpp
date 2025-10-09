#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<algorithm>
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
    void Print();
    void kneighbors(int x, int k);
private:
    bool Find(int x, CBinNode**& p);
    void InOrder(CBinNode* n);
    CBinNode* m_root;
};

CBinTree::CBinTree()
{
    m_root = 0;
}

CBinTree::~CBinTree()
{
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for (p = &m_root; *p && (*p)->value != x; p = &((*p)->nodes[(*p)->value < x]));
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if (Find(x, p)) return 0;
    *p = new CBinNode(x);
    return 0;
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

void CBinTree::kneighbors(int x, int k)
{
    std::cout << "\n(" << x << "," << k << ") => ";
    std::stack< pair<CBinNode*, int> > pil;
    std::vector< pair<CBinNode*, int> > vec;

    pil.push( {m_root , 0});
    vec.push_back( {m_root , abs(m_root->value - x) });

    while (!pil.empty())
    {
        auto &top = pil.top();
        switch ( top.second  )
        {
        case 0:
            top.second = 1;
            if (top.first->nodes[0])
            {
                pil.push( {top.first->nodes[0], 0});
                vec.push_back({ top.first->nodes[0] , abs(top.first->nodes[0]->value - x)});
            }
            break;
                
        case 1:
            top.second = 2;
            break;

        case 2:
            top.second = 3;
            if (top.first->nodes[1])
            {
                pil.push({ top.first->nodes[1], 0 });
                vec.push_back({ top.first->nodes[1] , abs(top.first->nodes[1]->value - x) });
            }
            break;
        case 3:
            pil.pop();
            break;

        default:
            break;
        }

    }
    sort( vec.begin() , vec.end() ,[](auto &a, auto &b)   {
        return  a.second < b.second;
    } );

    for (int i = 0; i < k ; ++i)
        cout << vec[i].first->value << " ";

    cout << endl;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    CBinTree t;
    t.Insert(55); t.Insert(41); t.Insert(77);
    t.Insert(33); t.Insert(47); t.Insert(61);
    t.Insert(88); t.Insert(20); t.Insert(36);
    t.Insert(44); t.Insert(51); t.Insert(57);
    t.Insert(65); t.Insert(80); t.Insert(99);
    t.Print();

    t.kneighbors(33, 4);
    t.kneighbors(88, 3);
    t.kneighbors(76, 2);
    t.kneighbors(47, 5);
    t.kneighbors(61, 4);
    t.kneighbors(50, 3);
    t.kneighbors(81, 5);
    t.kneighbors(20, 7);
}
