#include <iostream>
#include <vector>
using namespace std;

template<class T> struct objx; 

struct node
{
    int val, x, y;
    node* down;
    node* right;
    node(int v, int coordenada_x, int coordenada_y) {
        val = v;
        x = coordenada_x;
        y = coordenada_y;
        down = nullptr;
        right = nullptr;
    }
};

template<class T>
class MatrixSparsa
{
public:
    MatrixSparsa(T size_x, T size_y) :
        vec_x(size_x, nullptr),
        vec_y(size_y, nullptr)
    {
    }

    bool find_h(T x, T y, node**& ph);
    bool find_v(T x, T y, node**& pv);
    void set(T x, T y, int val);
    int get(T x, T y);
    void print();
    objx<T> operator()(T x, T y);

private:
    std::vector<node*> vec_x;
    std::vector<node*> vec_y;
};


template<class T>
bool MatrixSparsa<T>::find_h(T x, T y, node**& ph)
{
    ph = &vec_y[y];
    for (; *ph && (*ph)->x < x; ph = &(*ph)->right);
    return *ph && (*ph)->x == x && (*ph)->y == y;
}

template<class T>
bool MatrixSparsa<T>::find_v(T x, T y, node**& pv)
{
    pv = &vec_x[x];
    for (; *pv && (*pv)->y < y; pv = &(*pv)->down);
    return *pv && (*pv)->x == x && (*pv)->y == y;
}

template<class T>
void MatrixSparsa<T>::set(T x, T y, int val)
{
    node** pv;
    node** ph;

    bool existeV = find_v(x, y, pv);
    bool existeH = find_h(x, y, ph);

    if (existeV && existeH) {
        if (val == 0) {
            node* borrar = *pv;
            *pv = borrar->down;
            *ph = borrar->right;
            delete borrar;
        } else {
            (*pv)->val = val;
        }
        return;
    }
    if (val == 0) return;

    node* n = new node(val, x, y);
    n->down = *pv;
    *pv = n;
    n->right = *ph;
    *ph = n;
}

template<class T>
int MatrixSparsa<T>::get(T x, T y)
{
    node** pv;
    if (find_v(x, y, pv))
        return (*pv)->val;
    return 0;
}


template<class T>
struct objx {
    MatrixSparsa<T>* m;
    T x, y;
    objx(MatrixSparsa<T>* mat, T xx, T yy) {
        m = mat;
        x = xx;
        y = yy;
    }

    objx& operator=(int v) {
        m->set(x, y, v);
        return *this;
    }
    operator int() {
        return m->get(x, y);
    }
};


template<class T>
objx<T> MatrixSparsa<T>::operator()(T x, T y) {
    return objx<T>(this, x, y);
}


template<class T>
void MatrixSparsa<T>::print()
{

}


int main() {
    MatrixSparsa<int> max(4, 4);

    max.set(0, 0, 5);
    max.set(1, 0, 2);
    max.set(2, 0, 12);
    max.set(3, 0, 17);

    max.set(0, 1, 17);
    max.set(1, 1, 8);
    max.set(2, 1, 0);

    max.set(3, 2, 9);
    max.set(3, 3, 1);

    cout << max.get(3, 2) << endl; 
    cout << max.get(1, 2) << endl; 

    max.set(1, 0, 0);
    max.set(1, 1, 0);

    max(0, 0) = 7;
    int a = max(0, 0);
    cout << a << endl;


}
