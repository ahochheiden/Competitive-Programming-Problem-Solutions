#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, w, h;

	cin >> n >> w >> h;

	int temp;

	double maximum = sqrt((w * w) + (h * h));

	for(int i = 0; i < n; i++)
	{
		cin >> temp;

		if(temp <= maximum)
		{
			cout << "DA" << endl;
		}
		else
		{
			cout << "NE" << endl;
		}
	}

	return 0;
}