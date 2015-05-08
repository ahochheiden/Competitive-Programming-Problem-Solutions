#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int64_t bottles[9];
int64_t moves[6];
int64_t minMoves;

string output;
const string combinations[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

void solve();
int64_t countMoves(int64_t a, int64_t b, int64_t c);

int main() {
	while (cin >> bottles[0] >> bottles[1] >> bottles[2] >> bottles[3] >> bottles[4] >> bottles[5] >> bottles[6] >> bottles[7] >> bottles[8]) {
		solve();
	}

	return 0;
}

void solve() {
	moves[0] = countMoves(0, 5, 7); // BCG
	moves[1] = countMoves(0, 4, 8); // BGC
	moves[2] = countMoves(2, 3, 7); // CBG
	moves[3] = countMoves(2, 4, 6); // CGB
	moves[4] = countMoves(1, 3, 8); // GBC
	moves[5] = countMoves(1, 5, 6); // GCB

	minMoves = moves[0];
	output = combinations[0];

	for (int64_t i = 1; i < 6; i++) {
		if (moves[i] < minMoves) {
			minMoves = moves[i];
			output = combinations[i];
		}
	}

	cout << output << ' ' << minMoves << endl;
}

int64_t countMoves(int64_t a, int64_t b, int64_t c) {
	int64_t numMoves = 0;
	for (int64_t i = 0; i < 9; i++) {
		if ((i != a) && (i != b) && (i != c))
			numMoves += bottles[i];
	}

	return numMoves;
}