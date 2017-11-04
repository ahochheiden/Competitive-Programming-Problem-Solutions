#include <iostream>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 20000;

int state[MAX_N][MAX_M];
int courses[MAX_N];

int originalM;
int originalN;

int solve(int capacity, int courseIndex, int prevCapacity)
{
	if(courseIndex >= originalN)
	{
		return 0;
	}

	if(state[courseIndex][capacity] == 0)
	{
		int caloriesIfEat = min(courses[courseIndex], capacity);

		state[courseIndex][capacity] =
			max((solve(capacity * 2 / 3, courseIndex + 1, capacity) + caloriesIfEat), // Eat
				max(solve(prevCapacity, courseIndex + 1, capacity),                   // Don't eat once
				solve(originalM, courseIndex + 2, capacity)));                        // Don't eat twice
	}

	return state[courseIndex][capacity];
}

int main()
{
	int n, m;

	cin >> n >> m;

	originalM = m;
	originalN = n;

	for(int i = 0; i < n; i++)
	{
		cin >> courses[i];
	}

	cout << solve(m, 0, m) << endl;

	return 0;
}