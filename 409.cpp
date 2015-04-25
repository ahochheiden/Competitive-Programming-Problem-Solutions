#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int64_t k;
int64_t e;

vector<string> keywords;
vector<string> excuses;
vector<string> excusesTemp;
vector<string> output;
vector<int64_t> keywordsFoundCount;

void solve();
void readInput();
void processing();
void counting();

int main() {
	int64_t setCount = 1;

	while (cin >> k >> e) {
		keywords.clear();
		excuses.clear();
		excusesTemp.clear();
		output.clear();
		keywordsFoundCount.clear();

		cout << "Excuse Set #" << setCount++ << endl;
		solve();
	}

	return 0;
}

void solve() {
	readInput();
	processing();
	counting();

	for (int64_t i = 0; i < output.size(); i++) {
		cout << output.at(i) << endl;
	}
	cout << endl;
}


void readInput() {
	string input;
	for (int64_t i = 0; i < k; i++) {
		cin >> input;
		keywords.push_back(input);
	}
	for (int64_t i = 0; i < e + 1; i++) {
		getline(cin, input);
		excuses.push_back(input);
		keywordsFoundCount.push_back(0);
	}
	excusesTemp = excuses;
}

void processing() {
	for (int64_t i = 0; i < excusesTemp.size(); i++) {
		for (int64_t j = 0; j < excusesTemp.at(i).size(); j++) {
			if (ispunct(excusesTemp[i][j])) {
				excusesTemp[i][j] = ' ';
			}
			excusesTemp[i][j] = tolower(excusesTemp[i][j]);
		}
	}
}

void counting() {
	int64_t maxCount = 0;

	for (int64_t i = 0; i < excusesTemp.size(); i++) {
		stringstream excusesStream(excusesTemp.at(i));
		string tempExcuse = "";

		while (excusesStream >> tempExcuse) {
			for (int64_t j = 0; j < keywords.size(); j++) {
				if (tempExcuse == keywords.at(j)) {
					keywordsFoundCount.at(i)++;
				}
			}
		}
	}

	for (int64_t i = 0; i < keywordsFoundCount.size(); i++) {
		if (keywordsFoundCount.at(i) > maxCount) {
			maxCount = keywordsFoundCount.at(i);
		}
	}

	for (int64_t i = 0; i < excuses.size(); i++) {
		if (keywordsFoundCount.at(i) == maxCount) {
			output.push_back(excuses.at(i));
		}
	}
}