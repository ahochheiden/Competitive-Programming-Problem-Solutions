#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b;

	string garbage;

	cin >> a >> b;
	getline(cin, garbage);

	for(int i = 0; i < a; i++)
	{
		getline(cin, garbage);
	}

	cout << b << endl;

	return 0;
}