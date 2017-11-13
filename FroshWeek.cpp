#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> task;
	vector<int> time;

	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		task.push_back(temp);
	}

	for(int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		time.push_back(temp);
	}

	sort(task.begin(), task.end());
	sort(time.begin(), time.end());

	int count = 0;
	int i = 0;
	int j = 0;

	while(i < n && j < m)
	{
		if(task[i] <= time[j])
		{
			i++; count++;
		}

		j++;
	}

	cout << count << endl;

	return 0;
}