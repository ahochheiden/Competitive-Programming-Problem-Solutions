#include <iostream>
#include <cstdint>

using namespace std;

int64_t loops;
int64_t bx;
int64_t by;
int64_t x;
int64_t y;

int main() {
	while (cin >> loops) {
		cin >> bx >> by;
		for (int64_t i = 0; i < loops; i++) {
			cin >> x >> y;
			if ((bx == x) || (by == y)) {
				cout << "divisa" << endl;
			} else {
				if ((x < bx) && (y < by)) {
					cout << "SO" << endl;
				} else {
					if ((x > bx) && (y < by)) {
						cout << "SE" << endl;
					} else {
						if ((x > bx) && (y > by)) {
							cout << "NE" << endl;
						} else {
							if ((x < bx) && (y > by)) {
								cout << "NO" << endl;
							}
						}
					}
				}
			}
		}
	}

	return 0;
}