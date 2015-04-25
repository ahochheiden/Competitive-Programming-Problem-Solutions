#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main() {
	string input = "";

	while (getline(cin, input)) {
		for (int64_t i = 0; i < input.size(); i++) {
			input.at(i) = (input.at(i) - 7);
		}
		cout << input << endl;
	}

	return 0;
}