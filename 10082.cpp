#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

void _replace(char &c);

int main() {
	string input;
	while (getline(cin, input)) {
		for (int64_t i = 0; i < input.size(); i++) {
			_replace(input.at(i));
		}
		cout << input << endl;
	}

	return 0;
}

void _replace(char &c) {
	string keys = "`1234567890-=QWERTYUIOP[]\\_ASDFGHJKL;'ZXCVBNM,./";

	for (int64_t i = 1; i < keys.size(); i++) {
		if (keys.at(i) == c) {
			c = keys.at(i - 1);
			break;
		}
	}
}
