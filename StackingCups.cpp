#include<iostream>
#include <vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

vector<pair<int, string> > table;

int main()
{
	int N;

	while(cin >> N)
	{
		table.clear();

		string one, two;

		for(int i = 0; i < N; i++)
		{
			cin >> one >> two;

			if(isalpha(one[0]))
			{
				table.push_back(make_pair((stoi(two) * 2), one));
			}
			else
			{
				table.push_back(make_pair(stoi(one), two));
			}
		}

		sort(table.begin(), table.end());

		for(int i = 0; i < N; i++)
		{
			cout << table[i].second << endl;
		}
	}

	return 0;
}