#include <iostream>
#include <string> 
#include <cstring>
#include <cstdint>

using namespace std;

int64_t caseCount = 1;
string city1;
string city2;
int64_t c[200][200];

int64_t LCS(const int64_t &m, const int64_t &n);

int main() {
	while (getline(cin, city1)) {
		if (city1[0] == '#') {
			break;
		}
		getline(cin, city2);

		cout << "Case #" << caseCount++ << ": you can visit at most " << LCS(city1.size(), city2.size()) << " cities." << endl;
	}

	return 0;
}

int64_t LCS(const int64_t &m, const int64_t &n) {
	memset(c, 0, sizeof(c));

	for (int64_t i = 1; i <= m; ++i) {
		for (int64_t j = 1; j <= n; ++j) {
			if (city1[i - 1] == city2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			} else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			} else {
				c[i][j] = c[i][j - 1];
			}
		}
	}

	return c[m][n];
}