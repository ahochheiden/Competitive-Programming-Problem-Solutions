#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int64_t numCases;
int64_t numHouses;
int64_t temp;

int64_t numAccessPoints;
int64_t accessPointsNeeded;

int64_t maxDist;
int64_t minDist;

vector<int64_t> houses;

double output;
double high;
double low;
double mid;
double position;

void solve();
void binarySearch();
bool testDistance(double dist);

int main() {
	cin >> numCases;

	for (int64_t i = 0; i < numCases; i++) {
		solve();
	}

	return 0;
}

void solve() {
	output = 0.0;
	houses.clear();

	cin >> numAccessPoints >> numHouses;

	houses.reserve(numHouses + 1);

	for (int64_t i = 0; i < numHouses; i++) {
		cin >> temp;
		houses.push_back(temp);
	}

	if (numAccessPoints >= numHouses) {
		goto endCase;
	}

	sort(houses.begin(), houses.end());
	minDist = houses[0];
	maxDist = houses[houses.size() - 1];

	binarySearch();

endCase:
	cout << showpoint << fixed << setprecision(1) << output << endl;
}

void binarySearch() {
	low = 0;
	high = (maxDist - minDist);

	while (high - low > 1e-2) {
		mid = ((high + low) / 2);
		if (testDistance(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}

	output = high;
}

bool testDistance(double dist) {
	accessPointsNeeded = 1;
	dist *= 2;
	position = (houses[0] + dist);

	for (int64_t i = 0; i < houses.size(); i++) {
		if (position <= houses[i]) {
			accessPointsNeeded++;
			position = (houses[i] + dist);
		}
	}

	if (accessPointsNeeded <= numAccessPoints) {
		return true;
	} else {
		return false;
	}
}