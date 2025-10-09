#include <iostream>
#include <vector>
#include <queue>
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
    cout << "\n(" << x << "," << k << ") => ";

    CBinNode** pos;
    if (!Find(x, pos)) {
        cout << "no esta en el arbol\n";
        return;
    }

    queue<pair<CBinNode*, int>> col;
    vector<pair<CBinNode*, int>> res;  

    col.push({ m_root , abs(m_root->value - x)});

    while (!col.empty()) {
        CBinNode* actual = col.front().first;
        int distancia = abs(actual->value - x);       
        res.push_back({ actual, distancia });

        if (actual->nodes[0])
            col.push({ actual->nodes[0], abs(actual->nodes[0]->value - x) });
        if (actual->nodes[1])
            col.push({ actual->nodes[1], abs(actual->nodes[1]->value - x) });
        col.pop();
    }

    for (int j = 1; j < res.size(); ++j) {
        auto key = res[j];
        int i = j - 1;
        while (i >= 0 && key.second < res[i].second) {
            res[i + 1] = res[i];
            i--;
        }
        res[i + 1] = key;
    }

    for (int i = 0; i < k && i < res.size(); ++i)
        cout << res[i].first->value << " ";
    
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
