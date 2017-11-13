#include <iostream>

using namespace std;

int input;
long long pills[40][40];

long long calc(int whole, int half);

int main()
{
	calc(30, 0);

	while(cin >> input)
	{
		if(input)
		{
			cout << pills[input][0] << endl;
		}
		else
		{
			break;
		}
	}

	return 0;
}

long long calc(int whole, int half)
{
	if(pills[whole][half] > 0)
	{
		return pills[whole][half];
	}

	if(whole == 0)
	{
		pills[whole][half] = 1;
		return pills[whole][half];
	}

	if(half == 0)
	{
		calc(whole - 1, half + 1);
		pills[whole][half] = calc((whole - 1), (half + 1));
		return pills[whole][half];
	}

	pills[whole][half] = calc((whole - 1), (half + 1)) + calc(whole, (half - 1));

	return pills[whole][half];
}