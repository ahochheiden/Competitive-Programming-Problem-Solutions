#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void _solve();

int64_t numInput;
int64_t temp;

vector<int64_t> numbers;

int main() {
	while (cin >> numInput) {
		if (numInput != 0) {
			_solve();
		}
	}

	return 0;
}

void _solve() {
	numbers.clear();
	numbers.reserve(numInput);

	for (int64_t i = 0; i < numInput; i++) {
		cin >> temp;
		if (temp != 0) {
			numbers.push_back(temp);
		}
	}

	if (numbers.size() == 0) {
		cout << 0 << endl;
	} else {
		for (int64_t i = 0; i < numbers.size(); i++) {
			cout << numbers[i];
			if ((i + 1) != numbers.size()) {
				cout << " ";
			}
		}
		cout << endl;
	}
}