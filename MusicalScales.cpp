#include <iostream>
#include <string>

using namespace std;

const int NOTES = 12;
const int TONES = 8;
const int MAX_N = 100;

int n;

const string ALL[NOTES * 3] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

int order[TONES + 2] = {0, 1, 2, 2, 3, 4, 5, 5};

string scale[NOTES][TONES];
string notes[MAX_N];

void genScale()
{
	for(int i = 0; i < NOTES; i++)
	{
		for(int j = 0; j < TONES; j++)
		{
			scale[i][j] = ALL[i + j + order[j]];
		}
	}
}

bool check(int cur)
{
	bool printed = true;

	for(int i = 0; i < n; i++)
	{

		bool found = false;

		for(int j = 0; j < TONES; j++)
		{
			if(scale[cur][j] == notes[i])
			{
				found = true;
			}
		}

		printed = (found && printed);
	}

	return printed;
}

int main()
{
	genScale();

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> notes[i];
	}

	bool printed = false;

	for(int i = 0; i < NOTES; i++)
	{

		if(check(i))
		{
			if(printed) cout << " ";
			printed = true;

			cout << ALL[i];
		}
	}

	if(!printed)
	{
		cout << "none";
	}

	cout << endl;

	return 0;
}