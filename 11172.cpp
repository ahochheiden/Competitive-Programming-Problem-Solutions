#include <iostream>
#include <cstdint>

using namespace std;

int64_t count;
int64_t num1;
int64_t num2;

int main() {
	cin >> count;

	for (int64_t i = 0; i < count; i++) {
		cin >> num1 >> num2;
		if (num1 == num2) {
			cout << "=" << endl;
		} else {
			if (num1 < num2) {
				cout << "<" << endl;
			} else {
				cout << ">" << endl;
			}
		}
	}

	return 0;
}