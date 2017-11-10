#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_SIZE = 1504;

char board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

const int dx[4] = {1, 0, -1,  0};
const int dy[4] = {0, 1,  0, -1};

void reset()
{
	memset(board, '0', sizeof(board));
	memset(visited, false, sizeof(visited));
	memset(dist, 999999, sizeof(dist));
}

int main()
{
	reset();

	int n;
	
	cin >> n;

	queue<int> bfs;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> board[i][j];

			if(board[i][j] == '3')
			{
				dist[i][j] = 0;
				bfs.push(i);
				bfs.push(j);
			}
		}
	}

	int answer = 0;

	while(!bfs.empty())
	{
		int x = bfs.front(); bfs.pop();
		int y = bfs.front(); bfs.pop();

		if(visited[x][y] == true)
		{
			continue;
		}

		visited[x][y] = true;
		
		if(board[x][y] == '1')
		{
			answer = max(answer, dist[x][y]);
		}

		for(int i = 0; i < 4; i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];

			if(newX < 0 || newX >= n || newY < 0 || newY >= n)
			{
				continue;
			}

			dist[newX][newY] = min(dist[newX][newY], (dist[x][y] + 1));

			if(visited[newX][newY] == false)
			{
				bfs.push(newX);
				bfs.push(newY);
			}
		}
	}

	cout << answer << endl;

	return 0;
}