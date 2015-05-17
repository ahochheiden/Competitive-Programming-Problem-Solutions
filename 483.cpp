#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string input;
string output;
string temp;

void solve();

int main() {
	while (getline(cin, input)) {
		solve();
	}

	return 0;
}

void solve() {
	output.clear();
	stringstream stream(input);

	while (stream >> temp) {
		reverse(temp.begin(), temp.end());
		output += temp;
		output += ' ';
	}
	output.pop_back();

	cout << output << endl;
}