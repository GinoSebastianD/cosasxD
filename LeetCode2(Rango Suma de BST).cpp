#include <iostream>

struct CNode
{
    CNode(int _v)
    {
        v = _v; nodes[0] = nodes[1] = 0;
    }
    int v;
    CNode* nodes[2];
};

class CBinTree
{
public:
    CNode* root;

    CBinTree();
    ~CBinTree();
    bool find(int x, CNode**& p);
    bool ins(int x);
    bool rem(int x);
    CNode** rep(CNode** p);
    void inorder(CNode* n);
    void print();
    int height1(CNode* n);
    void h1(CNode* n, int h, int& maxh);
    int height2(CNode* n);

    CNode* buscar(CNode* root, int val);
    int range(CNode* root, int low, int high);

    CNode* cortar(CNode* root, int low, int high);
    int range2(CNode* root, int low, int high);


private:
    bool brep;
};

CBinTree::CBinTree()
{
    root = 0;   brep = 0;
}

CBinTree::~CBinTree()
{
}

bool CBinTree::find(int x, CNode**& p)
{
    for (p = &root; *p && (*p)->v != x;
        p = &((*p)->nodes[(*p)->v < x]));
    return *p != 0;
}
bool CBinTree::ins(int x)
{
    CNode** p;
    if (find(x, p)) return 0;
    *p = new CNode(x);
    return 1;
}

bool CBinTree::rem(int x)
{
    CNode** p;
    if (!find(x, p)) return 0;

    if ((*p)->nodes[0] && (*p)->nodes[1])//caso 2
    {
        CNode** q = rep(p);
        (*p)->v = (*q)->v;
        p = q;
    }
    CNode* t = *p;
    *p = (*p)->nodes[(*p)->nodes[1] != 0];
    delete t;
    return 1;
}

CNode** CBinTree::rep(CNode** p)
{
    CNode** q = p;
    for (q = &((*q)->nodes[!brep]); (*q)->nodes[brep];
        q = &((*q)->nodes[brep]));
    brep = !brep;
    return q;
}

/*
 CNode** CBinTree::rep(CNode** p)
 {
     CNode** q = p;
     q = &((*q)->nodes[brep]);
     while ( (*q)->nodes[!brep] )
         q = &((*q)->nodes[!brep]);
     brep = !brep;
     return q;
 }

 */

void CBinTree::print()
{
    inorder(root);
    std::cout << " h = " << height1(root);
    std::cout << "\n";
}

void CBinTree::inorder(CNode* n)
{
    if (!n) return;
    inorder(n->nodes[0]);
    std::cout << n->v << " ";
    inorder(n->nodes[1]);
}

int CBinTree::height1(CNode* n)
{
    int maxh = 0;
    h1(root, 1, maxh);
    return maxh;
}

void CBinTree::h1(CNode* n, int h, int& maxh)
{
    if (!n) return;
    if (h > maxh) maxh = h;
    h1(n->nodes[0], h + 1, maxh);
    h1(n->nodes[1], h + 1, maxh);
}

int CBinTree::height2(CNode* n)
{

    return 0;
}

CNode* CBinTree::buscar(CNode* root, int val)
{
    if (!root){ return nullptr;}
    if (root->v == val){  return root;}
    if (root->v > val){   return buscar(root->nodes[0], val);}
    if (root->v < val){   return buscar(root->nodes[1], val);}
}

int CBinTree::range(CNode* root, int low, int high)
{
    cortar(root, low, high);
    if (!root)
    {
        return 0;
    }
    return range(root->nodes[0],low,high) + root->v + range(root->nodes[1],low,high);
}

CNode* CBinTree::cortar(CNode* raiz, int low, int high)
{
    if (!raiz)
    {
        return nullptr;
    }
    if (raiz->v < low)
    {
        return cortar(raiz->nodes[1], low, high);
    }
    if (raiz->v > high)
    {
        return cortar(raiz->nodes[0], low, high);
    }
    raiz->nodes[0] = cortar(raiz->nodes[0], low, high);
    raiz->nodes[1] = cortar(raiz->nodes[1], low, high);
    return raiz;
}

int CBinTree::range2(CNode* root, int low, int high)
{
    if (!root)
    {
        return 0;
    }
    if (root->v < low)
    {
        return range2(root->nodes[1], low, high);
    }
    if (root->v > high)
    {
        return range2(root->nodes[0], low, high);
    }
    return range2(root->nodes[0], low, high) + root->v + range2(root->nodes[1], low, high);
}

int main()
{
    CBinTree t;
    t.ins(10); t.print();
    t.ins(5); t.print();
    t.ins(15); t.print();
    t.ins(3); t.print();
    t.ins(7); t.print();
    t.ins(18); t.print();


    std::cout << t.range2(t.root,7,15);
    std::cout << std::endl;
    std::cout<< t.range(t.root , 7 ,15);

}
