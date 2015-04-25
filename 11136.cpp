#include <iostream>
#include <set>
#include <cstdint>

using namespace std;

multiset<int64_t> urn;

int64_t n, k, bill, output = 0;

int main() {
	while (cin >> n) {
		urn.clear();
		output = 0;

		if (n == 0) {
			break;
		} else {
			for (int64_t i = 0; i < n; i++) {
				cin >> k;
				for (int64_t j = 0; j < k; j++) {
					cin >> bill;
					urn.insert(bill);
				}
				output += *--urn.end() - *urn.begin();

				urn.erase(--urn.end());
				urn.erase(urn.begin());
			}
			cout << output << endl;
		}
	}

	return 0;
}
