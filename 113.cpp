#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double number;
double base;

int main() {
	while (cin >> base >> number) {
		cout << setprecision(0) << fixed << pow(number, (1 / base)) << endl;
	}

	return 0;
}