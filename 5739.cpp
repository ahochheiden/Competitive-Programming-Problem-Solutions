#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int numNames;
int maxNameLength;
int caseCount = 0;

string input;
string name;
string firstName;
string lastName;
string temp;

set<string> userNames;

bool stop;

void solve();
void prepare();
void strip(string &nameToStrip);

int main()
{
	while(cin >> numNames >> maxNameLength)
	{
		if(numNames && maxNameLength)
		{
			getline(cin, temp);
			cout << "Case " << ++caseCount << endl;
			solve();
		}
		else
		{
			break;
		}
	}

	return 0;
}

void solve()
{
	name.clear();
	firstName.clear();
	lastName.clear();
	temp.clear();
	userNames.clear();

	for(int i = 0; i < numNames; i++)
	{
		getline(cin, input);

		prepare();

		if(userNames.count(name) == 0)
		{
			userNames.insert(name);

			cout << name << endl;
			continue;
		}

		for(int j = 1; j < 10; j++)
		{
			temp = name;
			if(temp.length() == maxNameLength)
			{
				temp.pop_back();
			}
			temp += static_cast<char>('0' + j);

			if(userNames.count(temp) == 0)
			{
				userNames.insert(temp);

				cout << temp << endl;
				stop = true;
				break;
			}
		}

		if(stop)
		{
			stop = false;
			continue;
		}

		for(int j = 10; j < 100; j++)
		{
			temp = name;
			if(temp.length() == maxNameLength)
			{
				temp.pop_back();
			}
			if(temp.length() == maxNameLength - 1)
			{
				temp.pop_back();
			}
			temp += static_cast<char>('0' + (j / 10));
			temp += static_cast<char>('0' + (j % 10));

			if(userNames.count(temp) == 0)
			{
				userNames.insert(temp);
				cout << temp << endl;
				break;
			}
		}
	}
}

void prepare()
{
	stringstream nameStringStream(input);
	name.clear();

	nameStringStream >> firstName;

	while(nameStringStream >> temp)
	{
		lastName = temp;
	}

	strip(firstName);
	strip(lastName);

	name += tolower(firstName[0]);

	for(int i = 0; i < lastName.length(); i++)
	{
		if(name.length() < maxNameLength)
		{
			name += tolower(lastName[i]);
		}
	}
}

void strip(string &nameToStrip)
{
	for(int i = 0; i < nameToStrip.size(); i++)
	{
		if(nameToStrip[i] == '-')
		{
			nameToStrip.erase(nameToStrip.begin() + i);
			i--;
		}
		if(nameToStrip[i] == '\'')
		{
			nameToStrip.erase(nameToStrip.begin() + i);
			i--;
		}
	}
}