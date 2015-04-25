/*
* Suffix array
*
* Author: Howard Cheng
* References:
*   Manber, U. and Myers, G.  "Suffix Arrays: a New Method for On-line
*   String Searches."  SIAM Journal on Computing.  22(5) p. 935-948, 1993.
*
*   T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park.  "Linear-time
*   Longest-common-prefix Computation in Suffix Arrays and Its
*   Applications."  Proc. 12th Annual Conference on Combinatorial
*   Pattern Matching, LNCS 2089, p. 181-192, 2001
*
*   J. Kärkkäinen and P. Sanders. Simple linear work suffix array
*   construction.  In Proc. 13th International Conference on Automata,
*   Languages and Programming, Springer, 2003
*
* The build_sarray routine takes in a string str of n characters (null-
* terminated), and construct an array sarray.  Optionally, you can also
* construct an lcp array from the sarray computed.  The properties
* are:
*
* - If p = sarray[i], then the suffix of str starting at p (i.e.
*   str[p..n-1] is the i-th suffix when all the suffixes are sorted in
*   lexicographical order
*
*   NOTE: the empty suffix is not included in this list, so sarray[0] != n.
*
* - lcp[i] contains the length of the longest common prefix of the suffixes
*   pointed to by sarray[i-1] and sarray[i].  lcp[0] is defined to be 0.
*
* - To see whether a pattern P occurs in str, you can look for it as
*   the prefix of a suffix.  This can be done with a binary search in
*   O(|P| log n) time.  Call find() to return a pair <L, R> such that
*   all occurrences of the pattern are at positions sarray[i] with
*   L <= i < R.  If L == R then there is no match.
*
* The construction of the suffix array takes O(n) time.
*
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdint>

using namespace std;

bool leq(int64_t a1, int64_t a2, int64_t b1, int64_t b2) {
	return(a1 < b1 || a1 == b1 && a2 <= b2);
}

bool leq(int64_t a1, int64_t a2, int64_t a3, int64_t b1, int64_t b2, int64_t b3) {
	return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}

void radixPass(int64_t* a, int64_t* b, int64_t* r, int64_t n, int64_t K) {
	int64_t* c = new int64_t[K + 1];
	fill(c, c + K + 1, 0);
	for (int64_t i = 0; i < n; i++) c[r[a[i]]]++;
	for (int64_t i = 0, sum = 0; i <= K; i++) {
		int64_t t = c[i];  c[i] = sum;  sum += t;
	}
	for (int64_t i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
	delete[] c;
}

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

void sarray_int(int64_t* s, int64_t* SA, int64_t n, int64_t K) {
	int64_t n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
	int64_t* s12 = new int64_t[n02 + 3];  s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
	int64_t* SA12 = new int64_t[n02 + 3]; SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
	int64_t* s0 = new int64_t[n0];
	int64_t* SA0 = new int64_t[n0];

	for (int64_t i = 0, j = 0; i < n + (n0 - n1); i++) if (i % 3 != 0) s12[j++] = i;

	radixPass(s12, SA12, s + 2, n02, K);
	radixPass(SA12, s12, s + 1, n02, K);
	radixPass(s12, SA12, s, n02, K);

	int64_t name = 0, c0 = -1, c1 = -1, c2 = -1;
	for (int64_t i = 0; i < n02; i++) {
		if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
			name++;  c0 = s[SA12[i]];  c1 = s[SA12[i] + 1];  c2 = s[SA12[i] + 2];
		}
		if (SA12[i] % 3 == 1) { s12[SA12[i] / 3] = name; } else { s12[SA12[i] / 3 + n0] = name; }
	}

	if (name < n02) {
		sarray_int(s12, SA12, n02, name);
		for (int64_t i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
	} else
		for (int64_t i = 0; i < n02; i++) SA12[s12[i] - 1] = i;

	for (int64_t i = 0, j = 0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
	radixPass(s0, SA0, s, n0, K);

	for (int64_t p = 0, t = n0 - n1, k = 0; k < n; k++) {
		int64_t i = GetI();
		int64_t j = SA0[p];
		if (SA12[t] < n0 ?
			leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]) :
			leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0])) {
			SA[k] = i;  t++;
			if (t == n02) {
				for (k++; p < n0; p++, k++) SA[k] = SA0[p];
			}
		} else {
			SA[k] = j;  p++;
			if (p == n0) {
				for (k++; t < n02; t++, k++) SA[k] = GetI();
			}
		}
	}
	delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}

void build_sarray(string str, int64_t sarray[]) {
	int64_t n = str.length();

	if (n <= 1) {
		for (int64_t i = 0; i < n; i++) {
			sarray[i] = i;
		}
		return;
	}

	int64_t *s = new int64_t[n + 3];
	int64_t *SA = new int64_t[n + 3];
	for (int64_t i = 0; i < n; i++) {
		s[i] = (int64_t)str[i] - CHAR_MIN + 1;
	}
	s[n] = s[n + 1] = s[n + 2] = 0;
	sarray_int(s, SA, n, 256);
	copy(SA, SA + n, sarray);

	delete[] s;
	delete[] SA;
}

void compute_lcp(string str, int64_t sarray[], int64_t lcp[]) {
	int64_t n = str.length();
	int64_t *rank = new int64_t[n];
	for (int64_t i = 0; i < n; i++) {
		rank[sarray[i]] = i;
	}
	int64_t h = 0;
	for (int64_t i = 0; i < n; i++) {
		int64_t k = rank[i];
		if (k == 0) {
			lcp[k] = -1;
		} else {
			int64_t j = sarray[k - 1];
			while (i + h < n && j + h < n && str[i + h] == str[j + h]) {
				h++;
			}
			lcp[k] = h;
		}
		if (h > 0) {
			h--;
		}
	}
	lcp[0] = 0;
	delete[] rank;
}

pair<int64_t, int64_t> find(const string &str, const int64_t sarray[],
	const string &pattern) {
	int64_t n = str.length(), p = pattern.length();
	int64_t L, R;

	if (pattern <= str.substr(sarray[0], p)) {
		L = 0;
	} else if (pattern > str.substr(sarray[n - 1], p)) {
		L = n;
	} else {
		int64_t lo = 0, hi = n - 1;
		while (hi - lo > 1) {
			int64_t mid = lo + (hi - lo) / 2;
			if (pattern <= str.substr(sarray[mid], p)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		L = hi;
	}

	if (pattern < str.substr(sarray[0], p)) {
		R = 0;
	} else if (pattern >= str.substr(sarray[n - 1], p)) {
		R = n;
	} else {
		int64_t lo = 0, hi = n - 1;
		while (hi - lo > 1) {
			int64_t mid = lo + (hi - lo) / 2;
			if (pattern < str.substr(sarray[mid], p)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		R = hi;
	}

	if (L > R) R = L;
	return make_pair(L, R);
}

int64_t numCases;
string inputString;
string outputString;
int64_t SA[100500];
int64_t LCP[100500];
int64_t repCounter;
int64_t maxi;
int64_t sa;

void solve();

int main() {
	cin >> numCases;
	for (int64_t i = 0; i < numCases; i++) {
		solve();
	}

	return 0;
}

void solve() {
	cin >> inputString;

	outputString.clear();
	maxi = 0;
	sa = 0;

	if (inputString.size() > 0) {
		build_sarray(inputString, SA);
		compute_lcp(inputString, SA, LCP);
		for (int64_t i = 0; i < inputString.size(); i++) {
			if (LCP[i] > maxi) {
				sa = i;
				maxi = LCP[i];
			}
		}
	}

	if (maxi == 0) {
		cout << "No repetitions found!" << endl;
	} else {
		repCounter = 2;
		for (int64_t i = sa + 1; (i < inputString.size()) && (LCP[i] >= maxi); i++) {
			repCounter++;
		}
		for (int64_t i = 0; i < maxi; i++) {
			outputString += inputString[SA[sa] + i];
		}
		cout << outputString << " " << repCounter << endl;
	}
}