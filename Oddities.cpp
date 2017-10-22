#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count;

	cin >> count;

	int num;

	for(int i = 0; i < count; i++)
	{
		cin >> num;

		if(num % 2 == 0)
		{
			cout << num << " is even" << endl;
		}
		else
		{
			cout << num << " is odd" << endl;
		}
	}

	return 0;
}