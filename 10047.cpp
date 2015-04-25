#include <iostream>
#include <cstring>
#include <queue>
#include <cstdint>

using namespace std;

struct Node {
	int64_t x;
	int64_t y;
	int64_t dir;
	int64_t colour;
	int64_t time;

	Node(int64_t xIn, int64_t yIn, int64_t dIn, int64_t cIn, int64_t tIn) {
		x = xIn;
		y = yIn;
		dir = dIn;
		colour = cIn;
		time = tIn;
	}
};

char grid[30][30];
int64_t dx[] = {0, 1, 0, -1};
int64_t dy[] = {-1, 0, 1, 0};
int64_t status[30][30][5][5];

int64_t caseCount = 0;
int64_t numRows;
int64_t numCols;
int64_t answer;

void solve();
void calc(queue<Node> nodeQueue);

int main() {
	while (cin >> numRows >> numCols) {
		if (numRows && numCols) {
			solve();
		} else {
			break;
		}
	}

	return 0;
}

void solve() {
	answer = 0;
	memset(status, 0, sizeof status);
	queue<Node> nodeQueue;

	for (int64_t i = 1; i <= numRows; ++i) {
		for (int64_t j = 1; j <= numCols; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'S')
				nodeQueue.push(Node(i, j, 0, 0, 0));
		}
	}

	if (caseCount) {
		cout << endl;
	}

	calc(nodeQueue);

	cout << "Case #" << ++caseCount << endl;
	if (answer) {
		cout << "minimum time = " << answer << " sec" << endl;
	} else {
		cout << "destination not reachable" << endl;
	}
}

void calc(queue<Node> nodeQueue) {
	while (!(nodeQueue.empty())) {
		Node temp = nodeQueue.front();
		nodeQueue.pop();

		if (status[temp.x][temp.y][temp.dir][temp.colour]) {
			continue;
		}

		if (grid[temp.x][temp.y] == '#') {
			continue;
		}
		if (grid[temp.x][temp.y] == 'T' && temp.colour == 0) {
			answer = temp.time;
			break;
		}
		status[temp.x][temp.y][temp.dir][temp.colour] = 1;
		if (!((temp.x + dy[temp.dir] < 1) || (temp.x + dy[temp.dir] > numRows) || (temp.y + dx[temp.dir] < 1) || (temp.y + dx[temp.dir] > numCols))) {
			nodeQueue.push(Node(temp.x + dy[temp.dir], temp.y + dx[temp.dir], temp.dir, (temp.colour + 1) % 5, temp.time + 1));
		}
		nodeQueue.push(Node(temp.x, temp.y, (temp.dir + 1) % 4, temp.colour, temp.time + 1));
		nodeQueue.push(Node(temp.x, temp.y, (temp.dir + 3) % 4, temp.colour, temp.time + 1));
	}
}