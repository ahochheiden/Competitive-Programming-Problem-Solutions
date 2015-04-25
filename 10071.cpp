#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int64_t input1;
	int64_t input2;
	int64_t output;

	while (cin >> input1 >> input2) {
		output = (2 * input1 * input2);
		cout << output << endl;
	}

	return 0;
}