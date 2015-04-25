#include <iostream>
#include <cstdint>

using namespace std;

int64_t numCases;
int64_t numFarmers;
int64_t sum;

int64_t area;
int64_t animals;
int64_t premium;

int main() {
	cin >> numCases;

	for (int64_t i = 0; i < numCases; i++) {
		cin >> numFarmers;
		sum = 0;

		for (int64_t j = 0; j < numFarmers; j++) {
			cin >> area >> animals >> premium;
			sum += (area * premium);
		}

		cout << sum << endl;
	}
}