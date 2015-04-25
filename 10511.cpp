#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdint>

using namespace std;

int64_t caseCount = 1;
int64_t numCases;
int64_t maxFlow;
int64_t maxParty;
int64_t sent;
int64_t n;

int64_t g[1500][1500];
bool v[1500];

string input, sm, sp, sc;
map<string, int64_t> everyMan;
map<string, int64_t> everyParty;
map<string, int64_t> everyClub;

void solve();
void calc();
int64_t send(int64_t s, int64_t t, int64_t m);
int64_t f(string& input, map<string, int64_t> &map);

int main() {
	cin >> numCases;
	getline(cin, input); 
	getline(cin, input);

	for (int64_t i = 0; i < numCases; i++) {
		solve();
	}

	return 0;
}

void solve() {
	everyClub.clear(); 
	everyParty.clear(); 
	everyMan.clear();
	memset(g, 0, sizeof(g));
	memset(v, 0, sizeof(v));
	maxFlow = 0;
	n = 2;

	while (getline(cin, input)) {
		if ((input == "") || (input == " ")) {
			break;
		} else {
			stringstream sin(input);
			sin >> sm >> sp;
			g[f(sp, everyParty)][f(sm, everyMan)] = 1;
			while (sin >> sc) {
				g[f(sm, everyMan)][f(sc, everyClub)] = 1;
				g[f(sc, everyClub)][2] = 1;
			}
		}
	}

	calc();

	if (maxFlow == everyClub.size()) {
		for (map<string, int64_t>::iterator i = everyMan.begin(); i != everyMan.end(); i++) {
			for (map<string, int64_t>::iterator j = everyClub.begin(); j != everyClub.end(); j++) {
				if (g[j->second][i->second]) {
					cout << i->first << " " << j->first << endl;
				}
			}
		}
	} else {
		cout << "Impossible." << endl;
	}

	if ((caseCount > 0) && (caseCount < numCases)) {
		cout << endl;
	}
	caseCount++;
}

void calc() {
	maxParty = (everyClub.size() - 1) / 2;
	for (map<string, int64_t>::iterator it = everyParty.begin(); it != everyParty.end(); it++) {
		g[1][it->second] = maxParty;
	}

	while (sent = send(1, 2, INT_MAX)) {
		maxFlow += sent;
		memset(v, 0, sizeof(v));
	}
}

int64_t send(int64_t s, int64_t t, int64_t m) {
	v[s] = true;

	if (s == t) {
		return m;
	}

	for (int64_t i = 1; i <= n; i++) {
		if (!v[i] && g[s][i] > 0) {
			if (sent = send(i, t, min(m, g[s][i]))) {
				g[s][i] -= sent;
				g[i][s] += sent;
				return sent;
			}
		}
	}

	return 0;
}

int64_t f(string& in, map<string, int64_t> &map) {
	if (map.find(in) != map.end()) {
		return map[in];
	} else { 
		return map[in] = ++n; 
	}
}