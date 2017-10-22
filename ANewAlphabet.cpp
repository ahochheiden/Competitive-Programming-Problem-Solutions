#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string input = "";

const string values[26] = {
	"@", "8", "(", "|)", 
	"3", "#", "6", "[-]", 
	"|", "_|", "|<", "1", 
	"[]\\/[]", "[]\\[]", "0", "|D", 
	"(,)", "|Z", "$", "']['", 
	"|_|", "\\/", "\\/\\/", "}{", 
	"`/", "2"};

string output = "";

int main()
{
	getline(cin, input);

	for(uint64_t i = 0; i < input.size(); i++)
	{
		if(isalpha(input[i]))
		{
			output += values[(tolower(input[i]) - 'a')];
		}
		else
		{
			output += input[i];
		}
	}

	cout << output;

	return 0;
}