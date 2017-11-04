#include <iostream>
#include <string>
#include <map>
#include <assert.h>

using namespace std;

const int MAX_N = 501;

bool isA[MAX_N][MAX_N];
bool hasA[MAX_N][MAX_N];

const string isAString = "is-a";
const string hasAString = "has-a";

map<string, int> idMap;

void prepare()
{
	for(int i = 0; i < MAX_N; i++)
	{
		for(int j = 0; j < MAX_N; j++)
		{
			isA[i][j] = false;
		}
	}

	for(int i = 0; i < MAX_N; i++)
	{
		isA[i][i] = true;
	}
}

int classNameToID(const string& className)
{
	static int count = 0;

	if(!(idMap.count(className)))
	{
		idMap.insert(pair<string, int>(className, count++));
	}

	return idMap[className];
}

int main()
{
	prepare();

	// parse input
	int n, m;
	
	cin >> n >> m;

	string class1, class2, relationship;

	int id1, id2;

	for(int i = 0; i < n; i++)
	{
		cin >> class1 >> relationship >> class2;

		id1 = classNameToID(class1);
		id2 = classNameToID(class2);

		if(relationship == isAString)
		{
			isA[id1][id2] = true;
		}
		else
		{
			if(relationship == hasAString)
			{
				hasA[id1][id2] = true;
			}
			else
			{
				// programming error, should never happen
				assert(false);
			}
		}
	}

	// process isA
	for(int k = 0; k < MAX_N; ++k)
	{
		for(int i = 0; i < MAX_N; ++i)
		{
			for(int j = 0; j < MAX_N; ++j)
			{
				isA[i][j] = isA[i][j] || (isA[i][k] && isA[k][j]);
			}
		}
	}

	// process hasA
	for(int k = 0; k < MAX_N; ++k)
	{
		for(int i = 0; i < MAX_N; ++i)
		{
			for(int j = 0; j < MAX_N; ++j)
			{
				hasA[i][j] = hasA[i][j] || (hasA[i][k] && hasA[k][j]);
				hasA[i][j] = hasA[i][j] || (isA[i][k] && hasA[k][j]);
				hasA[i][j] = hasA[i][j] || (hasA[i][k] && isA[k][j]);
			}
		}
	}
	
	bool queryStatus;

	// output
	for(int i = 1; i <= m; i++)
	{
		cin >> class1 >> relationship >> class2;

		id1 = classNameToID(class1);
		id2 = classNameToID(class2);

		if(relationship == isAString)
		{
			queryStatus = isA[id1][id2];
		}
		else
		{
			if(relationship == hasAString)
			{
				queryStatus = hasA[id1][id2];
			}
			else
			{
				// programming error, should never happen
				assert(false);
			}
		}

		cout << "Query " << i << ": " << (queryStatus ? "true" : "false") << endl;
	}

	return 0;
}