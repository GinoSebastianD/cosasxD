#include <iostream>

class XVector
{
public:
    XVector(int size_map, int size_vec);
    ~XVector();
    void push_back(int x);
    void push_front(int x);
    void expand();
    int& operator[] (int x);
    

    int** map;
    int size_map, size_vec;
    int** ini;
    int** fin;
    int* ini_vec;
    int* fin_vec;
    int size;
};

XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    map = new int*[size_map];
    ini = map + (size_map/2);
    fin = ini;
    ini_vec = nullptr;
    fin_vec = nullptr;
    size = 0;
}

XVector::~XVector()
{

}

void XVector::push_back(int x)
{
    if (fin_vec == nullptr)
    {
        *fin = new int[size_vec];
        fin_vec = *fin + (size_vec-1);
        ini_vec = fin_vec;
        *fin_vec = x;
        size++;
    }
    else if (fin_vec == *fin+size_vec-1  )
    {
        if (*fin == *map+size_map-1)
        {
            return;
        }
        fin++;
        *fin = new int[size_vec];
        fin_vec = *fin;
        *fin_vec = x;
        size++;
    }
    else
    {
        fin_vec++;
        *fin_vec = x;
        size++;
    }
}

void XVector::push_front(int x)
{
    if (ini_vec == nullptr)
    {
        *ini = new int[size_vec];
        ini_vec = *ini + (size_vec / 2);
        fin_vec = ini_vec;
        *ini_vec = x;
        size++;
    }
    else if (ini_vec == *ini)
    {
        if (ini == map)
        {
            expand();
        }
        ini--;
        *ini = new int[size_vec];
        ini_vec = *ini + size_vec - 1;
        *ini_vec = x;
        size++;
    }
    else
    {
        ini_vec--;
        *ini_vec = x;
        size++;
    }

}

void XVector::expand()
{

}

int& XVector::operator[](int x)
{
    int offset = ini_vec - *ini;
    int total = x + offset;
    return *(*(ini + (total / size_vec)) + total % size_vec);
}

void print(XVector* p)
{ //no modificar esta función
    for (int i = 0; i < p->size; i++)
        std::cout << (*p)[i] << " ";
    std::cout << "\n";
}

int main()
{
    //no modificar esta función main
    XVector v(4, 3);
    v.push_back(3); v.push_back(8); v.push_back(1);
    v.push_back(4); v.push_back(9); v.push_back(6);
    v.push_back(7);
    print(&v);
   /* v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v);
    v.push_front(33); v.push_back(77);
    print(&v);*/
}
