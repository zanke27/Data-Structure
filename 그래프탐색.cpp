#include <iostream>
#include <queue>
using namespace std;
#define MAX_VTXS 256

class AdjMatGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }

	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}
	void insertVertex(char name) {
		if (isFull()) return;
		vertices[size++] = name;
	}
	void insertEdge(int u, int v) {
		if (isFull()) return;
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}
	void display() {
		if (isEmpty()) return;
		cout << "정점의 개수 : " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			cout << vertices[i] << "  ";
			for (int j = 0; j < size; j++)
				cout << adj[i][j] << " ";
			cout << "\n";
		}
	}
};

class SearchGraph : public AdjMatGraph
{
	int visited[MAX_VTXS];
	queue<char> q;
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v) {
		visited[v] = true;
		cout << vertices[v] << " ";
		for (int i = 0; i < size; i++)
		{
			if (isLinked(v, i) && visited[i] == false)
				DFS(i);
		}
	}

	//void BFS(int v) {
	//	visited[v] = true;
	//	q.push(v);
	//	while (!q.empty())
	//	{
	//		int temp = q.front();
	//		cout << getVertex(temp) << " ";
	//		q.pop();
	//		for (int i = 0; i < size; i++)
	//		{
	//			if (isLinked(temp, i) && visited[i] == false)
	//			{
	//				visited[i] = true;
	//				q.push(i);
	//			}
	//		}
	//	}
	//}

	void BFS(int v)
	{
		fill_n(visited, MAX_VTXS, -1);
		visited[v] = 0;
		queue<char> q;
		q.push(v);
		while (!q.empty())
		{
			int i = q.front();
			//cout << getVertex(i) << " ";
			q.pop();
			for (int j = 0; j < size; j++)
			{
				if (isLinked(i, j) && visited[j] < 0)
				{
					visited[j] += visited[i] + 2; // 1로하면 안됨
					q.push(j);
				}
			}
		}
		cout << endl << "A에서 각 정점까지의 거리 : ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << visited[i];
		}
 	}
};

int main(void)
{
	SearchGraph g;

	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);

	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	cout << "인접 행렬로 표현할 그래프" << endl;
	g.display();
	//cout << "DFS 탐색 => ";
	//g.resetVisited();
	//g.DFS(0);
	g.BFS(0);
}