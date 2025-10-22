#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solucion
{
public:
	vector<int> suma(vector<int>& nums, int target);

private:

};



vector<int> solucion::suma(vector<int>& nums, int target)
{
	vector<int> sol;
	unordered_map<int, int> vistos; 
	for (int i = 0; i < nums.size(); i++)
	{
		int falta = target - nums[i]; 

		if (vistos.count(falta))
		{
			sol.push_back(vistos[falta]);
			sol.push_back(i);
			break;
		}

		vistos[nums[i]] = i;
	}

	for (int ele: sol)
	{
		cout << ele << " ";
	}

	return sol;
	
}




int main() {
	solucion sol;

	vector<int> vec = {3,2,3};
	sol.suma(vec,6);
}
