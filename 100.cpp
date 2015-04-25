#include <iostream>
#include <cstdint>

using namespace std;

int64_t counter(int64_t input);
int64_t maxBetween(int64_t num1, int64_t num2);

int main() {
	int64_t input1 = 0;
	int64_t input2 = 0;

	while (cin >> input1 >> input2) {
		if (input1 >= input2) {
			cout << input1 << ' ' << input2 << ' ' << maxBetween(input2, input1) << endl;
		} else {
			cout << input1 << ' ' << input2 << ' ' << maxBetween(input1, input2) << endl;
		}
	}

	return 0;
}

int64_t counter(int64_t input) {
	int64_t count = 1;


	while (input != 1) {
		if (input % 2 == 1) {
			input = (3 * input) + 1;
		} else {
			input = (input / 2);
		}
		count++;
	}
	return count;
}

int64_t maxBetween(int64_t num1, int64_t num2) {
	int64_t max = 0;
	int64_t temp = 0;
	for (int64_t i = num1; i <= num2; i++) {
		temp = counter(i);
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}