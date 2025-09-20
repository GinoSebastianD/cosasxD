#include "iostream"
//con o sin vector
using namespace std;


class MyCircularDeque {
public:
    int v;
    int* arr;;
    int* head ;
    int* tail;
    int nelem;
    MyCircularDeque(int k) {
        v = k;
        arr = new int[v];
        head = nullptr;
        tail = nullptr;
        nelem = 0;
    }

    bool insertFront(int value) {
      
        if (head == nullptr)
        {
            head = arr + v/2;
            tail = head;
            *head = value;
            nelem++;
            return true;
        }
        if (head == arr && nelem != v )
        {
            head = arr + v-1;
            *head = value;
            nelem++;
            return true;
        }
        if (nelem == v)
        {
            return false;
        }
        else
        {
            head--;
            *head = value;
            nelem++;
            return true;
        }
    }

    bool insertLast(int value) {
        if (tail == nullptr)
        {
            tail = arr + v / 2;
            head = tail;
            *tail = value;
            nelem++;
            return true;
        }
        if (tail == arr+v-1 && nelem != v)
        {
            tail = arr;
            *tail = value;
            nelem++;
            return true;

        }
        if (nelem == v)
        {
            return false;
        }
        else
        {
            tail++;
            *tail = value;
            nelem++;
            return true;
        }
    }

    bool deleteFront() {

        if (isEmpty())
        {
            return false;
        }
        if (head == arr + v-1)
        {
            head = arr;
            nelem--;
            return true;
        }
        else
        {
            head++;
            nelem--;
            return true;
        }
    }

    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }
        if (tail == arr)
        {
            tail = arr + v - 1;
            nelem--;

            return true;
        }
        else
        {
            tail--;
            nelem--;
            return true;
        }
    }

    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        return *head;
    }

    int getRear() {
        if (isEmpty())
        {
            return -1;
        }
        return *tail;
    }

    bool isEmpty() {
        if (nelem == 0)
        {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (nelem == v)
        {
            return true;
        }
        return false;
    }
};
int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);

    cout << boolalpha; // para imprimir true/false en vez de 1/0

    cout << obj->insertFront(8) << endl;  // true
    cout << obj->insertLast(8) << endl;   // true
    cout << obj->insertLast(2) << endl;   // true
    cout << obj->getFront() << endl;      // 8
    cout << obj->deleteLast() << endl;    // true
    cout << obj->getRear() << endl;       // 8
    cout << obj->insertFront(9) << endl;  // true
    cout << obj->deleteFront() << endl;   // true
    cout << obj->getRear() << endl;       // 8
    cout << obj->insertLast(2) << endl;   // true
    cout << obj->isFull() << endl;        // true o false según tu lógica

    delete obj;
    return 0;
}


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
