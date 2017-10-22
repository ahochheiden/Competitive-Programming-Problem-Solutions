#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1001;
const int DISCONNECT = -1;

bool seen1[MAX_N][MAX_N * 2];
bool seen2[MAX_N][MAX_N * 2];

set<int> path1;
set<int> path2;

struct Edge
{
	int to;
	int weight;

	Edge(int t, int w)
		: to(t), weight(w)
	{

	}
};

struct Graph
{
	vector<Edge> *nbr;
	int num_nodes;

	Graph(int n) : num_nodes(n)
	{

		nbr = new vector<Edge>[num_nodes];
	}

	void add_edge(int u, int v, int weight)
	{
		nbr[u].push_back(Edge(v, weight));
	}
};

typedef vector<Edge>::iterator EdgeIter;

struct p
{
	int c;
	int cost;
};

void dfs(int N1, int N2, Graph U1, Graph U2)
{
	for(int i = 0; i < MAX_N; i++)
	{
		for(int j = 0; j < MAX_N * 2; j++)
		{
			seen1[i][j] = false;
			seen2[i][j] = false;
		}
	}

	stack<p> s1;
	p start;
	start.c = 1;
	start.cost = 0;
	s1.push(start);

	while(!s1.empty())
	{
		p cur = s1.top(); s1.pop();

		if(seen1[cur.c][cur.cost] == true)
			continue;

		seen1[cur.c][cur.cost] = true;

		if(cur.c == N1)
		{
			path1.insert(cur.cost);
		}

		for(EdgeIter it = U1.nbr[cur.c].begin(); it != U1.nbr[cur.c].end(); it++)
		{
			int v = it->to;
			p next;
			next.c = v;
			next.cost = cur.cost + 1;
			s1.push(next);
		}
	}

	stack<p> s2;
	p start2;
	start2.c = 1;
	start2.cost = 0;
	s2.push(start2);

	while(!s2.empty())
	{
		p cur = s2.top(); s2.pop();

		if(seen2[cur.c][cur.cost] == true)
			continue;

		seen2[cur.c][cur.cost] = true;

		if(cur.c == N2)
		{
			path2.insert(cur.cost);
		}

		for(EdgeIter it = U2.nbr[cur.c].begin(); it != U2.nbr[cur.c].end(); it++)
		{
			int v = it->to;
			p next;
			next.c = v;
			next.cost = cur.cost + 1;
			s2.push(next);
		}
	}
}


int main()
{
	int N1, N2, M1, M2;

	cin >> N1 >> N2 >> M1 >> M2;

	Graph U1(N1 + 1);
	Graph U2(N2 + 1);

	int u, v;

	for(int i = 0; i < M1; i++)
	{
		cin >> u >> v;
		U1.add_edge(u, v, 1);
	}

	for(int i = 0; i < M2; i++)
	{
		cin >> u >> v;
		U2.add_edge(u, v, 1);
	}

	dfs(N1, N2, U1, U2);

	set<int> value;

	for(auto a : path1)
	{
		for(auto b : path2)
		{
			value.insert(a + b);
		}
	}

	int Q;

	cin >> Q;

	while(Q--)
	{
		int q;

		cin >> q;

		if(value.find(q) == value.end())
		{
			cout << "No";
		}
		else
		{
			cout << "Yes";
		}

		cout << endl;
	}

	return 0;
}