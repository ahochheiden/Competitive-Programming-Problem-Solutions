#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

void solve();
void calc();

int64_t numRows;
int64_t numCols;
int64_t counter = 0;
int64_t field[105][105];

const int64_t di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int64_t dj[] = {0, -1, 0, 1, -1, 1, 1, -1};

int main() {
	while (cin >> numRows >> numCols) {
		if ((numRows == 0) && (numCols == 0)) {
			break;
		} else {
			solve();
		}
	}

	return 0;
}

void solve() {
	string temp;

	for (int64_t i = 1; i <= numRows; i++) {
		cin >> temp;
		for (int64_t j = 1; j <= numCols; j++) {
			if (temp[j - 1] == '.') {
				field[i][j] = 0;
			} else {
				field[i][j] = -100;
			}
		}
	}

	calc();

	counter++;

	if (counter > 1) {
		cout << endl;
	}

	cout << "Field #" << counter << ":" << endl;
	for (int64_t i = 1; i <= numRows; i++) {
		for (int64_t j = 1; j <= numCols; j++) {
			if (field[i][j] >= 0) {
				cout << field[i][j];
			} else {
				cout << '*';
			}
		}
		cout << endl;
	}
}

void calc() {
	for (int64_t i = 1; i <= numRows; i++) {
		for (int64_t j = 1; j <= numCols; j++) {
			if (field[i][j] < 0) {
				for (int64_t k = 0; k < 8; k++) {
					field[i + di[k]][j + dj[k]]++;
				}
			}
		}
	}
}