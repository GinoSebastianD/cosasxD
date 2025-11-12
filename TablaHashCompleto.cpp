#include <iostream>
#include <list>
#include<vector>

struct cf {
    int operator()(int x) const {
        return x;
    }
};

// tipo de dato, tipo de ED, functionObjects, tamaño del vector
template<class T, class C , class F , int S>
class TableHash
{
public:
	TableHash() {
		ht = new std::vector<C>(S);
	};

	F f;
	std::vector<C>* ht;

	void ins(T x);
	void remove(T x);
};

template<class T, class C, class F, int S>
void TableHash<T, C, F, S>::ins(T x)
{
    int i = f(x) % S;
    (*ht)[i].push_front(x);
}

template<class T, class C, class F, int S>
void TableHash<T, C, F, S>::remove(T x)
{
    int i = f(x) % S;
	(*ht)[i].remove(x);
}




int main() {
	TableHash<int, std::list<int>, cf, 7> ht;
	ht.ins(7);
	ht.ins(8);
	ht.ins(10);
	ht.ins(11);
	ht.ins(5);

	ht.remove(11);

}
