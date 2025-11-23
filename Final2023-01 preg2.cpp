#include <iostream>
#include <map>

class CSMatrix
{
public:
    CSMatrix(int dx, int dy);
    bool set(int x, int y, int value);
    int get(int x, int y);
    void print();

private:
    // matrix

    std::map<std::pair<int,int> , int> coordenadas;
    int dimx, dimy; 
};

CSMatrix::CSMatrix(int dx, int dy)
{
    dimx = dx; dimy = dy;
}

bool CSMatrix::set(int x, int y, int value)
{
    if (x > dimx && y > dimy)
    {
        return false;
    }
    std::pair<int, int> key = { x,y };
    if (value != 0) {
        coordenadas[key] = value;
        return true;
    }
    else
    {
        coordenadas.erase(key);
    }
}

int CSMatrix::get(int x, int y)
{
    std::pair<int, int> key = {x , y};
  
    auto f = coordenadas.find(key);

    if (f == coordenadas.end() )
    {
        return 0;
    }   
    return f->second;

}

void CSMatrix::print()
{
    std::cout << "\n";
    for (int x = 0; x < dimx; x++)
    {
        for (int y = 0; y < dimy; y++)
        {
            std::cout << get(x, y) << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    CSMatrix m(8, 8);

    m.set(2, 1, 5); //si
    m.set(2, 3, 2); //si
    m.set(2, 5, 7); //si
    m.set(5, 3, 9); //si
    m.set(7, 3, 12);//si
    m.set(1, 4, 3);//si
    m.set(2, 4, 0);
    m.set(5, 5, 8);
    m.set(3, 6, 1);
    m.print();
    m.set(1, 4, 0);
    m.set(2, 3, 0);
    m.set(4, 3, 0);
    m.set(0, 1, 0);
    m.print();
    std::cout << "\n 0,0 => " << m.get(0, 0);
    std::cout << "\n 3,5 => " << m.get(3, 5);
    std::cout << "\n 7,3 => " << m.get(7, 3);
}





//
//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//    map<char, int> m;
//
//    //initializing
//    m['a'] = 10;
//    m['b'] = 20;
//    m['c'] = 30;
//    m.insert({ 'd',44 });
//    m.insert({ 'e',31 });
//    m.insert({ 'f',24 });
//
//    m.erase('b');
//    m.erase('d');
//
//    auto f1 = m.find('a');
//    if (f1 != m.end())
//        cout << "'a' found! " << f1->first << " " << f1->second;
//    else
//        cout << "'a' no found! ";
//    cout << "\n";
//
//    auto f2 = m.find('b');
//    if (f2 != m.end())
//        cout << "'b' found!" << f2->first << " " << f2->second;
//    else
//        cout << "'b' no found!";
//
//    cout << "\n";
//
//    return 0;
//}
