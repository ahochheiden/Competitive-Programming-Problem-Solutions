#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

string first;
string second;
string temp;
int64_t position;

void solve();

int main() {
	while (cin >> first >> second) {
		solve();
	}

	return 0;
}

void solve() {
	temp = "";
	position = 0;

	for (int64_t i = 0; i < second.size(); i++) {
		if (first[position] == second[i]) {
			position++;
			temp += second[i];
		}
	}

	if (first == temp) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}