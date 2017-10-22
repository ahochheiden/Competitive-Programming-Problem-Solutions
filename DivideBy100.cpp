#include <iostream>
#include <string>

using namespace std;

int main()
{
	string in;
	string div;

	cin >> in >> div;

	int d = div.length();
	int il = in.length();

	if(d > il)
	{
		string app = "0.";

		for(int i = 1; i < d - il; i++)
		{
			app += "0";
		}

		in = app + in;

		while(in[in.length() - 1] == '0')
		{
			in.pop_back();
		}

		cout << in << endl;
	}
	else
	{
		in.insert(il - (d - 1), ".");

		while(in[in.length() - 1] == '0')
		{
			in.pop_back();
		}

		if(in[in.length() - 1] == '.')
		{
			in.pop_back();
		}

		cout << in << endl;
	}
}