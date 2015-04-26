#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

using namespace std;

int64_t caseCount;
int64_t people;
int64_t score;

vector<int64_t> scores;

double average;
double numAboveAverage;
double output;

void solve();

int main() {
	cin >> caseCount;

	for (int64_t i = 0; i < caseCount; i++) {
		solve();
	}

	return 0;
}

void solve() {
	scores.clear();
	average = 0;
	numAboveAverage = 0;

	cin >> people;

	for (int64_t i = 0; i < people; i++) {
		cin >> score;
		scores.push_back(score);
		average += score;
	}

	average /= scores.size();

	for (int64_t i = 0; i < people; i++) {
		if (scores[i] > average) {
			numAboveAverage++;
		}
	}

	output = (numAboveAverage / people * 100);
	cout << showpoint << fixed << setprecision(3) << output << '%' << endl;
}