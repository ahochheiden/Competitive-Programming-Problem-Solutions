#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int64_t caseCount;
int64_t counter = 0;
int64_t temp;

string input;

vector<int64_t> missles;
vector<int64_t> lis;
vector<int64_t> path;
vector<int64_t> output;

void solve();
void calc();

int main() {
	cin >> caseCount;
	cin.ignore();
	cin.ignore();

	for (int64_t i = 0; i < caseCount; i++) {
		solve();
	}

	return 0;
}

void solve() {
	missles.clear();
	lis.clear();
	path.clear();
	output.clear();

	while (getline(cin, input) && (input != "")) {
		stringstream stream(input);
		stream >> temp;
		missles.push_back(temp);
	}

	calc();

	cout << "Max hits: " << output.size() << endl;
	for (int64_t i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	if (++counter != caseCount) {
		cout << endl;
	}
}

void calc() {
	lis.assign(missles.size(), 1);
	path.assign(missles.size(), -1);

	for (int64_t i = 1; i < missles.size(); ++i) {
		for (int64_t j = 0; j < i; ++j) {
			if (missles[j] < missles[i]) {
				temp = (lis[j] + 1);
			} else {
				temp = 0;
			}
			if (temp > lis[i]) {
				lis[i] = temp;
				path[i] = j;
			}
		}
	}

	temp = distance(lis.begin(), max_element(lis.begin(), lis.end()));
	output.assign(1, missles[temp]);

	while (path[temp] != -1) {
		temp = path[temp];
		output.insert(output.begin(), missles[temp]);
	}
}