#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> countryNames;
vector<int64_t> conquestCount;

void _counting();
void _sorting();

int main() {
	int64_t loops = 0;

	while (cin >> loops) {
		for (int64_t i = 0; i < loops; i++) {
			_counting();
		}

		_sorting();

		for (int64_t i = 0; i < countryNames.size(); i++) {
			cout << countryNames.at(i) << " " << conquestCount.at(i) << endl;
		}

		countryNames.clear();
		conquestCount.clear();
	}

	return 0;
}

void _counting() {
	string temp;
	cin >> temp;

	if (countryNames.size() == 0) {
		countryNames.push_back(temp);
		conquestCount.push_back(1);
	} else {
		bool found = false;
		for (int64_t i = 0; i < countryNames.size(); i++) {
			if (temp == countryNames.at(i)) {
				found = true;
				conquestCount.at(i)++;
			}
		}
		if (found == false) {
			countryNames.push_back(temp);
			conquestCount.push_back(1);
		}
	}
	getline(cin, temp);
}

void _sorting() {
	vector<string> countryNameTemp = countryNames;
	vector<int64_t> countryCountTemp = conquestCount;

	sort(countryNames.begin(), countryNames.end());

	for (int64_t i = 0; i < countryNames.size(); i++) {
		for (int64_t j = 0; j < countryNameTemp.size(); j++) {
			if (countryNames[i] == countryNameTemp[j]) {
				conquestCount[i] = countryCountTemp[j];
			}
		}
	}
}