#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int Find(int v) {
	while (true)
	{
		if (parent[v] != v)
			v = parent[v];
		else if (parent[v] == v)
			break;
	}
	return parent[v];
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) parent[a] = b;
}

struct Edge
{
	int s;
	int e;
	int value;

	Edge(int a, int b, int c) {
		s = a;
		e = b;
		value = c;
	}

	bool operator<(const Edge& b) const {
		return value < b.value;
	}
};

int main(void)
{
	vector<Edge> Ed;
	int i, n, m, a, b, c, cnt = 0, res = 0;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}

	sort(Ed.begin(), Ed.end());

	for (i = 0; i < m; i++) {
		int fa = Find(Ed[i].s);
		int fb = Find(Ed[i].e);
		if (fa != fb) {
			Union(fa, fb);
			res += Ed[i].value;
		}
	}
	cout << res;
}