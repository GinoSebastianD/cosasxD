#include <iostream>
#include <queue>

class CSortedQueue
{
public:
    void pushx(int x);
    void popx();
    int frontx();
    void remx(int x);
    void printx();
    std::queue<int> q;
};

void CSortedQueue::pushx(int x)
{
    if (q.empty())
    {
        q.push(x);
    }
    else
    {
        std::queue<int> tmp;
        bool entro = false;
        while (!q.empty())
        {
            if ( !entro && q.front() > x)
            {
                tmp.push(x);
                entro = true;
            }
            tmp.push(q.front());
            q.pop();
        }
        if (!entro)
        {
            tmp.push(x);
        }
        while (!tmp.empty())
        {
            q.push(tmp.front());
            tmp.pop();
        }
    }
}

void CSortedQueue::popx()
{
    if (!q.empty())
    {
        q.pop();
    }
}

int CSortedQueue::frontx()
{
    if (!q.empty())
    {
        return q.front();
    }
}

void CSortedQueue::remx(int x)
{
    std::queue<int> tmp;
    while (!q.empty())
    {
        if (x!=q.front())
        {
            tmp.push(q.front());
            q.pop();
        }
        else
        {
            q.pop();
        }
    }
    q = tmp;

    

}

void CSortedQueue::printx()
{
    std::queue<int> tmp2 = q;
    while (!tmp2.empty())
    {
        std::cout << tmp2.front() << " ";
        tmp2.pop();
    }
    std::cout << std::endl;
}

int main()
{
    CSortedQueue sq;
    sq.pushx(40); sq.printx();
    sq.pushx(23); sq.printx();
    sq.pushx(51); sq.printx();
    sq.pushx(12); sq.printx();
    sq.pushx(30); sq.printx();
    sq.pushx(5);  sq.printx();
    sq.pushx(40); sq.printx();
    sq.pushx(18); sq.printx();

    std::cout << "comienza otro" << std::endl;
    sq.remx(40);  sq.printx();
    sq.remx(23);  sq.printx();
    sq.remx(12);  sq.printx();
    sq.remx(5);  sq.printx();

    std::cout << "\nfront => " << sq.frontx(); sq.popx();
    std::cout << "\nfront => " << sq.frontx(); sq.popx();
    sq.printx();
}

