#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int64_t N = 0;
	int64_t w = 0;
	int64_t d = 0;
	int64_t difference = 0;
	int64_t basketWithCoin = 0;
	int64_t sumWeightGiven = 0;
	int64_t sumWeightExpected = 0;

	string input;

	while(getline(cin, input))
	{
		stringstream stream(input);

		stream >> N >> w >> d >> sumWeightGiven;

		if(N < 2)
		{
			return 0;
		}

		sumWeightExpected = 0;
		basketWithCoin = 0;
		difference = 0;

		for(int64_t i = 1; i < N; i++)
		{
			sumWeightExpected += (i * w);
		}

		difference = (sumWeightExpected - sumWeightGiven);

		if(sumWeightExpected == sumWeightGiven)
		{
			basketWithCoin = N;
		}
		else
		{
			basketWithCoin = (difference / d);
		}

		cout << basketWithCoin << endl;
	}

	return 0;
}