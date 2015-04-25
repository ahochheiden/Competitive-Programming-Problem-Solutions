#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int64_t caseCount;
string input;
bool isSlurpy;
bool f;

void solve();
bool slump(int64_t a, int64_t b);
bool slimp(int64_t a, int64_t b);

int main() {
	cout << "SLURPYS OUTPUT" << endl;
	cin >> caseCount;

	for (int64_t i = 0; i < caseCount; i++) {
		solve();
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}

void solve() {
	isSlurpy = false;

	cin >> input;
	for (int64_t i = 0; i < input.size(); i++) {
		if (input[i] == 'C' || input[i] == 'H') {
			isSlurpy = slump(i + 1, input.size() - 1) && slimp(0, i);
			if (isSlurpy) {
				break;
			}
		}
	}

	if (isSlurpy) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

bool slump(int64_t a, int64_t b) {
	if (!(input[a] == 'D' || input[a] == 'E')) {
		return false;
	}

	f = false;

	for (int64_t i = a + 1; i <= b; i++) {
		if (input[i] != 'F') {
			if (!f) {
				return false;
			}
			if (input[i] == 'G' && i == b) {
				return true;
			}
			return slump(i, b);
		} else {
			f = true;
		}
	}

	return false;
}

bool slimp(int64_t a, int64_t b) {
	if (b - a + 1 == 2) {
		return input[a] == 'A' && input[a + 1] == 'H';
	}
	if (input[a] != 'A') {
		return false;
	}
	if (b - a + 1 <= 1) {
		return false;
	}
	if (input[b] != 'C') {
		return false;
	}
	if (slump(a + 1, b - 1)) {
		return true;
	}
	if (input[a + 1] != 'B') {
		return false;
	}
	return slimp(a + 2, b - 1);
}