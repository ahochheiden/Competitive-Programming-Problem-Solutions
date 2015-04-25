#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>

using namespace std;

struct Combination_t {
	int64_t codeNum;
	int64_t correct;
	int64_t misplaced;
};

vector<Combination_t> guesses;
Combination_t temp;

int64_t answer;
int64_t possibilities;
int64_t numCases;
int64_t numGuesses;
int64_t correct;
int64_t misplaced;

char slash;

void solve();
bool match(int64_t codeNum);
void compare(int64_t codeNum, int64_t guessNum);

int main(void) {
	cin >> numCases;

	for (int64_t i = 0; i < numCases; i++) {
		solve();
	}

	return 0;
}

void solve() {
	guesses.clear();
	possibilities = 0;

	cin >> numGuesses;

	for (int64_t i = 0; i < numGuesses; i++) {
		cin >> temp.codeNum >> temp.correct >> slash >> temp.misplaced;
		guesses.push_back(temp);
	}

	for (int64_t codeNum = 0; codeNum < 10000; codeNum++) {
		if (match(codeNum)) {
			possibilities++;
			answer = codeNum;
		}
	}

	if (possibilities == 1) {
		cout << setw(4) << setfill('0') << answer << endl;
	} else if (possibilities == 0) {
		cout << "impossible" << endl;
	} else {
		cout << "indeterminate" << endl;
	}
}

bool match(int64_t codeNum) {
	for (int64_t i = 0, sz = guesses.size(); i < sz; i++) {
		compare(codeNum, guesses[i].codeNum);
		if (correct != guesses[i].correct || misplaced != guesses[i].misplaced) {
			return false;
		}
	}
	return true;
}

void compare(int64_t codeNum, int64_t guessNum) {
	int64_t code[4];
	int64_t guess[4];

	correct = 0;
	misplaced = 0;

	for (int64_t i = 0; i < 4; i++) {
		code[i] = codeNum % 10;
		codeNum /= 10;
	}

	for (int64_t i = 0; i < 4; i++) {
		guess[i] = guessNum % 10;
		guessNum /= 10;
	}

	for (int64_t i = 0; i < 4; i++) {
		if (code[i] == guess[i]) {
			code[i] = guess[i] = -1;
			correct++;
		}
	}

	for (int64_t i = 0; i < 4; i++) {
		for (int64_t j = 0; j < 4; j++) {
			if (code[i] == guess[j] && code[i] != -1) {
				code[i] = guess[j] = -1;
				misplaced++;
			}
		}
	}
}