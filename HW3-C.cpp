#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int goal;

struct Node
{
	int pre;
	int visit;
};

int MaximumFlow(vector<Node> nodes, vector<vector<int>> adjacent_list, int terminal)
									// use vector instead of pointer since we don't want 
									// the adjacent list in main be modified 
{
	vector<Node> tmp;
	vector<vector<int>> list;
	int flow = 0;
	while (flow < goal)
	{
		tmp = nodes;	//each time run BFS the nodes should be initialized
		queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			tmp[cur].visit = 1;
			for (int i = 0; i < n*2 + 2; i++)
			{
				if (adjacent_list[cur][i] > 0 && tmp[i].visit == 0)
				{
					tmp[i].visit = 1;	//cannot update adjacent list here !!!!
					tmp[i].pre = cur;
					q.push(i);
				}
			}
			if (tmp[terminal].visit == 1)
				break;
		}
		if (tmp[terminal].visit == 1)
		{
			int t = terminal;
			while (tmp[t].pre != -1)
			{
				adjacent_list[tmp[t].pre][t] -= 1;	//update adjacent list
				adjacent_list[t][tmp[t].pre] += 1;	//used edge -1 and the reverse direction +1
				t = tmp[t].pre;
			}
			flow++;	//count the maximum flow
		}
		else
			break;
	}
	if (flow >= goal)
		return 1;
	else
		return 0;
}

int main()
{
	cin >> n >> m;
	int **form = new int*[n];
	goal = n;
	for (int i = 0; i < n; i++)
	{
		form[i] = new int[m];
		for (int j = 0; j < m; j++)
			form[i][j] = 0;
	}
	vector<Node> nodes;
	for (int i = 0; i < 2 * n + 2; i++)
	{
		nodes.push_back({ -1,0 });
	}
	vector<vector<int>>adjacent_list(2 * n + 2);
	for (int i = 0; i < n*2 + 2; i++)
	{
		adjacent_list[i].resize(2 * n + 2);
		for (int j = 0; j < n * 2 + 2; ++j)
			adjacent_list[i][j] = 0;
	}
	int terminal = n * 2 + 1;
	int nb;
	char c;
	for (int i = 1; i <= n; i++)
	{
		adjacent_list[0][i] = 1;
		adjacent_list[n + i][terminal] = 1;
		for (int j = 1; j <= m; j++)
		{
			cin >> nb >> c;
			form[nb - 1][c - 'A'] = i;	//memorize the combinations of number and alphabet occur at which piles
			adjacent_list[i][nb + n] += 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)	//check each number in the smallest lexicographic order
		{
			if (adjacent_list[0][form[i][j]] == 1 &&
				adjacent_list[i + 1 + n][terminal] == 1)
			{
				// i -> number(rank)	j -> Alphabet
				adjacent_list[0][form[i][j]] = 0;		// check whether the combination  we choose
				adjacent_list[i + 1 + n][terminal] = 0;	// can generate the answer (use maximum flow)
				goal = n - i - 1;
				if (MaximumFlow(nodes, adjacent_list, terminal) == 1)
				{
					cout << i + 1 << (char)('A' + j) << " ";
					break;
				}
				else
				{
					adjacent_list[0][form[i][j]] = 1;
					adjacent_list[i + 1 + n][terminal] = 1;
				}
			}
		}
	}
	system("pause");
	return 0;
}