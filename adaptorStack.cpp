

#include "iostream"
#include "forward_list"

class Stack
{
public:
	Stack();
	void push(int x);
	void pop();
	int TOP();
	void print();
	~Stack();

private:
	std::forward_list<int> lista;
};

Stack::Stack()
{
}

void Stack::push(int x)
{
	lista.push_front(x);
}

void Stack::pop()
{
	lista.pop_front();
}

int Stack::TOP()
{
	return lista.front();
}

void Stack::print()
{
    for (auto it = lista.begin(); it != lista.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


Stack::~Stack()
{
}

int main() {
	Stack st;
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.pop();
	st.print();
	return 0;
}
