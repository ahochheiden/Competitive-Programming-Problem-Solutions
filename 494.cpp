#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

string input;
int64_t output;
bool between;

int main() {
	while (getline(cin, input)) {
		input += ' ';
		output = 0;
		between = true;

		for (int i = 0; i < input.size(); i++) {
			if (isalpha(input[i])) {
				if (between) {
					output++;
					between = false;
				}
			} else {
				between = true;
			}
		}

		cout << output << endl;
	}

	return 0;
}