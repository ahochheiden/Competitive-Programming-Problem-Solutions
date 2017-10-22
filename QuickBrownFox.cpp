#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int tableSize = 26;
const char lowerA = 'a';

bool table[tableSize];

void reset()
{
	for(int i = 0; i < tableSize; i++)
	{
		table[i] = false;
	}
}

void answer()
{
	bool isPangram = true;
	string answer = "";

	for(int i = 0; i < tableSize; i++)
	{
		if(table[i])
		{
			continue;
		}
		else
		{
			isPangram = false;
		}

		if(isPangram)
		{
			continue;
		}
		else
		{
			answer += static_cast<char>('a' + i);
		}
	}

	if(isPangram)
	{
		cout << "pangram" << endl;
	}
	else
	{
		cout << "missing " << answer << endl;
	}

}

int main()
{
	int count = 0;

	cin >> count;

	string garbage = "";

	getline(cin, garbage);

	string line = "";

	for(int i = 0; i < count; i++)
	{
		reset();

		getline(cin, line);

		for(int j = 0; j < line.size(); j++)
		{
			char character = line[j];

			if(isalpha(character))
			{
				table[tolower(character) - 'a'] = true;
			}
		}

		answer();
	}

	return 0;
}