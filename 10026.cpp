#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

struct Job_t {
	int64_t time;
	int64_t fine;
	int64_t position;
};

void solve();
bool comparison(const Job_t &job1, const Job_t &job2);

int64_t numCases;
int64_t numInputs;

Job_t temp;
vector<Job_t> jobs;

int main() {
	cin >> numCases;
	for (int64_t i = 0; i < numCases; i++) {
		if (i) {
			cout << endl;
		}
		cin >> numInputs;
		solve();
	}

	return 0;
}

void solve() {
	jobs.clear();
	jobs.reserve(numInputs);

	for (int64_t i = 1; i <= numInputs; i++) {
		cin >> temp.time >> temp.fine;
		temp.position = i;
		jobs.push_back(temp);
	}

	stable_sort(jobs.begin(), jobs.end(), comparison);

	for (int64_t i = 0; i < numInputs; i++) {
		if (i) {
			cout << " ";
		}
		cout << jobs[i].position;
	}
	cout << endl;
}

bool comparison(const Job_t &job1, const Job_t &job2) {
	return 	((job1.time * job2.fine) < (job2.time * job1.fine));
}