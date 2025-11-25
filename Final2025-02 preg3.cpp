#include <iostream>
#include <queue>
using namespace std;

// se puede hacer con tabla hash tambien uwu
int HijoIzq(int i) { return 2 * i + 1; }
int HijoDer(int i) { return 2 * i + 2; }

void XMayores(int heap[], int size, int x)
{
    std::priority_queue<std::pair<int, int>> col;
    col.push({heap[0], 0});

    while (!col.empty() && x > 0)
    {
        int idx = col.top().second;
        int val = col.top().first;
        
        cout << val << " ";

        col.pop();

        int izq = HijoIzq(idx);
        if (izq < size)
        {
            col.push({ heap[izq],izq });
        }
        int der = HijoDer(idx);
        if (der < size)
        {
            col.push({ heap[der],der });
        }
        x--;
    }


}

int main()
{

    int heap1[15] = { 95, 83, 90, 75, 80, 89, 70, 60, 65, 55, 45, 87, 40, 35, 25 };
    int heap2[15] = { 100, 95, 90, 80, 85, 88, 75, 70, 78, 82, 83, 86, 73, 72, 71 };
    int heap3[15] = { 98, 95, 92, 91, 85, 80, 75, 70, 88, 82, 83, 78, 76, 73, 72 };

    XMayores(heap1, 15, 4);
    XMayores(heap2, 15, 4);
    XMayores(heap3, 15, 4);




    return 0;
}
