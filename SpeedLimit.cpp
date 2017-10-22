#include <iostream>

using namespace std;

int main()
{
	int n, s, t;

	while(cin >> n && n != -1)
	{
		int oldT = 0;
		int totalMiles = 0;

		for(int i = 0; i < n; i++)
		{
			cin >> s >> t;

			totalMiles += s * (t - oldT);

			oldT = t;
		}

		cout << totalMiles << " miles" << endl;
	}

	return 0;
}