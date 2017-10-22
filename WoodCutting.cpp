#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int64_t numCases = 0;
int64_t customers;
int64_t numOfLogs;
int64_t sum;
int64_t woodSize;

vector<int64_t> customerSum;

double waitTime;
double runningTime;


int main()
{
	cin >> numCases;

	while(numCases--)
	{
		waitTime = 0;
		runningTime = 0;
		customerSum.clear();

		cin >> customers;
		
		for(int i = 0; i < customers; i++)
		{
			sum = 0;
			cin >> numOfLogs;

			for(int j = 0; j < numOfLogs; j++)
			{
				cin >> woodSize;
				sum += woodSize;
			}

			customerSum.push_back(sum);
		}

		sort(customerSum.begin(), customerSum.end());
		
		for(int i = 0; i < customers; i++)
		{
			waitTime += runningTime + customerSum[i];
			runningTime += customerSum[i];
		}

		cout << fixed << setprecision(10) << (waitTime / customers) << endl;
	}

	return 0;
}