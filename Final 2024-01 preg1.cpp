#include <iostream>
#include <deque>
#include <vector>


struct asc
{
    bool operator()(int x, int y) {
        return x < y;
    }
};
struct des
{
    bool operator()(int x, int y) {
        return x > y;
    }
};


template <class T, class comp>
class CMaxHeap3
{
public:
    void push(int n);
    int top();
    void pop();
    void print();
    comp compara;
private:
    std::deque<T> heap;
};

template <class T, class comp>
int CMaxHeap3<T,comp>::CMaxHeap3::top()
{
    return heap.front();
}

template <class T, class comp>
void CMaxHeap3<T,comp>::CMaxHeap3::push(int x)
{
    heap.push_back(x);
    int tam = heap.size() - 1;
    while (tam > 0)
    {
        int p = (tam - 1) / 3;
        if ( compara( heap[tam] , heap[p]) )
        {
            std::swap(heap[tam], heap[p]);
            tam = p;
        }
        else
        {
            break;
        }
    }
}

template <class T, class comp>
void CMaxHeap3<T,comp>::CMaxHeap3::pop()
{
    int tam = heap.size();
    heap[0] = heap[tam - 1];
    tam--;
    heap.pop_back();
    int ini = 0;
    while (true)
    {
        int izq = 3 * ini + 1;
        int centro = 3 * ini + 2;
        int der = 3 * ini + 3;
        int cam = ini;
        if (izq < tam && heap[izq] > heap[cam])
        {
            cam = izq;
        }
        if (centro < tam && heap[centro] > heap[cam])
        {
            cam = centro;
        }
        if (der < tam && heap[der] > heap[cam])
        {
            cam = der;
        }
        if (cam!=ini)
        {
            std::swap(heap[cam],heap[ini]);
            ini = cam;
        }
        else
        {
            break;
        }
    }
}

template <class T, class comp>
void CMaxHeap3<T,comp>::CMaxHeap3::print()
{
    for (auto i = heap.begin(); i != heap.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";
}

int main()
{
    CMaxHeap3<int,des> h;
    std::vector<int> vpush = { 30,35,40,50,43,36,60,51,70,90,66,77,23,21,49,88,73 };
    for (auto i : vpush)
        h.push(i);
    h.print();
    h.top();
   for (int j = 0; j < 5; j++)
        h.pop();
    h.print();
}
