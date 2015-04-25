#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>

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

void solve();

int main() {
	int64_t cases;
	string temp;
	cin >> cases;
	cin.ignore();

	getline(cin, temp);

	for (int64_t i = 0; i < cases; i++) {
		if (i > 0) {
			cout << endl;
		}
		solve();
	}

	return 0;
}

void solve() {
	int64_t numComp, num1, num2;
	char qType;
	string input;

	int64_t yes = 0;
	int64_t no = 0;

	cin >> numComp;
	cin.ignore();

	UnionFind network(numComp + 1);

	while (true) {
		getline(cin, input);
		if (input == "") {
			break;
		} else {
			stringstream inputStream(input);
			inputStream >> qType >> num1 >> num2;
			if (qType == 'c') {
				network.merge(num1, num2);
			} else {
				if (qType == 'q') {
					if (network.find(num1) == network.find(num2)) {
						yes++;
					} else {
						no++;
					}
				}
			}
		}
	}
	cout << yes << "," << no << endl;
}