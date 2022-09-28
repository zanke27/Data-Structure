#include <iostream>
#include <vector>
using namespace std;

void DFS(int x, int y);

const int MAX = 50;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int field[MAX][MAX] = { 0, }, n, m, k, t, x, y, nx, ny, ret, result;
bool visited[MAX][MAX];
int main(void)
{

	cin >> t;
	for (int i = 0; i < t; i++) {
		fill_n(field[0], MAX * MAX, 0);
		fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);

		cin >> n >> m >> k;
		ret = 0;
		for (int i = 0; i < k; i++) {			
			cin >> x >> y;
			field[y][x] = 1;
		}
		
		//visited[y][x] = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (field[j][i] != 0 && visited[j][i] == false)
				{
					result++;
					DFS(j, i);
				}
			}
		}

		cout << result << endl;
		result = 0;
	}
}

void DFS(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (ny < 0 || ny > MAX-1 || nx < 0 || nx > MAX-1) continue;
		if (field[ny][nx] != 0 && visited[ny][nx] == false)
		{
			//cout << &"visited[{nx}][{ny}]" << endl;
			DFS(ny, nx);
		}
	}
}