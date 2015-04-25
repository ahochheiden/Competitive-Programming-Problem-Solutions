#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdint>

using namespace std;

struct Edge {
	int64_t city;
	int64_t fuel;
	int64_t cost;

	Edge(int64_t cityInput, int64_t fuelInput, int64_t costInput) {
		city = cityInput;
		fuel = fuelInput;
		cost = costInput;
	}

	bool operator < (const Edge &edgeInput) const {
		return (cost > edgeInput.cost);
	}
};

int64_t price[1500];
int64_t state[1500][150];
vector<Edge> graph[1500];

int64_t numCities;
int64_t numRoads;
int64_t numQueries;

int64_t city1;
int64_t city2;
int64_t length;

int64_t fuelCapacity;
int64_t startingCity;
int64_t goal;

int64_t dist;
int64_t neighbor;
int64_t gas;

int64_t output;

int64_t dijkstras(int64_t &start, int64_t &goal, int64_t &cap);

int main() {
	cin >> numCities >> numRoads;
	for (int64_t i = 0; i < numCities; ++i) {
		cin >> price[i];
	}
	for (int64_t i = 0; i < numRoads; i++) {
		cin >> city1 >> city2 >> length;
		graph[city1].push_back(Edge(city2, 0, length));
		graph[city2].push_back(Edge(city1, 0, length));
	}
	cin >> numQueries;
	for (int64_t i = 0; i < numQueries; i++) {
		cin >> fuelCapacity >> startingCity >> goal;
		output = dijkstras(startingCity, goal, fuelCapacity);
		if (output == INT_MAX) {
			cout << "impossible" << endl;
		} else {
			cout << output << endl; 
		}
	}

	return 0;
}

int64_t dijkstras(int64_t &start, int64_t &goal, int64_t &cap) {
	priority_queue<Edge> pQueue;
	pQueue.push(Edge(start, 0, 0));
	for (int64_t i = 0; i < numCities; i++) {
		for (int64_t j = 0; j <= cap; j++) {
			state[i][j] = INT_MAX;
		}
	}

	state[start][0] = 0;

	while (pQueue.size()) {
		Edge edge = pQueue.top();
		pQueue.pop();
		if (edge.city == goal) {
			return edge.cost;
		}
		if (state[edge.city][edge.fuel] < edge.cost) {
			continue;
		}
		if ((edge.fuel < cap) && ((edge.cost + price[edge.city]) < (state[edge.city][edge.fuel + 1]))) {
			state[edge.city][edge.fuel + 1] = (edge.cost + price[edge.city]);
			pQueue.push(Edge(edge.city, edge.fuel + 1, edge.cost + price[edge.city]));
		}
		vector<Edge> v = graph[edge.city];
		for (int64_t j = 0; j < v.size(); ++j) {
			dist = v[j].cost;
			neighbor = v[j].city;
			if (edge.fuel >= dist) {
				gas = edge.fuel - dist;
				if (edge.cost < state[neighbor][gas]) {
					state[neighbor][gas] = edge.cost;
					pQueue.push(Edge(neighbor, gas, edge.cost));
				}
			}
		}
	}
	return INT_MAX;
}