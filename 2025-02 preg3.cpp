
#include <iostream>

struct CNode
{
    CNode(int _v)
    {
        v = _v; left = right = 0;
    }
    int v;
    CNode* left, * right;
};

class CBinTree
{
public:
    CNode* root;

    CBinTree();
    ~CBinTree();
    bool find(int x, CNode**& p);
    bool ins(int x);
    void inorder(CNode* n);
    void print();
    void printRange(int min, int max);
    void recor(CNode* raiz, int x, int y);

private:
    void deleteTree(CNode* n);
};

CBinTree::CBinTree()
{
    root = 0;
}

CBinTree::~CBinTree()
{
    deleteTree(root);
}

void CBinTree::deleteTree(CNode* n)
{
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}

bool CBinTree::find(int x, CNode**& p)
{
    p = &root;
    while (*p && (*p)->v != x)
        if ((*p)->v < x)
            p = &((*p)->right);
        else
            p = &((*p)->left);
    return *p != 0;
}

bool CBinTree::ins(int x)
{
    CNode** p;
    if (find(x, p)) return 0;
    *p = new CNode(x);
    return 1;
}

void CBinTree::print()
{
    inorder(root);
    std::cout << "\n";
}

void CBinTree::inorder(CNode* n)
{
    if (!n) return;
    inorder(n->left);
    std::cout << n->v << " ";
    inorder(n->right);
}



void CBinTree::recor(CNode* raiz, int x, int y)
{
    if (!raiz) { 
        return; 
    }

    if (raiz->v > x)
        recor(raiz->left, x, y);

    if (raiz->v >= x && raiz->v <= y)
        std::cout << raiz->v << " ";

    if (raiz->v < y)
        recor(raiz->right, x, y);
}

void CBinTree::printRange(int min, int max)
{

    recor(root, min, max);
    

}




int main()
{
    CBinTree t;
    t.ins(60); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(65);
    t.ins(80); t.ins(15); t.ins(25);
    t.ins(35); t.ins(45); t.ins(62);
    t.ins(68); t.ins(75); t.ins(85);

    std::cout << "Árbol completo: ";
    t.print();

    std::cout << "\nRango [35, 75]: ";
    t.printRange(35, 75);
    // Salida esperada: 35 40 45 60 62 65 68 70 75

    std::cout << "\nRango [40, 70]: ";
    t.printRange(40, 70);
    // Salida esperada: 40 45 60 62 65 68 70

    std::cout << "\nRango [10, 25]: ";
    t.printRange(10, 25);
    // Salida esperada: 15 20 25

    std::cout << "\nRango [65, 100]: ";
    t.printRange(65, 100);
    // Salida esperada: 65 68 70 75 80 85

    std::cout << "\n\n";
    return 0;
}
