#include "iostream"
#include "vector"


std::vector<int> particion(std::vector<int> numeros) {
	std::vector<int> tmp;

	for (int i = 1; i < numeros.size()-1; i++)
	{
		if (numeros[i] < numeros[i-1] && numeros [i] > numeros[i+1])
		{
			tmp.push_back(numeros[i]);
		}

	}
	return tmp;

}


int main() {
	std::vector<int> numeros = { 8,7,5,9,6,2,4,1 };


	std::vector <int> num = particion(numeros);
	
	for (int elem: num)
	{
		std::cout << elem << " ";
	}
}
