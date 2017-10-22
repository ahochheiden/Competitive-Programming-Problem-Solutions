#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	getline(cin, input);

	cout << input[0];

	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == '-' && i + 1 != input.size())
		{
			cout << input[i + 1];
		}
	}

	return 0;
}