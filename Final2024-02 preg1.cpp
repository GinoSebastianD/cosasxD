//#include <iostream>
//#include <vector>
//#include <list>
//using namespace std;
//struct nodo
//{
//    nodo* next;
//    int val;
//    int x;
//    int y;
//    nodo(int xx , int yy , int v) {
//        x = xx;
//        y = yy;
//        val = v;
//        next = NULL;
//    }
//};
//
//struct fo
//{
//    int dimy = 0;
//    int tam_tabla = 0;
//
//    fo(int y , int tam) {
//        dimy = y;
//        tam_tabla = tam;
//    }
//
//
//    int operator()(int x , int y) const {
//        return (x * dimy + y) % tam_tabla;
//    }
//};
//
//
//
//class CSMatrix
//{
//private:
//    int dimx, dimy;
//    int table_size;
//
//
//public:
//    //std::vector<std::list<nodo>>* ht;
//    std::vector<std::list<nodo>> ht;
//    fo functionobj;
//    CSMatrix(int dx, int dy, int ts): functionobj(dy,ts)
//    {
//
//        dimx = dx;
//        dimy = dy;
//        table_size = ts;
//        ht.resize(table_size);
//        //ht = new std::vector<std::list<nodo>>(table_size);
//    }
//
//
//
//    int get(int x, int y)
//    {
//        int id = functionobj(x, y);
//        auto& act = ht[id];
//        for (auto & n : act )
//        {
//            if (n.x == x && n.y == y )
//            {
//                return n.val;
//            }
//        }
//        return 0;
//    }
//
//    void set(int x, int y, int v)
//    {
//        int id = functionobj(x, y);
//        auto& act = ht[id];
//
//        for (auto it = act.begin() ; it != act.end() ; it++)
//        {
//            if (it->x == x && it->y == y)
//            {
//                if (v == 0)
//                {
//                    act.erase(it);
//                }
//                else
//                {
//                    it->val = v;
//                    
//                }
//                return;
//            }
//
//        }
//        if (v !=0 )
//        {
//            act.push_front(nodo(x, y, v));
//        }
//    }
//
//    void print()
//    {
//        for (int i = 0; i < dimx; i++)
//        {
//            for (int j = 0; j < dimy; j++)
//            {
//                cout << get(i, j) << "\t";
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main()
//{
//    CSMatrix m(5, 5, 7); // Matriz 5x5 con tabla hash de tamaño 7
//
//    cout << "1. Matriz inicial (vacía):" << endl;
//    m.print();
//    cout << endl;
//
//    cout << "2. Insertando nuevos elementos:" << endl;
//    m.set(0, 0, 5);  // Esquina superior izquierda
//    m.set(4, 4, 8);  // Esquina inferior derecha
//    m.set(2, 2, 3);  // Centro
//    m.set(1, 3, 6);  // Posición arbitraria
//    m.print();
//    cout << endl;
//
//    cout << "3. Modificando elementos existentes:" << endl;
//    m.set(0, 0, 9);  // Cambiar 5 por 9
//    m.set(2, 2, 7);  // Cambiar 3 por 7
//    m.print();
//    cout << endl;
//
//    cout << "4. Eliminando elementos (poniendo 0):" << endl;
//    m.set(0, 0, 0);  // Eliminar el 9
//    m.set(2, 2, 0);  // Eliminar el 7
//    m.print();
//    cout << endl;
//
//    cout << "5. Intentando eliminar elementos en posiciones vacías:" << endl;
//    m.set(3, 3, 0);  // Intentar eliminar en posición vacía
//    m.print();
//    cout << endl;
//
//    cout << "6. Operaciones mixtas:" << endl;
//    m.set(1, 1, 2);  // Insertar nuevo
//    m.set(1, 1, 4);  // Modificar existente
//    m.set(1, 1, 0);  // Eliminar existente
//    m.set(1, 1, 0);  // Intentar eliminar ya eliminado
//    m.print();
//    cout << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct node
{
    int x, y;
    int val;
    node(int xx, int yy, int v) {
        x = xx;
        y = yy;
        val = v;
    }
};
struct h
{
    int dim = 0;
    int tam_tabla = 0;

    
    h(int d, int t) : dim(d), tam_tabla(t) {}

    int operator()(int x, int y) {
        return  (x * dim + y) % tam_tabla;
    }

};

class CSMatrix
{
private:
    int dimx, dimy;
    int table_size;
public:
    std::vector<std::list<node>>* hash;
    h hash_func;
    CSMatrix(int dx, int dy, int ts) : dimx(dx), dimy(dy), table_size(ts) , hash_func(dimy,table_size)
    {
        hash = new std::vector<std::list<node>>(table_size);
    }

    int get(int x, int y)
    {
        int id = hash_func(x, y);
        auto& act = (*hash)[id];
        for (auto& n : act)
        {
            if (n.x == x && n.y == y)
            {
                return n.val;
            }
        }
        return 0;
    }

    void set(int x, int y, int v)
    {
        int id = hash_func(x, y);
        auto &act = (*hash)[id];

        for (auto it = act.begin() ; it != act.end() ; it++)
        {
            if (it->x == x && it->y == y)
            {
                if (v == 0)
                {
                    act.erase(it);
                }
                else
                {
                    it->val = v;
                }
                return;
            }
        }
        if (v!=0)
        {
            act.push_front(node(x,y,v));
        }
        
    }

    void print()
    {
        for (int i = 0; i < dimx; i++)
        {
            for (int j = 0; j < dimy; j++)
            {
                cout << get(i, j) << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    CSMatrix m(5, 5, 7); // Matriz 5x5 con tabla hash de tamaño 7

    cout << "1. Matriz inicial (vacía):" << endl;
    m.print();
    cout << endl;

    cout << "2. Insertando nuevos elementos:" << endl;
    m.set(0, 0, 5);  // Esquina superior izquierda
    m.set(4, 4, 8);  // Esquina inferior derecha
    m.set(2, 2, 3);  // Centro
    m.set(1, 3, 6);  // Posición arbitraria
    m.print();
    cout << endl;

    cout << "3. Modificando elementos existentes:" << endl;
    m.set(0, 0, 9);  // Cambiar 5 por 9
    m.set(2, 2, 7);  // Cambiar 3 por 7
    m.print();
    cout << endl;

    cout << "4. Eliminando elementos (poniendo 0):" << endl;
    m.set(0, 0, 0);  // Eliminar el 9
    m.set(2, 2, 0);  // Eliminar el 7
    m.print();
    cout << endl;

    cout << "5. Intentando eliminar elementos en posiciones vacías:" << endl;
    m.set(3, 3, 0);  // Intentar eliminar en posición vacía
    m.print();
    cout << endl;

    cout << "6. Operaciones mixtas:" << endl;
    m.set(1, 1, 2);  // Insertar nuevo
    m.set(1, 1, 4);  // Modificar existente
    m.set(1, 1, 0);  // Eliminar existente
    m.set(1, 1, 0);  // Intentar eliminar ya eliminado
    m.print();
    cout << endl;

    return 0;
}
