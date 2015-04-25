#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

const bool fingers[16][11] =
{
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0} 
};

const string index = "cdefgabCDEFGAB";
string input;

int64_t changeCount[11];

void solve();
void prepare();
void calc();

int main() {
	int64_t cases;
	cin >> cases;
	cin.ignore();

	for (int64_t i = 0; i < cases; i++) {
		solve();
	}

	return 0;
}

void prepare() {
	for (int64_t i = 1; i <= 10; i++) {
		changeCount[i] = 0;
	}
}

void solve() {
	prepare();
	getline(cin, input);
	calc();

	for (int64_t i = 1; i < 10; i++) {
		cout << changeCount[i] << " ";;
	}
	cout << changeCount[10] << endl;
}

void calc() {
	int64_t currentNote = 15;
	int64_t prevNote = 15;

	for (int64_t i = 0; i < input.size(); i++) {
		for (int64_t j = 0; j <= index.size(); j++) {
			if (input[i] == index[j]) {
				currentNote = j;
				break;
			}
		}
		if (i == 0) {
			for (int64_t j = 1; j <= 10; j++) {
				changeCount[j] += fingers[currentNote][j];
			}
		} else {
			for (int64_t j = 1; j <= 10; j++) {
				if ((fingers[prevNote][j] - fingers[currentNote][j]) == -1) {
					changeCount[j]++;
				}
			}
		}
		prevNote = currentNote;
	}
}