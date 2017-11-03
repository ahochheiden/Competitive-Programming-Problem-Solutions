#include <iostream>
#include <string>
#include <utility>

using namespace std;

string rotate(string toRotate)
{
	int sum = 0;

	for(size_t i = 0; i < toRotate.size(); i++)
	{
		sum += toupper(toRotate[i]) - 'A';
	}

	for(size_t i = 0; i < toRotate.size(); i++)
	{
		toRotate[i] = ((toRotate[i] - 'A' + sum) % 26) + 'A';
	}

	return toRotate;
}

int main()
{
	string input;

	cin >> input;

	// divide
	string firstHalf = input.substr(0, input.size() / 2);
	string secondHalf = input.substr(input.size() / 2);

	// rotate
	string rotatedFirstHalf = rotate(firstHalf);
	string rotatedSecondHalf = rotate(secondHalf);

	// merge
	string output = "";

	for(size_t i = 0; i < rotatedFirstHalf.size(); i++)
	{
		output += char(((rotatedFirstHalf[i] - 'A' + rotatedSecondHalf[i] - 'A') % 26) + 'A');
	}

	cout << output << endl;

	return 0;
}