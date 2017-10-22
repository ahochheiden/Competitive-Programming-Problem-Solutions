#include <iostream>
#include <cstdint>

using namespace std;

int64_t cases = 0;
int64_t counter = 0;

char grid[20][20];

int main()
{
	cin >> cases;

	int64_t row, col;

	while(cases--)
	{
		cin >> row >> col;

		for(int64_t i = 0; i < row; i++)
		{
			for(int64_t j = 0; j < col; j++)
			{
				char temp;

				cin >> temp;

				grid[i][j] = temp;
			}
		}

		cout << "Test " << ++counter << endl;

		for(int64_t i = row - 1; 0 <= i; i--)
		{
			for(int64_t j = col - 1; 0 <= j; j--)
			{
				cout << grid[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}