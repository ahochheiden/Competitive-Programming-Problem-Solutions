#include <iostream>
#include <cstdint>
#include <iomanip>

using namespace std;

int main()
{
	int64_t loops, num;
	double dist, p1, p2, fly, o;

	cin >> loops;

	for(int64_t i = 0; i < loops; i++)
	{
		cin >> num >> dist >> p1 >> p2 >> fly;

		cout << num << " ";

		o = ((dist / (p1 + p2)) * fly);

		cout << fixed << showpoint << setprecision(2) << o << endl;
	}

	return 0;
}