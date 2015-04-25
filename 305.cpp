#include <iostream>
#include <cstdint>

using namespace std;

int64_t ans[15] = {0};

void _calc();

int main() {
	int64_t input;

	_calc();

	while (cin >> input) {
		if ((input != 0) && (input < 14)) {
			cout << ans[input] << endl;
		}
	}

	return 0;
}

void _calc() {
	int64_t num, bad, pos;
	bool success;

	for (int64_t k = 1; k < 14; k++) {
		num = k + 1;
		success = false;

		if (k > 1) {
			while (!success) {
				bad = k;
				pos = 0;

				while (true) {
					pos = ((num + pos) % (k + bad)) + 1;
					if ((k < pos) && (0 < bad)) {
						bad--;
						pos--;
					} else {
						break;
					}

					if (bad == 0) {
						success = true;
						break;
					}
				}
				num++;
			}
			ans[k] = num;
		} else {
			ans[k] = 2;
		}
	}
}