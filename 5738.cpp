#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Coord
{
	int row;
	int column;
	int direction;

	Coord(int rowInput, int columnInput, int directionInput)
	{
		row = rowInput;
		column = columnInput;
		direction = directionInput;
	}
};

const int rowDir[4] = {-1, 0, 1, 0};
const int colDir[4] = {0, 1, 0, -1};

int distances[1000][1000][4];
int paths[1000][1000][4];

string planetMap[1000];
string temp;

int caseCount = 0;
int numRows;
int numColumns;
int mod;
int sumRemainder = 0;
bool programExists;

pair<int, int> startCoord;
pair<int, int> destCoord;
char startDirection;

void solve();
int NESW(char &direction);
void BFS(queue<Coord> &coordQueue);
void pushCoord(queue<Coord> &coordQueue, Coord &current, Coord &next);

int main()
{
	while(cin >> numRows >> numColumns >> mod)
	{
		if(mod)
		{
			getline(cin, temp);
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
	sumRemainder = 0;
	programExists = false;

	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numColumns; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				distances[i][j][k] = -1;
				paths[i][j][k] = 0;
			}
		}
	}

	for(int i = 0; i < numRows; i++)
	{
		getline(cin, planetMap[i]);
	}

	cin >> startCoord.first >> startCoord.second >> destCoord.first >> destCoord.second >> startDirection;

	Coord start(startCoord.first, startCoord.second, NESW(startDirection));
	queue<Coord> coordQueue;

	coordQueue.push(start);
	distances[start.row][start.column][start.direction] = 0;
	paths[start.row][start.column][start.direction] = 1;

	BFS(coordQueue);

	for(int i = 0; i < 4; i++)
	{
		if(distances[destCoord.first][destCoord.second][i] >= 0)
		{
			sumRemainder += paths[destCoord.first][destCoord.second][i];
			sumRemainder %= mod;
			programExists = true;
		}
	}

	if(programExists)
	{
		cout << "Case " << ++caseCount << ": " << mod << ' ' << sumRemainder << endl;
	}
	else
	{
		cout << "Case " << ++caseCount << ": " << mod << ' ' << -1 << endl;
	}

}

int NESW(char &direction)
{
	switch(direction)
	{
		case 'N': return 0;
		case 'E': return 1;
		case 'S': return 2;
		case 'W': return 3;
	}
}

void BFS(queue<Coord> &coordQueue)
{
	while(!(coordQueue.empty()))
	{
		Coord current = coordQueue.front();	coordQueue.pop();

		if(current.row == destCoord.first)
		{
			if(current.column == destCoord.second)
			{
				break;
			}
		}

		Coord next = current;
		next.row += rowDir[current.direction];
		next.column += colDir[current.direction];

		if((0 <= next.row) && (next.row < numRows))
		{
			if((0 <= next.column) && (next.column < numColumns))
			{
				if(planetMap[next.row][next.column] != '*')
				{
					pushCoord(coordQueue, current, next);
				}
			}

		}

		next = current;
		next.direction = (next.direction + 3) % 4;

		pushCoord(coordQueue, current, next);

		next = current;
		next.direction = (next.direction + 1) % 4;

		pushCoord(coordQueue, current, next);
	}
}

void pushCoord(queue<Coord> &coordQueue, Coord &current, Coord &next)
{
	if(0 <= distances[next.row][next.column][next.direction])
	{
		if(distances[next.row][next.column][next.direction] < (distances[current.row][current.column][current.direction] + 1))
		{
			return;
		}
	}

	if(0 > distances[next.row][next.column][next.direction])
	{
		coordQueue.push(next);
	}

	paths[next.row][next.column][next.direction] += paths[current.row][current.column][current.direction];
	paths[next.row][next.column][next.direction] %= mod;
	distances[next.row][next.column][next.direction] = distances[current.row][current.column][current.direction] + 1;
}