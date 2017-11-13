#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	vector<int> palindromes;

	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			for(int k = 0; k < 10; k++)
			{
				int newPalindrome = 100000 * i + 10000 * j + 1000 * k + 100 * k + 10 * j + i;

				palindromes.push_back(newPalindrome);
			}
		}
	}

	int N;
	int inputPalindrome;
	int best;

	cin >> N;

	while(N--)
	{
		cin >> inputPalindrome;

		best = palindromes[0];

		for(int i = 1; i < palindromes.size(); i++)
		{
			if(abs(inputPalindrome - palindromes[i]) < abs(inputPalindrome - best))
			{
				best = palindromes[i];
			}
		}

		cout << best << endl;
	}

	return 0;
}