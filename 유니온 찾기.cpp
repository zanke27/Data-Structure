#include <iostream>
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

int main(void)
{
	int i, n, m, a, b, fa, fb, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (i = 1; i <= m; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	cin >> a >> b;
	fa = Find(a);
	fb = Find(b);
	if (fa == fb) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}