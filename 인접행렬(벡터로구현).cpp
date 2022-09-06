#include <iostream>
#include <vector>
using namespace std;
#define MAX_VTXS 256

class AdjMatGraph
{
protected:
	int size;
	vector<char> vertices;
	vector<vector<int>> adj;
public:
	AdjMatGraph(int num) { reset(num); }

	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	void setSize(int siz)
	{
		vertices.resize(siz, 0);
		adj.resize(siz, vector<int>(siz, 0));
	}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset(int num) {
		size = 0;
		setSize(num);
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
		cout << "������ ���� : " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			cout << vertices[i] << "  ";
			for (int j = 0; j < size; j++)
				cout << adj[i][j] << " ";
			cout << "\n";
		}
	}
};

int main(void)
{
	int verSize = 4;
	AdjMatGraph g(verSize);

	for (int i = 0; i < verSize; i++)
		g.insertVertex('A' + i);

	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	cout << "���� ��ķ� ǥ���� �׷���" << "\n";
	g.display();
}