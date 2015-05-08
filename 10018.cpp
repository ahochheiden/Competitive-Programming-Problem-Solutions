#include <iostream>
#include <cstdint>

using namespace std;

uint64_t numCases;
uint64_t counter;
uint64_t input;
uint64_t reversedNum;

void reverseAndAdd(uint64_t &num);
uint64_t reverseNum(uint64_t num);
bool isPalindrome(uint64_t num);

int main() {
	cin >> numCases;
	for (int64_t i = 0; i < numCases; i++) {
		cin >> input;
		counter = 0;
		while (++counter) {
			reverseAndAdd(input);
			if (isPalindrome(input)) {
				break;
			}
		}
		cout << counter << ' ' << input << endl;
	}
	return 0;
}

void reverseAndAdd(uint64_t &num) {
	reversedNum = reverseNum(num);
	num = num + reversedNum;
}

uint64_t reverseNum(uint64_t num) {
	reversedNum = 0;
	while (num != 0) {
		reversedNum = reversedNum * 10 + num % 10;
		num /= 10;
	}
	return reversedNum;
}

bool isPalindrome(uint64_t num) {
	reversedNum = reverseNum(num);
	if (reversedNum == num) {
		return true;
	} else {
		return false;
	}
}