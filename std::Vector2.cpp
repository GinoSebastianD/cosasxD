#include "iostream"
#include "algorithm"
#include "vector"


bool test(std::vector<int> numeros) {

	std::sort(numeros.begin(), numeros.end());
	int elem = numeros.at(0) - 1;

	for (int numb: numeros)
	{
		if (numb - elem != 1)
		{
			return false;
		}
		elem = numb;
	}

	
	return true;
}



int main() {

	std::vector<int> nums = { 9,8,5,7,6,10,13,12,11 };
	

	 std::cout << test(nums) << std::endl;


	for (int elem: nums)
	{
		std::cout << elem << " ";
	}



	return 0;
}
