#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	int64_t loops, num, mod, fib1, fib2, count, temp;

	cin >> loops;

	for(int64_t i = 0; i < loops; i++)
	{
		cin >> num >> mod;
		cout << num << " ";

		fib1 = 1;
		fib2 = 1;
		count = 2;

		if(mod == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			if(mod == 2)
			{
				cout << 3 << endl;
			}
			else
			{
				while(true)
				{

					fib1 = (fib1 + fib2) % mod;
					fib2 = (fib1 + fib2) % mod;

					count += 2;

					if(fib1 == 1 && fib2 == 0)
					{
						break;
					}
				}
				cout << count << endl;
			}
		}
	}

	return 0;
}