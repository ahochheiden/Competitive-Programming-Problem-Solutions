#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void solve();
void calc();

int64_t numStacks;
int64_t temp;
int64_t counter = 1;
int64_t sum;
int64_t average;
int64_t answer;
vector<int64_t> heights;

int main() {
	while (cin >> numStacks) {
		if (numStacks != 0) {
			solve();
		} else {
			break;
		}
	}

	return 0;
}

void solve() {
	heights.clear();
	sum = 0;

	for (int64_t i = 0; i < numStacks; i++) {
		cin >> temp;
		sum += temp;
		heights.push_back(temp);
	}

	calc();

	cout << "Set #" << counter++ << endl;
	cout << "The minimum number of moves is " << answer << "." << endl << endl;
}

void calc() {
	average = (sum / numStacks);
	answer = 0;

	for (int64_t i = 0; i < numStacks; i++) {
		if (heights[i] > average) {
			answer += (heights[i] - average);
		}
	}
}