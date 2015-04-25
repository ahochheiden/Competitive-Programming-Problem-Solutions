#include <iostream>
#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string temp;
vector<int64_t> values;
int64_t num;
bool diff[3010];
bool jolly;

int main() {
	while (getline(cin, temp)) {
		values.clear();
		for (int64_t i = 1; i < 3010; i++) {
			diff[i] = false;
		}
		jolly = true;

		stringstream input(temp);

		while (input >> num) {
			values.push_back(num);
		}

		for (int64_t i = 1; i < values.size(); i++) {
			diff[abs(values[i - 1] - values[i])] = true;
		}

		for (int64_t i = 1; i < (values.size() - 1); i++) {
			if (diff[i] != true) {
				jolly = false;
				break;
			}
		}

		if (jolly) {
			cout << "Jolly" << endl;
		} else {
			cout << "Not jolly" << endl;
		}
	}

	return 0;
}