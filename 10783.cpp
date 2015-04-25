#include <iostream>
#include <cstdint>>

using namespace std;

int main() {
	int64_t loops, num1, num2, answer;
	cin >> loops;

	for (int64_t i = 0; i < loops; i++) {
		answer = 0;
		cin >> num1 >> num2;
		for (int64_t j = num1; j <= num2; j++) {
			if (j % 2 == 1) {
				answer += j;
			}
		}
		cout << "Case " << (i + 1) << ": " << answer << endl;
	}

	return 0;
}