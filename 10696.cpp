#include <iostream>
#include <cstdint>

using namespace std;

int64_t input;

int64_t f91(int64_t num);

int main() {
	while (cin >> input) {
		if (input == 0) {
			break;
		}
		cout << "f91(" << input << ") = " << f91(input) << endl;
	}
	
	return 0;
}

int64_t f91(int64_t num) {
	if (num <= 100) {
		return f91(f91(num + 11));
	} else {
		return num - 10;
	}
}