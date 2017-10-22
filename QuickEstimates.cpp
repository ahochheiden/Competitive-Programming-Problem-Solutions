#include <iostream>
#include <cctype>
#include <string>
#include <cstdint>

using namespace std;

int64_t numInputs = 0;
int64_t counter = 0;
string input = "";

int main()
{
	cin >> numInputs;
	getline(cin, input);

	for(int64_t i = 0; i < numInputs; i++)
	{
		counter = 0;
		input = "";

		getline(cin, input);

		for(int64_t j = 0; j < input.size(); j++)
		{
			if(isdigit(input[j]))
			{
				counter++;
			}
		}

		cout << counter << endl;
	}

	return 0;
}