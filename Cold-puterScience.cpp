#include <iostream>

using namespace std;

int main()
{
	int numInputs;

	cin >> numInputs;

	int temp;
	int count = 0;

	for(int i = 0; i < numInputs; i++)
	{
		cin >> temp;

		if(temp < 0)
		{
			count++;
		}
	}

	cout << count << endl;

	return 0;
}