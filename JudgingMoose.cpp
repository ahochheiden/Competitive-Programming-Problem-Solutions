#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	if(a == 0 && b == 0)
	{
		cout << "Not a moose" << endl;

		return 0;
	}

	if(a == b)
	{
		cout << "Even " << a + b << endl;
	}
	else
	{
		cout << "Odd " << ((a < b) ? b * 2 : a * 2) << endl;
	}

	return 0;
}