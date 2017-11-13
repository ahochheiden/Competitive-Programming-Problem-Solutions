#include <iostream>
#include <iomanip>

using namespace std;

void solve()
{
	double b;
	double p;

	cin >> b >> p;

	double BPM = (60 * b) / p;

	double delta = BPM / b;
	double val1 = BPM - delta;
	double val2 = BPM + delta;

	cout << setprecision(4) << fixed << val1 << " "	<<
		setprecision(4) << fixed << BPM << " " <<
		setprecision(4) << fixed << val2 << endl;
}

int main()
{
	int N;
	cin >> N;

	while(N--)
	{
		solve();
	}

	return 0;
}