#include <iostream>

using namespace std;

int numPitches;
int pitch[200];
int maxPitch;
int total;
int climbers;

int calc(int ropeLength);

int main()
{
	while(cin >> numPitches)
	{
		if(numPitches)
		{
			for(int i = 0; i < numPitches; i++)
			{
				cin >> pitch[i];
			}

			cout << calc(50) << " " << calc(60) << " " << calc(70) << endl;
		}
		else
		{
			break;
		}
	}

	return 0;
}

int calc(int ropeLength)
{
	maxPitch = pitch[0];
	total = pitch[0];

	for(int i = 1; i < numPitches; i++)
	{
		total += pitch[i];
		if(pitch[i] > maxPitch)
		{
			maxPitch = pitch[i];
		}
	}

	climbers = (ropeLength / maxPitch) + 1;

	if((ropeLength < (2 * total)) || (climbers < 2))
	{
		return 0;
	}
	else
	{
		return climbers;
	}
}