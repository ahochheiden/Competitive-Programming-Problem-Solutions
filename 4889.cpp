#include <iostream>

using namespace std;

double length;
double height;
double thickness;
double temp;

void solve();
void swap(double &a, double &b);

int main(void)
{
	while(cin >> length >> height >> thickness)
	{
		if(length || height || thickness)
		{
			solve();
		}
		else
		{
			break;
		}
	}

	return 0;
}

void solve()
{
	if(length < height)
	{
		swap(length, height);
	}

	if(length < thickness)
	{
		swap(length, thickness);
	}

	if(height < thickness)
	{
		swap(height, thickness);
	}

	if(length >= 125 && height >= 90 && thickness >= 0.25)
	{
		if(length <= 290 && height <= 155 && thickness <= 7)
		{
			cout << "letter";
		}
		else
		{
			if(length <= 380 && height <= 300 && thickness <= 50)
			{
				cout << "packet";
			}
			else
			{
				if(length + height + height + thickness + thickness <= 2100)
				{
					cout << "parcel";
				}
			}
		}
	}
	else
	{
		cout << "not mailable";
	}

	cout << endl;
}

void swap(double &a, double &b)
{
	temp = a;
	a = b;
	b = temp;
}