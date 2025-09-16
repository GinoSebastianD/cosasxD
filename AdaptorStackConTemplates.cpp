#include "vector"
#include "iostream"
using namespace std;



template<class T, class P>
class vec_stack
{
public:
	vec_stack<T,P>() {};
	void push(T x);
	void pop();
	void print();
private:
	P vect;
};


template<class T, class P>
void vec_stack<T,P>::push(T x)
{
	vect.push_back(x);
}
template<class T, class P>
void vec_stack<T, P>::pop()
{
	vect.pop_back();
}

template<class T, class P>
void vec_stack<T,P>::print()
{
	for (int elemento: vect)
	{
		cout<<elemento << " ";
	}
}



int main() {
	vec_stack<int ,vector<int>> v_S;
	v_S.push(5);
	v_S.push(4);
	v_S.push(3);
	v_S.push(2);
	v_S.push(1);
	v_S.push(0);
	v_S.print();
}
