#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string input;
int top;
int stack1[3000];
bool print[3000];
bool stack2[3000];

void solve();
void process();

int main()
{
	while(getline(cin, input))
	{
		solve();
	}

	return 0;
}

void solve()
{
	top = 0;
	memset(print, true, sizeof print);

	process();

	for(int i = 0; i < input.size(); ++i)
	{
		if(print[i])
		{
			cout << input[i];
		}
	}

	cout << endl;
}

void process()
{
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == '(')
		{
			stack1[top] = i;
			stack2[top] = false;
			top++;
		}
		else
		{
			if(input[i] == '+')
			{
				if(top)
				{
					stack2[top - 1] = true;
				}
			}
			else
			{
				if(input[i] == ')')
				{
					if(((stack2[top - 1] && (stack1[top - 1] - 1 >= 0 && input[stack1[top - 1] - 1] != '+' && input[stack1[top - 1] - 1] != '(') || (i + 1 < input.size() && input[i + 1] != '+' && input[i + 1] != ')')) == 0))
					{
						if(stack1[top - 1] - 1 >= 0)
						{
							if(input[stack1[top - 1] - 1] == '(')
							{
								if(i + 1 < input.size())
								{
									if(input[i + 1] == ')')
									{
										stack2[top - 2] = stack2[top - 1];
									}
								}
							}
						}
						print[stack1[top - 1]] = false;
						print[i] = false;
					}
					top--;
				}
			}
		}
	}
}