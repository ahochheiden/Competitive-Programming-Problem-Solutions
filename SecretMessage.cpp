#include <iostream>
#include <cmath>
#include <string>
#include <cctype>

using namespace std;

const int MAX_SIZE = 101;

int table[MAX_SIZE];
char inputTable[MAX_SIZE][MAX_SIZE];

void generateSquares()
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		table[i] = i*i;
	}
}

int findM(int L)
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		if(table[i] >= L)
		{
			return table[i];
		}
	}
}

void populateTable(const string& message, const int& K)
{
	int pos = 0;

	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < K; j++)
		{
			inputTable[i][j] = message[pos++];
		}
	}
}

void outputTable(const int& K)
{
	for(int i = 0; i < K; i++)
	{
		for(int j = K - 1; j >= 0; j--)
		{
			char character = inputTable[j][i];

			if(isalpha(character))
			{
				cout << character;
			}
			else
			{
				continue;
			}
		}
	}

	cout << endl;
}

int main()
{
	generateSquares();

	int count = 0;

	cin >> count;

	string garbage;

	getline(cin, garbage);

	string message;

	for(int i = 0; i < count; i++)
	{
		getline(cin, message);

		int L = message.size();

		int M = findM(L);

		int padding = M - L;

		for(int j = 0; j < padding; j++)
		{
			message += '*';
		}

		int K = static_cast<int>(sqrt(M));

		populateTable(message, K);

		outputTable(K);
	}

	return 0;
}