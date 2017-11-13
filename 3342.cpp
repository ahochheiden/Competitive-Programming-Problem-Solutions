#include <iostream>
#include <cstdint>

using namespace std;

int main()

{
	int64_t input = 0;
	int64_t converted_input = 0;
	int64_t temp = 0;
	int64_t place = 0;
	int64_t multi = 0;

	while(true)
	{
		cin >> input;

		if(input == 0)
		{
			break;
		}

		temp = input;
		multi = 1;
		place = 0;
		converted_input = 0;

		while(temp)
		{
			place = (temp % 10);
			temp = (temp / 10);

			if(place > 4)
			{
				place--;
			}

			converted_input += place * multi;
			multi *= 9;
		}

		cout << input << ": " << converted_input << endl;
	}

	return 0;
}