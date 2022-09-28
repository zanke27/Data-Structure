#include<iostream>
#include<vector>
using namespace std;
#define MAX_VTXS 256
#define INF 9999

class AdjMatGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	int weight[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }

	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return weight[i][j]; }
	void setEdge(int i, int j, int val) { weight[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, INF);
	}
	void insertVertex(char name) {
		if (isFull()) return;
		vertices[size++] = name;
	}
	void insertEdge(int u, int v, int val) {
		if (isFull()) return;
		setEdge(u, v, val);
		setEdge(v, u, val);
	}
	void display() {
		if (isEmpty()) return;
		cout << "정점의 개수 : " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			cout << vertices[i] << "  ";
			for (int j = 0; j < size; j++)
				cout << weight[i][j] << " ";
			cout << "\n";
		}
	}
};

class shortestPath : public AdjMatGraph {
	int dist[MAX_VTXS];
	bool found[MAX_VTXS];
	int parent[MAX_VTXS];
public:
	void printDistance() {
		for (int i = 0; i < size; i++)
			cout << dist[i] << " ";
		cout << endl;
	}
	int chooseVertex() {
		int min = INF;
		int minpos = -1;
		for (int i = 0; i < size; i++) {
			if (found[i] == false && min > dist[i]) {
				min = dist[i];
				minpos = i;
			}
		}
		return minpos;
	}

	void dijikstra(int start, int end) {
		for (int i = 0; i < size; i++) {
			dist[i] = getEdge(start, i);
			found[i] = false;
		}
		fill_n(parent, size, -1);
		found[start] = true;
		dist[start] = 0;
		parent[start] = start;
		int next, current = start;
		cout << start << " 정점에서 시작!" << endl;
		for (int i = 0; i < size; i++) {
			if (current == end)
			{
				cout << "목적 정점 " << end << "에 도착!" << endl;
				break;
			}
			cout << "Step " << i + 1 << " : ";
			printDistance();
			next = chooseVertex();
			cout << next << " 정점에 안착 !" << endl;
			found[next] = true;
			for (int w = 0; w < size; w++){
				if (found[w] == false)
				{
					if (dist[next] + getEdge(next, w) < dist[w])
					{
						dist[w] = dist[next] + getEdge(next, w);
						parent[w] = next;
					}
				}
			}
			current = next;
		}

		vector <int> shortestPath;
		while (current != start) {
			shortestPath.push_back(current);
			current = parent[current];
			if (current == -1) break;
		}
		shortestPath.push_back(start);
		reverse(shortestPath.begin(), shortestPath.end());
		cout << start << "에서 " << end << "까지의 최단경로 : ";
		for (auto i : shortestPath) {
			cout << i << " ";
		}
	}
};



int main(void)
{
	shortestPath g;
	for (int i = 0; i < 7; i++)
		g.insertVertex('A' + i);

	g.insertEdge(0, 1, 2);
	g.insertEdge(0, 2, 7);
	g.insertEdge(1, 2, 1);
	g.insertEdge(1, 3, 3);
	g.insertEdge(2, 4, 4);
	g.insertEdge(2, 5, 5);
	g.insertEdge(3, 2, 2);
	g.insertEdge(3, 4, 3);
	g.insertEdge(4, 5, 4);
	g.insertEdge(4, 6, 1);
	g.insertEdge(5, 6, 5);
	g.dijikstra(0, 5);
}