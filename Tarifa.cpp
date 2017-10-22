#include <iostream>

using namespace std;

int main()
{
	int X, count;

	cin >> X >> count;

	int total = X * (count + 1);

	int temp;

	for(int i = 0; i < count; i++)
	{
		cin >> temp;
		total -= temp;
	}

	cout << total << endl;

	return 0;
}