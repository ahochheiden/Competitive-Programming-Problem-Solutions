#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	if(s.find("ss") != string::npos)
	{
		cout << "hiss" << endl;
	}
	else
	{
		cout << "no hiss" << endl;
	}

	return 0;
}