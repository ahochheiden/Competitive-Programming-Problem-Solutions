#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int pages;
int numPages;
int low;
int high;
char separator;
int currentPage;
vector<pair<int, int> > pageRanges;
string rangesInput;

void solve();
void process();
void calc();

int main()
{
	while(cin >> pages)
	{
		if(pages)
		{
			getline(cin, rangesInput);
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
	pageRanges.clear();
	numPages = 0;
	currentPage = 0;

	getline(cin, rangesInput);

	process();

	calc();

	cout << numPages << endl;
}

void process()
{
	stringstream inputstringstream(rangesInput);

	while(inputstringstream >> low)
	{
		inputstringstream >> separator;

		if(separator == ',')
		{
			if(low <= pages)
			{
				pageRanges.push_back(make_pair(low, low));
			}
		}
		else
		{
			if(separator == '-')
			{
				inputstringstream >> high;

				inputstringstream >> separator;

				high = min(high, pages);

				if(low <= high)
				{
					pageRanges.push_back(make_pair(low, high));
				}
			}
		}
	}

	sort(pageRanges.begin(), pageRanges.end());
}

void calc()
{
	for(int i = 0; i < pageRanges.size(); i++)
	{
		if((pageRanges[i].first <= currentPage) && (pageRanges[i].second <= currentPage))
		{
			continue;
		}
		else
		{
			if((pageRanges[i].first <= currentPage) && (pageRanges[i].second > currentPage))
			{
				numPages += pageRanges[i].second - currentPage;

				currentPage = pageRanges[i].second;
			}
			else
			{
				if(pageRanges[i].first > currentPage)
				{
					numPages += pageRanges[i].second - pageRanges[i].first + 1;

					currentPage = pageRanges[i].second;
				}
			}
		}
	}
}