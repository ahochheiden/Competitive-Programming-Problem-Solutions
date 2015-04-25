#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

int64_t counter = 1;

int main() {
	int64_t cases, num;
	vector<int64_t> inputs;

	cin >> cases;
	for (int64_t i = 0; i < cases; i++) {
		inputs.clear();
		for (int64_t j = 0; j < 3; j++) {
			cin >> num;
			inputs.push_back(num);
		}
		sort(inputs.begin(), inputs.end());

		cout << "Case " << counter++ << ": " << inputs[1] << endl;
	}

	return 0;
}