#include <iostream>
#include <cstdint>
#include <iomanip>

using namespace std;

int main()
{
	int64_t strands = 0;

	while((cin >> strands) && (strands != 0) && ((strands % 2) == 0))
	{
		double probability = 1;

		for(int64_t i = 2; i <= (strands - 2); i += 2)
		{
			probability *= i;
		}

		for(int64_t i = 3; i <= (strands - 1); i += 2)
		{
			probability /= i;
		}

		cout << fixed << showpoint << setprecision(5) << probability << endl;
	}

	return 0;
}