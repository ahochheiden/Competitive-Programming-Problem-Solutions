#include <iostream>
#include <cstdint>

using namespace std;

int64_t b;
int64_t p;
int64_t m;

int64_t bigMod(int64_t b, int64_t p, int64_t m);

int main() {
	while (cin >> b >> p >> m) {
		cout << bigMod(b, p, m) << endl;
	}

	return 0;
}

int64_t bigMod(int64_t b, int64_t p, int64_t m) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		int temp = bigMod(b, (p / 2), m);
		return (temp * temp) % m;
	} else {
		return (b % m * bigMod(b, (p - 1), m)) % m;
	}
}