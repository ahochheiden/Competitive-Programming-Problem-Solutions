#include <iostream>
#include <cstdint>

using namespace std;

int64_t numCases;
int64_t sum;
int64_t diff;
int64_t output;

int64_t score1;
int64_t score2;

int main() {
	cin >> numCases;

	for (uint64_t i = 0; i < numCases; i++) {
		cin >> sum >> diff;

		if ((sum < diff) || (((sum - diff) % 2) != 0)) {
			cout << "impossible" << endl;
		} else {
			score2 = ((sum - diff) / 2);
			score1 = (score2 + diff);

			cout << score1 << " " << score2 << endl;
		}
	}

	return 0;
}