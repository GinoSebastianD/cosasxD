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
    std::queue<int> temp;
    while (!q.empty() && q.front() < x)
    {
        temp.push( q.front()  );
        q.pop();
    }
    temp.push(x);
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    q = temp;

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
    return q.front();
}

void CSortedQueue::remx(int x)
{
    std::queue<int> tmp;
    while (!q.empty())
    {
        if (q.front() == x )
        {
            q.pop();
        }
        else
        {
            tmp.push(q.front());
            q.pop();
        }
    }
    q = tmp;
}

void CSortedQueue::printx()
{
    std::queue<int> tmp = q ;
    while (!tmp.empty())
    {
        std::cout << tmp.front()  << " " ;

        tmp.pop();
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

    sq.remx(40);  sq.printx();
    sq.remx(23);  sq.printx();
    sq.remx(12);  sq.printx();
    sq.remx(5);  sq.printx();

    std::cout << "\nfront => " << sq.frontx(); sq.popx();
    std::cout << std::endl;
    std::cout << "\nfront => " << sq.frontx(); sq.popx() ;
    std::cout << std::endl;
    sq.printx();
}

