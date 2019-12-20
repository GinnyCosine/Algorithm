#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	long long min_cost;
	int visit;
};

struct Edge
{
	int to;
	long long weight;
};

int ExtractMin(Node *nodes, int length)
{
	int min_id = -1;
	long long min_cost = 9223372036854775807;
	for (int i = 0; i < length; i++)
	{
		if (nodes[i].visit == 0 && nodes[i].min_cost < min_cost)
		{
			min_cost = nodes[i].min_cost;
			min_id = i;
		}
	}
	return min_id;
}

int main()
{
	long long total = 0;
	int nb_cities;
	cin >> nb_cities;
	int *build_cost = new int[nb_cities];
	long long *X = new long long[nb_cities];
	long long *Y = new long long[nb_cities];
	for (int i = 0; i < nb_cities; i++)
		cin >> build_cost[i];
	Node *nodes = new Node[nb_cities + 1];
	for (int i = 0; i < nb_cities; i++)
	{
		cin >> X[i] >> Y[i];
		nodes[i].min_cost = 9223372036854775807;
		nodes[i].visit = 0;
	}

	//start
	nodes[nb_cities].min_cost = 0;
	nodes[nb_cities].visit = 0;
	vector<Edge> *edges = new vector<Edge>[nb_cities + 1];
	for (int i = 0; i < nb_cities; i++)
	{
		for (int j = i + 1; j < nb_cities; j++)
		{
			long long w = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);

			Edge edge1 = { j,w };
			Edge edge2 = { i,w };
			edges[i].push_back(edge1);
			edges[j].push_back(edge2);
		}
	}

	for (int i = 0; i < nb_cities; i++)
	{
		Edge edge1 = { i,build_cost[i] };
		Edge edge2 = { nb_cities,build_cost[i] };
		edges[nb_cities].push_back(edge1);		//start
		edges[i].push_back(edge2);
	}

	// Prim Algorithm
	for (int i = 0; i < nb_cities + 1; i++)
	{
		int min_id = ExtractMin(nodes, nb_cities + 1);
		
		for (int j = 0; j < edges[min_id].size(); j++)
		{
			int next = edges[min_id][j].to;
			if (nodes[next].visit==0 && nodes[next].min_cost > edges[min_id][j].weight)
			{
				nodes[next].min_cost = edges[min_id][j].weight;
			}
		}
		nodes[min_id].visit = 1;
		total += nodes[min_id].min_cost;
	}
	cout << total;
	system("pause");
	return 0;
}