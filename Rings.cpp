#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
void print64_t();
bool adjacentIsEmpty(int64_t row, int64_t col);

int64_t counter;
int64_t rows;
int64_t cols;
int64_t grid[110][110];
int64_t temp[110][110];
int64_t outGrid[110][110];

char tempChar;

vector<int64_t> dirs(4);

int main()
{
	for(int64_t i = 0; i < 110; i++)
	{
		for(int64_t j = 0; j < 110; j++)
		{
			grid[i][j] = -9999;
		}
	}

	while(cin >> rows >> cols)
	{
		for(int64_t i = 1; i <= rows; i++)
		{
			for(int64_t j = 1; j <= cols; j++)
			{
				cin >> tempChar;

				if(tempChar != '.')
				{
					grid[i][j] = tempChar;
				}
				else
				{
					grid[i][j] = -9999;
				}

				outGrid[i][j] = -9999;
			}
		}

		solve();
		print64_t();
	}

	return 0;
}

void print64_t()
{
	int64_t numRings = 0;

	for(int64_t i = 1; i <= rows; i++)
	{
		for(int64_t j = 1; j <= cols; j++)
		{
			numRings = max(numRings, outGrid[i][j]);
		}
	}

	for(int64_t i = 1; i <= rows; i++)
	{
		for(int64_t j = 1; j <= cols; j++)
		{
			int64_t temp = outGrid[i][j];

			if(temp < 0)
			{
				if(numRings < 10)
				{
					cout << "..";
				}
				else
				{
					cout << "...";
				}
			}
			else
			{
				if(numRings >= 10)
				{
					if(temp < 100)
					{
						if(temp < 10)
						{
							// range 1-9
							cout << ".." << temp;

						}
						else
						{
							// range 10-99
							cout << "." << temp;
						}
					}
					else
					{
						// range 100+
						cout << temp;
					}
				}
				else
				{
					if(temp < 10)
					{
						// range 1-9
						cout << "." << temp;
					}
					else
					{
						// range 10-99
						cout << temp;
					}
				}
			}
		}
		cout << endl;
	}
}

void solve()
{
	counter = 1;

	while(true)
	{
		bool elementFound = false;
		for(int64_t i = 1; i <= rows; i++)
		{
			for(int64_t j = 1; j <= cols; j++)
			{
				if(grid[i][j] == 'T')
				{
					elementFound = true;
					if(adjacentIsEmpty(i, j))
					{
						temp[i][j] = -9999;
						outGrid[i][j] = counter;
					}
					else
					{
						temp[i][j] = grid[i][j];
						continue;
					}
				}
				else
				{
					temp[i][j] = grid[i][j];
					continue;
				}
			}
		}

		if(!elementFound)
		{
			break;
		}

		counter++;

		for(int64_t i = 1; i <= rows; i++)
		{
			for(int64_t j = 1; j <= cols; j++)
			{
				grid[i][j] = temp[i][j];
			}
		}
	}
}

bool adjacentIsEmpty(int64_t row, int64_t col)
{
	if((grid[row][col + 1] < 0) || // right
		(grid[row + 1][col] < 0) || // down
		(grid[row - 1][col] < 0) || // up
		(grid[row][col - 1] < 0)) // left
	{
		return true;
	}
	else
	{
		return false;
	}
}
