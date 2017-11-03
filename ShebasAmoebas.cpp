#include <iostream>

using namespace std;

const int MAX_SIZE = 102;

char grid[MAX_SIZE][MAX_SIZE];

const int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

bool connection(int& x, int& y)
{
	for(int i = 0; i < 8; i++)
	{
		bool isConnected = grid[x + dx[i]][y + dy[i]] == '#';

		if(isConnected)
		{
			x += dx[i];
			y += dy[i];

			return true;
		}
	}

	return false;
}

int main()
{
	// reset
	for(int i = 0; i < MAX_SIZE; i++)
	{
		for(int j = 0; j < MAX_SIZE; j++)
		{
			grid[i][j] = '.';
		}
	}

	int m, n;

	cin >> m >> n;

	// input
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> grid[i][j];
		}
	}

	// process
	int count = 0;

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(grid[i][j] == '#')
			{
				count++;

				int currX = i;
				int currY = j;

				while(true)
				{
					if(connection(currX, currY))
					{
						grid[currX][currY] = '.';
					}
					else
					{
						break;
					}
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}