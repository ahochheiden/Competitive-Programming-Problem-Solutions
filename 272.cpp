#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
	string input;
	int64_t count = 0;

	while (getline(cin, input)) {
		for (int64_t i = 0; i < input.size(); i++) {
			if (count % 2 == 0) {
				if (input.at(i) == '"') {
					input.at(i) = '`';
					input.insert((input.begin() + i), '`');
					count++;
				}
			} else {
				if (input.at(i) == '"') {
					input.at(i) = static_cast<char>(39);
					input.insert((input.begin() + i), static_cast<char>(39));
					count++;
				}
			}
		}
		cout << input << endl;
	}

	return 0;
}