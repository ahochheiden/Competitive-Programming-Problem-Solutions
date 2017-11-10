#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

const vector<string> combinations = {
	"PCC", "PPC",  // -2 inversions
	"PCP", "CPC"}; // -1 inversions

int main()
{
	string input;

	cin >> input;

	string sorted(input);

	sort(sorted.begin(), sorted.end());

	uint64_t steps = 0;

	while(input != sorted)
	{
		for(const auto combo : combinations)
		{
			auto index = input.find(combo);

			if(index != string::npos)
			{
				sort((input.begin() + index), (input.begin() + index + 3));
				steps++;
				break; // in case a better inversion occurs from sort
			}
		}
	}

	cout << steps << endl;

	return 0;
}