#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string input;

	getline(cin, input);

	bool pos[3] = {true, false, false};

	for(int i = 0; i < input.size(); i++)
	{
		switch(input[i])
		{
			case 'A':
			{
				swap(pos[0], pos[1]);
				break;
			}
			case 'B':
			{
				swap(pos[1], pos[2]);
				break;
			}
			case 'C':
			{
				swap(pos[0], pos[2]);
				break;
			}
			default:
			{
				// do nothing
			}
		}
	}

	for(int i = 0; i < 3; i++)
	{
		if(pos[i] == true)
		{
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}