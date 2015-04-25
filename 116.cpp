#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

void solve();
void calc();

int64_t numRows;
int64_t numCols;

int64_t input[21][111];
int64_t sum[21][111];
int64_t path[111];
int64_t output;

int64_t up;
int64_t center;
int64_t down;

pair<int64_t, int64_t> upPair;
pair<int64_t, int64_t> centerPair;
pair<int64_t, int64_t> downPair;

int main() {
	while (cin >> numRows >> numCols) {
		if ((numRows != 0) && (numCols != 0)) {
			solve();
		}
	}

	return 0;
}

void solve() {
	for (int64_t i = 0; i < 21; i++) {
		fill(input[i], input[i] + 111, 0);
		fill(sum[i], sum[i] + 111, 0);
	}

	fill(path, path + 111, 0);

	for (int64_t i = 0; i < numRows; i++) {
		for (int64_t j = 0; j < numCols; j++) {
			cin >> input[i][j];
		}
	}
	for (int64_t i = 0; i < numRows; i++) {
		sum[i][(numCols - 1)] = input[i][(numCols - 1)];
	}

	calc();

	for (int64_t i = 0; i < numCols; i++) {
		if (i) {
			cout << " ";
		}
		cout << (path[i] + 1);
	}
	cout << endl << output << endl;
}

void calc() {
	for (int64_t j = numCols - 2; j >= 0; j--) {
		for (int64_t i = 0; i < numRows; i++) {
			up = sum[(i + numRows - 1) % numRows][j + 1];
			center = sum[i][j + 1];
			down = sum[(i + numRows + 1) % numRows][j + 1];
			sum[i][j] = min(up, min(center, down)) + input[i][j];
		}
	}

	output = sum[0][0];
	for (int64_t i = 1; i < numRows; i++) {
		if (sum[i][0] < output) {
			output = sum[i][0];
			path[0] = i;
		}
	}

	for (int64_t j = 1; j < numCols; j++) {
		upPair.first = sum[(path[j - 1] + numRows - 1) % numRows][j];
		upPair.second = ((path[j - 1] + numRows - 1) % numRows);

		centerPair.first = sum[path[j - 1]][j];
		centerPair.second = (path[j - 1]);

		downPair.first = sum[(path[j - 1] + numRows + 1) % numRows][j];
		downPair.second = ((path[j - 1] + numRows + 1) % numRows);

		int64_t tempMin = min(upPair.first, min(centerPair.first, downPair.first));

		vector<pair<int64_t, int64_t> > lexo;
		if (tempMin == upPair.first) {
			lexo.push_back(upPair);
		}
		if (tempMin == centerPair.first) {
			lexo.push_back(centerPair);
		}
		if (tempMin == downPair.first) {
			lexo.push_back(downPair);
		}
		int64_t lexoMin = lexo.at(0).second;
		for (int64_t k = 1; k < lexo.size(); k++) {
			if (lexo[k].second < lexoMin) {
				lexoMin = lexo[k].second;
			}
		}
		path[j] = lexoMin;
	}
}