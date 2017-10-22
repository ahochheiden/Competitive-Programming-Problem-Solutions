#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

void calc();
void rotate();

int64_t n;
int64_t counter;

string input;
string output;

bool valid;

char inGrid[12][12];
char outGrid[12][12];
char tempGrid[12][12];
char tempChar;
char tempChar2;

int main()
{
	while(cin >> n)
	{
		counter = 0;
		valid = true;

		for(int64_t i = 0; i < n; i++)
		{
			for(int64_t j = 0; j < n; j++)
			{
				cin >> inGrid[i][j];
				outGrid[i][j] = '!'; // invalid grille case
			}
		}

		cin >> input;

		calc();
		rotate();
		calc();
		rotate();
		calc();
		rotate();
		calc();

		output = "";

		for(int64_t i = 0; i < n && valid; i++)
		{
			for(int64_t j = 0; j < n && valid; j++)
			{
				tempChar = outGrid[i][j];

				if(tempChar != '!')
				{
					output += tempChar;
				}
				else
				{
					valid = false;
				}
			}
		}

		if(valid)
		{
			cout << output << endl;
		}
		else
		{
			cout << "invalid grille" << endl;
		}
	}

	return 0;
}

void calc()
{
	for(int64_t i = 0; i < n && valid; i++)
	{
		for(int64_t j = 0; j < n && valid; j++)
		{
			tempChar = inGrid[i][j];
			tempChar2 = outGrid[i][j];

			if((tempChar == '.'))
			{
				outGrid[i][j] = input[counter++];

				if(tempChar2 != '!')
				{
					valid = false;
				}
			}
		}
	}
}

void rotate()
{
	for(int64_t i = 0; i < n; i++)
	{
		for(int64_t j = 0; j < n; j++)
		{
			tempGrid[i][j] = inGrid[n - 1 - j][i];
		}
	}

	for(int64_t i = 0; i < n; i++)
	{
		for(int64_t j = 0; j < n; j++)
		{
			inGrid[i][j] = tempGrid[i][j];
		}
	}
}