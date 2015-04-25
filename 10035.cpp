#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int64_t num1, num2, carries, carry;

	while (cin >> num1 >> num2) {
		if (num1 == 0 && num2 == 0) {
			break;
		}

		carries = 0;
		carry = 0;

		while (num1 > 0 || num2 > 0) {
			carry = (num1 % 10 + num2 % 10 + carry) / 10;
			num1 /= 10;
			num2 /= 10;

			if (carry) {
				carries++;
			}
		}

		if (carries == 0) {
			cout << "No carry operation." << endl;
		} else {
			if (carries == 1) {
				cout << "1 carry operation." << endl;
			} else {
				cout << carries << " carry operations." << endl;
			}
		}
	}

	return 0;
}