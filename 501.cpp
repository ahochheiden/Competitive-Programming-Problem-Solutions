#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

void solve();

int k, m, n, temp, counter;

int main() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		if (i > 0) {
			cout << endl;
		}
		solve();
	}

	return 0;
}

void solve() {
	queue<int> getQueue, addQueue;
	priority_queue<int, vector<int>, greater<int> > min;
	priority_queue<int, vector<int>, less<int> > max;

	counter = 0;

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		addQueue.push(temp);
	}

	for (int i = 0; i < n; i++) {
		cin >> temp;
		getQueue.push(temp);
	}

	while (!addQueue.empty()) {
		if ((!min.empty()) && (addQueue.front() > max.top())) {
			min.push(addQueue.front());
		} else {
			max.push(addQueue.front());
		}
		addQueue.pop();

		while ((!getQueue.empty()) && (max.size() + min.size() == getQueue.front())) {
			while (max.size() != counter) {
				if (max.size() < counter) {
					max.push(min.top());
					min.pop();
				} else {
					if (max.size() > counter) {
						min.push(max.top());
						max.pop();
					}
				}
			}
			cout << min.top() << endl;
			counter++;
			getQueue.pop();
		}
	}
}