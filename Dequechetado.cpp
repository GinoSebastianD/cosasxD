#include <iostream>

class XVector
{
public:
    XVector(int size_map, int size_vec);
    ~XVector();
    void push_back(int x);
    void push_front(int x);
    int& operator [] (int x);
    void expand(int nuevotam);
    int** ini;
    int** fin;
    int* ini_array;
    int* fin_array;

    int** map;
    int size_map, size_vec;
    int size;
};
//constructor
XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    map = new int* [size_map];
    ini = map + (size_map/2);
    fin = ini;
    ini_array = nullptr;
    fin_array = nullptr;
    size = 0;
}

XVector::~XVector()
{
    for (int** p = ini; p <= fin; ++p)
    {
        if (*p != nullptr)
        {
            delete[] * p;
            *p = nullptr;
        }
    }
    delete[] map;
}
void XVector::expand(int nuevotam)
{
    int** ntam = new int*[nuevotam];
    int** n_ini = ini;
    int** p_medio_nmapa = ntam + (nuevotam / 2) - 1;
    while (n_ini <= fin)
    {
        if (n_ini == ini)
        {
            ini = p_medio_nmapa;
        }
        if (n_ini == fin)
        {
            fin = p_medio_nmapa;
            *p_medio_nmapa = *n_ini;
            break;
        }
        *p_medio_nmapa = *n_ini;
        n_ini++;
        p_medio_nmapa++;
    }
    int** tmp = map;
    size_map = nuevotam;
    map = ntam;
    delete [] tmp;

}
void XVector::push_back(int x)
{
    if (fin_array == nullptr)
    {
        *fin = new int[size_vec];
        fin_array = *fin + (size_vec/2);
        ini_array = fin_array;
        *fin_array = x;
        size++;
    }
    else if(fin_array == *fin + size_vec-1)
    {
        if (fin == map+size_map-1)
        {
            expand(size_map*2);
            fin++;
            *fin = new int[size_vec];
            fin_array = *fin;
            *fin_array = x;
            size++;
        }
        else
        {
            fin++;
            *fin = new int[size_vec];
            fin_array = *fin;
            *fin_array = x;
            size++;
        }
    }
    else
    {   
        fin_array++;
        *fin_array = x;
        size++;
    }
}

void XVector::push_front(int x)
{
    if (ini_array == nullptr)
    {
        *ini = new int[size_vec];
        ini_array = *ini + (size_vec/2);
        fin_array = ini_array;
        *ini_array = x;
        size++;
    }
    else if(ini_array == *ini)
    {
        if (ini == map)
        {
            expand(size_map * 2);
            ini--;
            *ini = new int[size_vec];
            ini_array = *ini + size_vec - 1;
            *ini_array = x;
            size++;
        }
        else
        {
            ini--;
            *ini = new int[size_vec];
            ini_array = *ini + size_vec - 1;
            *ini_array = x;
            size++;
        }
    }
    else
    {
        ini_array--;
        *ini_array = x;
        size++;
    }
}

int& XVector::operator[](int x)
{
    int faltante = ini_array - *ini;
    int total = faltante + x;
    return *( *(ini + (total/size_vec) ) + total % size_vec);
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
    v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v); 
    v.push_front(33); v.push_back(77);
    print(&v);
}
