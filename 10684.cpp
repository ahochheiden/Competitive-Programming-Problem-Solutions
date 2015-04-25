#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int64_t dp[10010];
int64_t output;

int64_t input;

void solve();

int main() {
	while (cin >> input) {
		if (input == 0) {
			break;
		} else {
			solve();
		}

	}
	return 0;
}

void solve() {
	fill(dp, (dp + input), 0);

	for (int64_t i = 0; i < input; i++) {
		cin >> dp[i];
	}

	for (int64_t i = 1; i < input; i++) {
		dp[i] = max(dp[i], (dp[i] + dp[i - 1]));
	}

	output = *max_element(dp, (dp + input));

	if (output <= 0) {
		cout << "Losing streak." << endl;
	} else {
		cout << "The maximum winning streak is " << output << '.' << endl;
	}
}