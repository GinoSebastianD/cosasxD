#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

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
    void inorden(CBinNode* root, std::vector<std::pair<CBinNode*, int>  >& vec, int x);
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

void CBinTree::inorden(CBinNode* root, std::vector< std::pair<CBinNode*,int> >& vec , int x)
{
    if (!root)
    {
        return;
    }
    inorden(root->nodes[0], vec , x );
    vec.push_back({root , abs(root->value - x) });
    inorden(root->nodes[1], vec ,x  );
}

void CBinTree::Print()
{
    InOrder(m_root);
    cout << endl;
}

void CBinTree::kneighbors(int x, int k)
{
    std::cout << "\n(" << x << "," << k << ") => ";
    std::vector<std::pair<CBinNode*, int>> vec ;
    inorden(m_root, vec , x);

    sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
     for (int i = 0; i < k; i++)
     {
         cout << vec[i].first->value << " "; 
     }
}

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
   
}
