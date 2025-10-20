#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solucion
{
public:
	Solucion();
	
	std::vector<string> findRelative(std::vector<int>& score);
	

private:

};

Solucion::Solucion()
{
}

std::vector<string> Solucion::findRelative(std::vector<int>& score)
{
	std::vector<  std::pair<int, int> > sol;
	
	for (int i = 0 ; i< score.size(); i++)
	{
		sol.push_back({score[i],i});
	}

	std::sort(sol.begin(), sol.end(), [](auto& a, auto& b) {
		return a.first > b.first;
	});

	std::vector<string> sol2(sol.size());
	
	for (int i = 0; i < sol.size(); i++)
	{
		int ori = sol[i].second;
		if (i == 0)
			sol2[ori] = "Gold Medal";
		else if (i == 1)
			sol2[ori] = "Silver Medal";
		else if (i == 2)
			sol2[ori] = "Bronze Medal";
		else
			sol2[ori] = to_string(i + 1); 

	}

	return sol2;
}





int main() {
	Solucion sol;
	std::vector<int> score = { 10,3,8,9,4 };

	sol.findRelative(score);
}
