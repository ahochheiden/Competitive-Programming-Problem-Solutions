#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main()
{
	uint64_t numCases = 0;

	cin >> numCases;

	for(uint64_t i = 0; i < numCases; i++)
	{
		double  num;

		cin >> num;

		cout << ceil(num / 400) << endl;
	}

	return 0;
}