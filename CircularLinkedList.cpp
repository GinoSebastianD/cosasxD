//falta usar functores y meterle templates
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node(int v) {
        data = v;
        next = nullptr;
    }
};

class CircularLinkedList
{
    node* head = NULL;
public:
    void add(int value)
    {
        node* ant = new node(value);
        if (head == nullptr)
        {
            head = ant;
            head->next = head;
        }
        else if(value < head->data){
                node* pos_ant = head;
                while (pos_ant->next != head)
                {
                    pos_ant = pos_ant->next;
                }
                ant->next = head;
                pos_ant->next = ant;
                head = ant;
        }
        else
        {
            node* pos_fin = head;
            while (pos_fin->next != head && pos_fin->next->data<value)
            {
                pos_fin = pos_fin->next;
            }
            ant->next = pos_fin->next;
            pos_fin->next = ant;    
        }
    }
    void del(int value)
    {
        node* tmp = head;
        if (head->data == value)
        {
            if (head->data == value && head->next == head)
            {
                head = nullptr;

            }
            else
            {
                while (tmp->next != head)
                {
                    tmp = tmp->next;
                }
                tmp->next = head->next;
                head = head->next;
            }
        }
        else
        {
            while (tmp->next->data<value)
            {
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
        }
    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        while (head && cont < 1)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout << " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}
