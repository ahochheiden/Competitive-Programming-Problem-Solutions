#include<cmath>
#include<iostream>

using namespace std;

int main()
{
	int x1;
	int x2;
	int limit1;
	int limit2;
	int x1Table[1000010];
	int x2Table[1000010];

	cin >> x1 >> x2;

	cin >> limit1;
	for(int i = 0; i < limit1; i++)
	{
		cin >> x1Table[i];
	}

	cin >> limit2;
	for(int i = 0; i < limit2; i++)
	{
		cin >> x2Table[i];
	}

	bool go1 = false;
	bool go2 = false;
	int step1 = 0;
	int step2 = 0;

	for(int i = 1; i < 3000010; i++)
	{
		if(go1)
		{
			x1++;
		}

		if(go2)
		{
			x2++;
		}

		if(i == x1Table[step1])
		{
			go1 = !go1;
			if(step1 < limit1)
			{
				step1++;
			}
		}

		if(i == x2Table[step2])
		{
			go2 = !go2;
			if(step2 < limit2)
			{
				step2++;
			}
		}

		// Check for collision
		if(abs(x1 - x2) <= 4)
		{
			cout << "bumper tap at time " << i << endl;
			return 0;
		}
	}

	cout << "safe and sound" << endl;

	return 0;
}