#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

using namespace std;

void calcPrimes();
bool isPrime(int64_t count);

vector<int64_t> primes;

int64_t cases;
int64_t numFlowers;
int64_t counter;
int64_t answer;
int64_t currentX;
int64_t currentY;
int64_t targetX;
int64_t targetY;

long double remainingDistance;
long double distanceNeeded;

bool doCalc;

int main()
{
	calcPrimes();

	cin >> cases;

	while(cases--)
	{
		counter = 0;
		answer = 0;
		currentY = 0;
		currentX = 0;

		cin >> numFlowers >> remainingDistance;

		doCalc = true;

		while(numFlowers--)
		{
			cin >> targetX >> targetY;

			if((remainingDistance > 0) && doCalc)
			{
				if(currentX == targetX || currentY == targetY)
				{
					distanceNeeded = abs(static_cast<long double>(currentX - targetX)) +
						abs(static_cast<long double>(currentY - targetY));
				}
				else
				{
					distanceNeeded = sqrt(
						pow(abs(static_cast<long double>(currentX - targetX)), 2) +
						pow(abs(static_cast<long double>(currentY - targetY)), 2));
				}


				if(remainingDistance >= distanceNeeded)
				{
					remainingDistance -= distanceNeeded;
					counter++;

					currentX = targetX;
					currentY = targetY;
				}
				else
				{
					doCalc = false;
				}
			}

			if(isPrime(counter))
			{
				answer = counter;
			}
		}

		cout << answer << endl;
	}

	return 0;
}

void calcPrimes()
{
	primes.push_back(2);
	primes.push_back(3);

	for(uint64_t i = 4; i < 20100; i++)
	{
		uint64_t temp = static_cast<int>(sqrt(i));

		for(uint64_t j = 2; j <= temp; j++)
		{
			if((i % j) == 0)
			{
				break;
			}

			if(j == temp)
			{
				primes.push_back(i);
			}
		}
	}
}

bool isPrime(int64_t count)
{
	for(uint64_t i = 0; i < primes.size(); i++)
	{
		if(primes[i] == count)
			return true;
	}
	return false;

}