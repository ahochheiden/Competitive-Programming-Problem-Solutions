#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count = 0;

	cin >> count;

	string garbage;

	getline(cin, garbage);

	string line = "";
	string match = "Simon says";

	for(int i = 0; i < count; i++)
	{
		getline(cin, line);

		if(line.size() >= 10)
		{
			if(match == line.substr(0, 10))
			{
				cout << line.substr(10, line.size()) << endl;
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
	}

	return 0;
}