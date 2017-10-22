#include <iostream>

using namespace std;

int counts[6] = {1, 1, 2, 2, 2, 8};

int main()
{
	int temp;

	for(int i = 0; i < 6; i++)
	{
		cin >> temp;

		cout << counts[i] - temp;

		if(i != 5)
		{
			cout << " ";
		}
	}

	cout << endl;

	return 0;
}