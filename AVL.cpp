#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CBinNode {
    int value;
    CBinNode* nodes[2];
    int altura;
    CBinNode(int v) {
        value = v;
        nodes[0] = nullptr;
        nodes[1] = nullptr;
        altura = 1;
    }
};

class AvlTree {
private:
    CBinNode* m_root = nullptr;
    bool find(int x, CBinNode**& p, vector<CBinNode*>& rec);
    void Inorder(CBinNode* p);
    int calcularaltura(CBinNode* p);
    int diferenciadealtura(CBinNode* p);
    void Avl(vector<CBinNode*>& rec);

    // Rotaciones
    CBinNode* rotarDerecha(CBinNode* y);
    CBinNode* rotarIzquierda(CBinNode* x);

public:
    bool Insert(int x);
    void print();
};

int AvlTree::calcularaltura(CBinNode* p) {
    if (!p) return 0;
    int left = p->nodes[0] ? p->nodes[0]->altura : 0;
    int right = p->nodes[1] ? p->nodes[1]->altura : 0;
    return 1 + max(left, right);
}

int AvlTree::diferenciadealtura(CBinNode* p) {
    if (!p) return 0;
    int left = p->nodes[0] ? p->nodes[0]->altura : 0;
    int right = p->nodes[1] ? p->nodes[1]->altura : 0;
    return right - left; // positivo = más pesado a la derecha
}

bool AvlTree::find(int x, CBinNode**& p, vector<CBinNode*>& rec) {
    for (p = &m_root; *p && (*p)->value != x; p = &((*p)->nodes[(*p)->value < x])) {
        if (*p != nullptr) {
            rec.push_back(*p);
        }
    }
    return *p && (*p)->value == x;
}

// ===== ROTACIONES =====
CBinNode* AvlTree::rotarDerecha(CBinNode* y) {
    CBinNode* x = y->nodes[0];
    CBinNode* T2 = x->nodes[1];

    // Rotación
    x->nodes[1] = y;
    y->nodes[0] = T2;

    // Actualizar alturas
    y->altura = calcularaltura(y);
    x->altura = calcularaltura(x);

    return x; // nueva raíz del subárbol
}

CBinNode* AvlTree::rotarIzquierda(CBinNode* x) {
    CBinNode* y = x->nodes[1];
    CBinNode* T2 = y->nodes[0];

    // Rotación
    y->nodes[0] = x;
    x->nodes[1] = T2;

    // Actualizar alturas
    x->altura = calcularaltura(x);
    y->altura = calcularaltura(y);

    return y; // nueva raíz del subárbol
}

// ===== BALANCEO =====
void AvlTree::Avl(vector<CBinNode*>& rec) {
    for (int i = rec.size() - 1; i >= 0; i--) {
        CBinNode* act = rec[i];
        act->altura = calcularaltura(act);
        int balance = diferenciadealtura(act);

        // Desbalance hacia la izquierda
        if (balance < -1) {
            if (diferenciadealtura(act->nodes[0]) <= 0) {
                // Rotación simple derecha
                CBinNode* nuevo = rotarDerecha(act);
                if (i == 0) m_root = nuevo;
                else {
                    CBinNode* padre = rec[i - 1];
                    (padre->nodes[0] == act ? padre->nodes[0] : padre->nodes[1]) = nuevo;
                }
            }
            else {
                // Rotación doble izquierda-derecha
                act->nodes[0] = rotarIzquierda(act->nodes[0]);
                CBinNode* nuevo = rotarDerecha(act);
                if (i == 0) m_root = nuevo;
                else {
                    CBinNode* padre = rec[i - 1];
                    (padre->nodes[0] == act ? padre->nodes[0] : padre->nodes[1]) = nuevo;
                }
            }
        }

        // Desbalance hacia la derecha
        else if (balance > 1) {
            if (diferenciadealtura(act->nodes[1]) >= 0) {
                // Rotación simple izquierda
                CBinNode* nuevo = rotarIzquierda(act);
                if (i == 0) m_root = nuevo;
                else {
                    CBinNode* padre = rec[i - 1];
                    (padre->nodes[0] == act ? padre->nodes[0] : padre->nodes[1]) = nuevo;
                }
            }
            else {
                // Rotación doble derecha-izquierda
                act->nodes[1] = rotarDerecha(act->nodes[1]);
                CBinNode* nuevo = rotarIzquierda(act);
                if (i == 0) m_root = nuevo;
                else {
                    CBinNode* padre = rec[i - 1];
                    (padre->nodes[0] == act ? padre->nodes[0] : padre->nodes[1]) = nuevo;
                }
            }
        }
    }
}

bool AvlTree::Insert(int x) {
    CBinNode** p;
    vector<CBinNode*> rec;
    if (find(x, p, rec)) {
        return false;
    }
    *p = new CBinNode(x);
    rec.push_back(*p);
    Avl(rec);
    return true;
}

void AvlTree::Inorder(CBinNode* p) {
    if (!p) return;
    Inorder(p->nodes[0]);
    cout << p->value << " ";
    Inorder(p->nodes[1]);
}

void AvlTree::print() {
    Inorder(m_root);
    cout << endl;
}

int main() {
    AvlTree t;
    t.Insert(1);
    t.Insert(8);
    t.Insert(9);
    t.Insert(4);
    t.Insert(7);
    t.Insert(6);
    t.Insert(2);
    t.Insert(3);

    cout << "Recorrido in-order (AVL balanceado): ";
    t.print();
}
