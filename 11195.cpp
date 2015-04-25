#include <iostream>
#include <cstdint>

using namespace std;

void _solve();
void _calc(int64_t column, int64_t row, int64_t leftDiagonal, int64_t rightDiagonal);

char board[14][14];

int64_t numSolutions;
int64_t numQueens;
int64_t caseCounter = 1;

int main() {
	while (cin >> numQueens) {
		if (numQueens == 0) {
			break;
		} else {
			_solve();
		}
	}

	return 0;
}

void _solve() {
	numSolutions = 0;

	for (int64_t i = 0; i < numQueens; i++) {
		for (int64_t j = 0; j < numQueens; j++) {
			cin >> board[i][j];
		}
	}

	_calc(0, 0, 0, 0);

	cout << "Case " << caseCounter++ << ": " << numSolutions << endl;
}

void _calc(int64_t column, int64_t row, int64_t leftDiagonal, int64_t rightDiagonal) {
	if ((((1 << numQueens) - 1) & row) == ((1 << numQueens) - 1)) {
		numSolutions++;
	} else {
		int64_t position = ((1 << numQueens) - 1) & (~row & ~leftDiagonal & ~rightDiagonal);
		for (int64_t i = 0; i < numQueens; i++) {
			if ((position >> i) & (board[i][column] == '.')) {
				_calc((column + 1), (row | (1 << i)), ((leftDiagonal | (1 << i)) << 1), ((rightDiagonal | (1 << i)) >> 1));
			}
		}
	}
}