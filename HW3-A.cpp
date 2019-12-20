#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct edge
{
	int to;
	int weight;
};

struct node
{
	int pre;
	int visit;
	int distance;
};

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int nb_nodes, nb_edges, start, terminal;
		cin >> nb_nodes >> nb_edges >> start >> terminal;
		vector<struct edge>* list = new vector<struct edge>[nb_nodes];
		struct node *nodes = new struct node[nb_nodes];
		struct node *nodes2 = new struct node[nb_nodes];
		for (int i = 0; i < nb_nodes; i++)
		{
			nodes[i].visit = 0;
			nodes[i].distance = 2147483640;
			nodes[i].pre = -1;
			nodes2[i].visit = 0;
			nodes2[i].distance = 2147483640;
			nodes2[i].pre = -1;
		}
		for (int i = 0; i < nb_edges; i++)
		{
			int from, to, w;
			cin >> from >> to >> w;
			struct edge tmp;
			tmp.to = to;
			tmp.weight = w;
			list[from].push_back(tmp);
		}

		// calculate the minimum distance needed to arrive the terminal node
		queue<int> q;
		q.push(start);
		nodes[start].visit = 1;
		nodes[start].distance = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			int dis = nodes[cur].distance + 1;
			for (int j = 0; j < list[cur].size(); j++)
			{
				int w = list[cur][j].weight;
				if (dis <= w)
				{
					int next = list[cur][j].to;
					if (nodes[next].visit == 0)
					{
						nodes[next].visit = 1;
						nodes[next].distance = dis;
						nodes[next].pre = cur;
						q.push(next);
					}

				}
			}
		}

		// consider the weight of edge
		queue<int> q2;
		q2.push(start);
		nodes2[start].visit = 1;
		nodes2[start].distance = 0;
		while (!q2.empty())
		{
			int cur = q2.front();
			q2.pop();
			int dis = nodes2[cur].distance + 1;
			for (int j = 0; j < list[cur].size(); j++)
			{
				int w = list[cur][j].weight;
				int next = list[cur][j].to;
				if (nodes2[next].visit == 0)
				{
					nodes2[next].visit = 1;
					nodes2[next].distance = dis;
					nodes2[next].pre = cur;
					q2.push(next);
				}
			}
		}
		if (nodes[terminal].visit == 1 && 
			nodes[terminal].distance == nodes2[terminal].distance)
			// compare whether the available path is the minimum path
		{
			int tmp = terminal;
			stack<int> print;
			print.push(terminal);
			while (nodes[tmp].pre >= 0)
			{
				tmp = nodes[tmp].pre;
				print.push(tmp);
			}
			while (!print.empty())
			{
				cout << print.top() << " ";
				print.pop();
			}
		}
		else
			cout << -1;
		cout << endl;
	}
	system("pause");
	return 0;
}