#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int64_t input1, input2, output;

	while (cin >> input1 >> input2) {
		output = abs(input1 - input2);
		cout << output << endl;
	}

	return 0;
}