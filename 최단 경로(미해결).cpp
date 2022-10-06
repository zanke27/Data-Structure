#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E, start, u, v, w;
vector<pair<int, int>> weight[20001];
const int INF = 999999999;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector <int> dijikstra(int start, int vertex)
{
	vector<int> dist(vertex, INF);
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (pq.empty()) {
		int now = pq.top().second;
		int sToNow = pq.top().first;
		pq.pop();

		if (dist[now] != sToNow) continue;
	
		for (auto n : weight[now]) {
			int neightbor = n.second;
			int NowToNeightbor = n.first;
			//if (neightbor + NowToNeightbor) {
			//	
			//	pq.push(make_pair(dist[neightbor], neightbor));
			//}
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> start;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		weight[u].emplace_back(w, v);
	}

	vector<int> result = dijikstra(start, V + 1);

	for (int i = 1; i <= V; i++) {
		if (result[i] == INF) cout << "INF" << "\n";
		else cout << result[i] << "\n";	
	}
	return 0;
}