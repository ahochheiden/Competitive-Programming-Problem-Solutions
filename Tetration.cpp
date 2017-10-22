#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double input;

	cin >> input;

	input = pow(input, 1 / input);

	cout << setprecision(6) << fixed << input << endl;

	return 0;
}