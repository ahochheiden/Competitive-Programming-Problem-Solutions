#include <iostream>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main()
{
	double a, n;

	cin >> a >> n;

	double circlePerimeter = (sqrt(a / pi) * 2 * pi);

	if(circlePerimeter - n < 0.000001)
	{
		cout << "Diablo is happy!" << endl;
	}
	else
	{
		cout << "Need more materials!" << endl;
	}

	return 0;
}