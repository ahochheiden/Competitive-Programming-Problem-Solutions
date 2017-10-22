#include <iostream>
#include <cstdint>

using namespace std;

void calc();
void resetGraph();

uint64_t n; // # users
uint64_t m; // # of links between users
uint64_t s; // index of initially infected user
uint64_t t; // number of minutes

uint64_t x;
uint64_t y;

uint64_t answer;

bool graph[110][110];
uint64_t answers[110][15];

int main()
{
	while(cin >> n >> m >> s >> t)
	{
		answer = 0;

		resetGraph();

		for(uint64_t i = 0; i < m; i++)
		{
			cin >> x >> y;
			graph[x][y] = true;
			graph[y][x] = true;
		}

		calc();

		cout << answer << endl;
	}

	return 0;
}

void calc()
{
	// reset answers
	for(uint64_t i = 0; i < n; i++)
	{
		for(uint64_t j = 0; j < t + 1; j++)
		{
			answers[i][j] = 0;
		}
	}

	// first receive
	for(uint64_t i = 0; i < n; i++)
	{
		if(graph[s][i] == true)
		{
			answers[i][1] = 1;
		}
	}

	// process
	for(uint64_t k = 2; k <= t + 1; k++) // k = answers column
	{
		for(uint64_t i = 0; i < n; i++) // i = answers rows
		{
			if(answers[i][k - 1] > 0)
			{
				for(uint64_t j = 0; j < n; j++) // j = possible connection with i
				{
					if(graph[i][j] == true)
					{
						answers[j][k] += answers[i][k - 1]; // add squawks sent to connected node(s)
					}
				}
			}
		}
	}

	for(uint64_t i = 0; i < n; i++) // i = answers row
	{
		answer += answers[i][t];
	}
}

void resetGraph()
{
	for(uint64_t i = 0; i < 110; i++)
	{
		for(uint64_t j = 0; j < 110; j++)
		{
			graph[i][j] = false;
		}
	}
}