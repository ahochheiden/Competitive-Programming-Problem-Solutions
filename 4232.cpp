#include <iostream>
#include <cstdint>

using namespace std;

int64_t gcd(int64_t a, int64_t b);
int64_t lcm(int64_t a, int64_t b);

int main()
{
	int64_t loop = 0;
	int64_t a = 0;
	int64_t b = 0;

	cin >> loop;

	for(int64_t i = 1; i <= loop; i++)
	{
		cin >> a >> b;

		cout << i << " " << lcm(a, b) << " " << gcd(a, b) << endl;
	}

	return 0;
}

int64_t gcd(int64_t a, int64_t b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, (a % b));
	}
}

int64_t lcm(int64_t a, int64_t b)
{
	return ((a * b) / (gcd(a, b)));
}