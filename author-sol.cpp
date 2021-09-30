#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	// create an adjacency list using three-dimensional vectors (with cost)
	// if cost is 0, then it means one edge is connected, otherwise it means that it needs to be reverted
	vector<vector<vector<int>>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, 1});
	}
	// perform dijkstra's algorithm
	priority_queue<pair<int, int>> q;
	vector<int> distance(n + 1, MAX);
	q.push({0, 1});
	distance[1] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		for (auto val : adj[u]) {
			int v = val[0];
			int weight = val[1];
			if (distance[v] > distance[u] + weight) {
				distance[v] = distance[u] + weight;
				q.push({-weight, v});
			}
		}
	}
	cout << (distance[n] == MAX ? -1 : distance[n]) << '\n';
	return 0;
}
