#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int main() {
	int64_t input = -1;
	int64_t temp = 0;

	while (input != 0) {
		cin >> input;
		if (input != 0) {
			temp = sqrt(input);

			if (input == temp * temp) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}

	return 0;
}