#include "iostream"
#include "vector"


void burbuja(std::vector<int> nums) {

	for (int i = 0 ; i < nums.size()-1 ; i++)
	{
		for (int j = 0; j < nums.size()-i-1; j++)
		{
			if (nums[j] > nums[j+1])
			{
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}
	for (int elem : nums)
	{
		std::cout << elem << " ";
	}

	std::cout << std::endl;

}

int main() {

	std::vector<int> nums = { 8,7,10,2,5,4,3,6,9,1 };
	burbuja(nums);
	for (int elem: nums)
	{
		std::cout << elem << " ";
	}

}
