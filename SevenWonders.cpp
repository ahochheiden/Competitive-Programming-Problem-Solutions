#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	string input;

	cin >> input;

	int t = 0;
	int c = 0;
	int g = 0;

	for(auto i : input)
	{
		switch(i)
		{
			case 'T':
			{
				t++;
				break;
			}
			case 'C':
			{
				c++;
				break;
			}
			case 'G':
			{
				g++;
				break;
			}
			default:
			{
				// do nothing
			}
		}
	}

	int total = t*t + c*c + g*g;

	if(t != 0 && c != 0 && g != 0)
	{
		total += 7 * (min(min(t, c), g));
	}

	cout << total << endl;

	return 0;
}