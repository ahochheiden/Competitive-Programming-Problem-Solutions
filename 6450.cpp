#include <iostream>
#include <cstdint>
#include <queue>
#include <unordered_set>

using namespace std;

const uint32_t MAX_N = 21;

void solve();
uint32_t hammingWeight(uint32_t value);

int main()
{
	uint32_t numCases;

	cin >> numCases;

	while(numCases--)
	{
		solve();
	}

	return 0;
}

void solve()
{
	uint32_t fullCoverage = 0;	
	uint32_t socialNetwork[MAX_N];
	uint32_t n;

	cin >> n;

	uint32_t d;
	uint32_t connection;

	for(uint32_t i = 1; i <= n; i++)
	{
		fullCoverage |= (1 << i);

		cin >> d;

		socialNetwork[i] = (1 << i);

		for(uint32_t j = 0; j < d; j++)
		{
			cin >> connection;

			socialNetwork[i] |= (1 << connection);
		}
	}

	queue<uint32_t> bfs;

	bfs.push(0);
	bfs.push(0);

	unordered_set<uint32_t> visited;

	while(!bfs.empty())
	{
		uint32_t currentCombination = bfs.front();
		bfs.pop();

		uint32_t currentCoverage = bfs.front();
		bfs.pop();

		for(uint32_t i = 1; i <= n; i++)
		{
			uint32_t newCombination = currentCombination | (1 << i);

			if(visited.count(newCombination))
			{
				continue;
			}

			uint32_t newCoverage = currentCoverage | socialNetwork[i];

			if(newCoverage == fullCoverage)
			{
				cout << hammingWeight(newCombination) << endl;

				return;
			}

			visited.insert(newCombination);

			bfs.push(newCombination);
			bfs.push(newCoverage);
		}
	}
}

uint32_t hammingWeight(uint32_t value)
{
	uint32_t output = 0;

	while(value > 0)
	{
		if((value & 1) == 1)
		{
			output++;
		}

		value >>= 1;
	}

	return output;
}