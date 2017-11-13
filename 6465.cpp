#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
	int64_t loops, num, count;
	string input;

	cin >> loops;

	for(int64_t i = 0; i < loops; i++)
	{
		count = 0;
		cin >> num;
		cin.ignore();

		getline(cin, input);

		cout << num << " ";

		for(int64_t j = 2; j < input.size(); j += 2)
		{
			if(input.at(j) > input.at(j - 2))
			{
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}