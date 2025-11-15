#include <iostream>
#include <list>
using namespace std;

struct objx;
struct CSNode
{
    CSNode(int _x, int _y, int _v);
    int x, y;
    int value;
};

CSNode::CSNode(int _x, int _y, int _v)
{
    x = _x; y = _y; value = _v;
}

class CSparseMatrix
{
public:

    CSparseMatrix(int xdim = 0, int ydim = 0);
    ~CSparseMatrix();
    bool Set(int x, int y, int value);
    int Get(int x, int y);
    void Print();
    int XDim, YDim;
    list<CSNode> smatrix;
    objx operator()(int a, int b);
};

CSparseMatrix::CSparseMatrix(int _xdim, int _ydim)
{
    XDim = _xdim; YDim = _ydim;
}

CSparseMatrix::~CSparseMatrix()
{
}

bool CSparseMatrix::Set(int x, int y, int value)
{
    if (x > XDim || y > YDim)
    {
        return false;
    }
    for (auto it = smatrix.begin() ; it != smatrix.end(); it++)
    {
        if (it->x == x && it->y == y)
        {
            if (value != 0)
            {
                it->value = value;
                return true;
            }
            smatrix.erase(it);
            return true;
        }
    }
    if (value == 0)
    {
        return true;
    }
    smatrix.push_back(CSNode(x, y, value));

    return 0;
}

int CSparseMatrix::Get(int x, int y)
{
    for (auto& it : smatrix)
    {
        if ( it.x == x && it.y == y)
        {
            return it.value;
        }
    }

}



void CSparseMatrix::Print()
{
    cout << "\n--------------------\n";
    for (int f = 0; f < XDim; f++) {
        for (int c = 0; c < YDim; c++) {
            cout << Get(f, c) << "  ";
        } cout << endl;
    }
    cout << endl;
}
struct objx
{
    CSparseMatrix* max;
    int x, y;
    objx(CSparseMatrix* m , int xx, int yy)
    {
        max = m;
        x = xx;
        y = yy;
    }
    objx operator = (  int v) {
        max->Set(x, y, v);
        return *this;
    }
    operator int() {
        return max->Get(x,y);
    }
};

objx CSparseMatrix::operator()(int x, int y)
{
    return objx(this, x, y);
}

int main(void)
{
    CSparseMatrix m(5, 5);

    m.Set(0, 0, 3);
    m.Set(2, 1, 5);
    m.Set(1, 2, 1);
    m.Set(4, 3, 8);
    m.Set(0, 4, 6);
    //----------------------
    m.Set(1, 2, 7);
    m.Set(4, 3, 0);
    m.Set(0, 4, 0);
    m.Print();

    
        m(0,0) = 0;
        m(4,0) = 1;
        m(4,4) = 2;
        m(0,4) = 3;
        m.Print();
        cout << "\n 0,0 => " << m(0, 0);
        cout << "\n 3,5 => " << m(4, 1);
        cout << "\n 7,3 => " << m(1, 2);
        m.Print();

    return 0;
}

