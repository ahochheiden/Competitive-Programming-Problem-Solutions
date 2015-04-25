#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind

class UnionFind {
	struct UF { int64_t p; int64_t rank; };

public:
	UnionFind(int64_t n) {          // constructor
		howMany = n;
		uf = new UF[howMany];
		for (int64_t i = 0; i < howMany; i++) {
			uf[i].p = i;
			uf[i].rank = 0;
		}
	}

	~UnionFind() {
		delete[] uf;
	}

	int64_t find(int64_t x) { return find(uf, x); }        // for client use

	bool merge(int64_t x, int64_t y) {
		int64_t res1, res2;
		res1 = find(uf, x);
		res2 = find(uf, y);
		if (res1 != res2) {
			if (uf[res1].rank > uf[res2].rank) {
				uf[res2].p = res1;
			} else {
				uf[res1].p = res2;
				if (uf[res1].rank == uf[res2].rank) {
					uf[res2].rank++;
				}
			}
			return true;
		}
		return false;
	}

private:
	int64_t howMany;
	UF* uf;

	int64_t find(UF uf[], int64_t x) {     // recursive funcion for internal use
		if (uf[x].p != x) {
			uf[x].p = find(uf, uf[x].p);
		}
		return uf[x].p;
	}
};

int64_t numCases;
int64_t caseCount = 1;

int64_t numCities;
int64_t numConnectedCities;
int64_t thresholdValue;

int64_t xyPosition[1100][2];

int64_t numStates;
double length;
double lengthOfRoads;
double lengthOfRailoads;

struct Edge {
	int64_t i, j;

	double length() {
		return pow(xyPosition[i][0] - xyPosition[j][0], 2) + pow(xyPosition[i][1] - xyPosition[j][1], 2);
	}

	// to sort
	bool operator<(Edge edgeInput) {
		return length() < edgeInput.length();
	}
};

Edge edges[700000];
int64_t numEdges;

void solve();
void calc();

int main() {
	cin >> numCases;
	for (int64_t i = 0; i < numCases; i++) {
		solve();
	}

	return 0;
}

void solve() {
	cin >> numCities >> thresholdValue;
	for (int64_t i = 0; i < numCities; i++) {
		cin >> xyPosition[i][0] >> xyPosition[i][1];
	}

	calc();

	if (numStates < 0) {
		numStates = 1;
	}

	cout << "Case #" << caseCount++ << ": " << numStates << " " << round(lengthOfRoads) << " " << round(lengthOfRailoads) << endl;
}

void calc() {
	numEdges = 0;
	numStates = -1;
	lengthOfRoads = 0;
	lengthOfRailoads = 0;
	numConnectedCities = numCities;
	UnionFind cities(numCities);

	for (int64_t i = 0; i < numCities; i++) {
		for (int64_t j = i + 1; j < numCities; j++) {
			edges[numEdges].i = i;
			edges[numEdges].j = j;
			numEdges++;
		}
	}

	sort(edges, (edges + numEdges));

	for (int64_t i = 0; i < numEdges; i++) {
		if ((edges[i].length() > pow(thresholdValue, 2)) && (numStates < 0)) {
			numStates = numConnectedCities;
		}
		int64_t temp1 = cities.find(edges[i].i);
		int64_t temp2 = cities.find(edges[i].j);

		if (temp1 == temp2) {
			continue;
		}

		cities.merge(temp1, temp2);
		numConnectedCities--;

		length = sqrt(edges[i].length());

		if (numStates < 0) {
			lengthOfRoads += length;
		} else {
			lengthOfRailoads += length;
		}
	}
}