#include <iostream>

using namespace std;

int main()
{
	int h, w, n, temp, sum = 0;

	cin >> h >> w >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
	
		sum += temp;

		if(sum == w)
		{
			sum = 0;
			continue;
		}

		if(sum < w)
		{
			continue;
		}

		if(sum > w)
		{
			cout << "NO" << endl;

			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}