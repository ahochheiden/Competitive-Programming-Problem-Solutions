#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int64_t loops;
int64_t num;
int64_t temp;
int64_t count;
int64_t trains[52];

int main() {

	cin >> loops;
	for (int64_t i = 0; i < loops; i++) {
		count = 0;
		cin >> num;

		for (int64_t j = 0; j < num; j++) {
			cin >> trains[j];
		}

		for (int64_t j = 0; j < num; j++) {
			for (int64_t k = j + 1; k < num; k++) {
				if (trains[j] > trains[k]) {
					temp = trains[j];
					trains[j] = trains[k];
					trains[k] = temp;
					count++;

				}
			}
		}
		cout << "Optimal train swapping takes " << count << " swaps." << endl;
	}

	return 0;
}