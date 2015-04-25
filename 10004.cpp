#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

void solve();
void calc();

int64_t numNodes;
int64_t numEdges;
int64_t neighbour1;
int64_t neighbour2;

vector<vector<int64_t> > adjacencyList;

bool bipartite;

int main() {
	while (cin >> numNodes) {
		if (numNodes) {
			solve();
		} else {
			break;
		}
	}

	return 0;
}

void solve() {
	adjacencyList.clear();
	adjacencyList.assign(numNodes, vector<int64_t>());

	cin >> numEdges;

	for (int64_t i = 0; i < numEdges; i++) {
		cin >> neighbour1 >> neighbour2;
		adjacencyList[neighbour1].push_back(neighbour2);
		adjacencyList[neighbour2].push_back(neighbour1);
	}

	calc();

	if (bipartite)
		cout << "BICOLORABLE." << endl;
	else
		cout << "NOT BICOLORABLE." << endl;
}

void calc() {
	queue<int64_t> countryQueue;
	countryQueue.push(0);
	vector<int64_t> color(numNodes, -1);
	color[0] = 0;

	bipartite = true;

	while (!countryQueue.empty() && bipartite) {
		neighbour1 = countryQueue.front();
		countryQueue.pop();
		for (int64_t i = 0; i < (int64_t)adjacencyList[neighbour1].size(); i++) {
			neighbour2 = adjacencyList[neighbour1][i];
			if (color[neighbour2] == -1) {
				color[neighbour2] = 1 - color[neighbour1];
				countryQueue.push(neighbour2);
			} else if (color[neighbour2] == color[neighbour1]) {
				bipartite = false;
				break;
			}
		}
	}
}