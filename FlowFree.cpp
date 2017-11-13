#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

const int GRID_SIZE = 4;
const int NUM_POSSIBLE_DIRECTIONS = 4;

const int dx[NUM_POSSIBLE_DIRECTIONS] = {1, 0, -1,  0};
const int dy[NUM_POSSIBLE_DIRECTIONS] = {0, 1,  0, -1};

struct state
{
	int x;
	int y;
	int colorsLeft;
	vector<vector<int>> table;

	state(vector<vector<int>> tableIn, int colorsLeftIn)
	{
		table = tableIn;
		colorsLeft = colorsLeftIn;

		setStartXY();
	}

	int targetColorIndex() const
	{
		return colorsLeft - 1;
	}

	int targetColor() const
	{
		return table[targetColorIndex()][4];
	}

	void setStartXY()
	{
		x = table[targetColorIndex()][5];
		y = table[targetColorIndex()][6];
	}

	bool endIsReached()
	{
		bool xReached = table[targetColorIndex()][7] == x;
		bool yReached = table[targetColorIndex()][8] == y;

		if(xReached && yReached)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void setNewTarget()
	{
		colorsLeft--;

		if(colorsLeft != 0)
		{
			setStartXY();
		}
	}

	void addDxDy(const int& index)
	{
		x = x + dx[index];
		y = y + dy[index];
	}

	bool coordinateOutOfBounds() const
	{
		if(x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool allColorsReached() const
	{
		return colorsLeft == 0;
	}

	bool allCellsAreNotW() const
	{
		for(int i = 0; i < GRID_SIZE; i++)
		{
			for(int j = 0; j < GRID_SIZE; j++)
			{
				if(table[i][j] == 'W')
				{
					return false;
				}
			}
		}

		return true;
	}

	bool canColor() const
	{
		return table[x][y] == 'W';
	}

	void colorCurrentXY()
	{
		table[x][y] = targetColor();
	}
};

bool solve(const state& initialState);

int main()
{
	vector<vector<int>> input(GRID_SIZE, vector<int>(9));
	map<char, int> colors;
	char temp;

	for(int i = 0; i < GRID_SIZE; i++)
	{
		for(int j = 0; j < GRID_SIZE; j++)
		{
			cin >> temp;
			input[i][j] = temp;

			if(temp != 'W')
			{
				if(colors.count(temp))
				{
					int colorIndex = colors[temp];

					input[colorIndex][7] = i;
					input[colorIndex][8] = j;
				}
				else
				{
					colors.insert(make_pair(temp, colors.size()));

					int colorIndex = colors[temp];

					input[colorIndex][4] = temp;
					input[colorIndex][5] = i;
					input[colorIndex][6] = j;
				}
			}
		}
	}

	state initialState(input, colors.size());

	if(solve(initialState))
	{
		cout << "solvable";

	}
	else
	{
		cout << "not solvable";
	}

	return 0;
}

bool solve(const state& initialState)
{
	stack<state> dfs;

	dfs.push(initialState);

	while(!dfs.empty())
	{
		const state topState = dfs.top(); dfs.pop();

		for(int k = 0; k < NUM_POSSIBLE_DIRECTIONS; k++)
		{
			state currentState(topState);

			currentState.addDxDy(k);

			if(currentState.coordinateOutOfBounds())
			{
				continue;
			}

			if(currentState.endIsReached())
			{
				currentState.setNewTarget();

				if(currentState.allColorsReached())
				{
					if(currentState.allCellsAreNotW())
					{
						return true;
					}
				}
				else
				{
					dfs.push(currentState);
					continue;
				}
			}

			if(currentState.canColor())
			{
				currentState.colorCurrentXY();

				dfs.push(currentState);
			}
		}
	}

	return false;
}