#include <iostream>
#include <cstdint>

using namespace std;

const int64_t coins[5] = {50, 25, 10, 5, 1};
int64_t answers[7490];
int64_t input;

void calc();

int main() {
	calc();

	while (cin >> input) {
		cout << answers[input] << endl;
	}

	return 0;
}

void calc() {
	answers[0] = 1;

	for (int64_t i = 0; i < 5; i++) {
		for (int64_t j = coins[i]; j < 7490; j++) {
			answers[j] += answers[j - coins[i]];
		}
	}
}