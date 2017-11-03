#include <iostream>
#include <string>
#include <stack>

using namespace std;

const string undo = "undo";

int main()
{
	int n;
	int k;

	cin >> n >> k;

	stack<int> eggPositions;

	// Child 0 always starts with the egg
	eggPositions.push(0);

	string input;

	int numberUndos;
	int movement;
	int newPosition;

	for(int i = 0; i < k; i++)
	{
		cin >> input;

		if(input == undo)
		{
			cin >> numberUndos;

			for(int j = 0; j < numberUndos; j++)
			{
				eggPositions.pop();
			}
		}
		else
		{
			movement = stoi(input);

			newPosition = (((eggPositions.top() + movement) % n) + n) % n;

			eggPositions.push(newPosition);
		}
	}

	cout << eggPositions.top() << endl;

	return 0;
}