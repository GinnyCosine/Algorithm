#include<iostream>
using namespace std;

struct pos
{
	int p1;
	int p2;
	int parent;
};


struct pos *node;
int cur;
int print;
int *input;
int *used;
int first;
int len;

void tree(int root, int pre, int block)
{
	int stop;
	switch (block)
	{
	case 1:
		stop = node[root - 1].p1;
		break;
	case 2:
		stop = node[root - 1].p2;
		break;
	case 3:
		if (pre == 0)
		{
			stop = 2 * len;
			break;
		}
		stop = node[pre - 1].p1;
		while (used[stop] == 1)
		{
			stop = node[pre - 1].p2;
			if (used[stop] == 0)
				break;
			pre = node[pre - 1].parent;
			if (pre == 0)
			{
				stop = 2 * len;
				break;
			}
			stop = node[pre - 1].p1;
		}
		break;
	}
	if (cur == stop)
	{
		cur++;
		used[stop] = 1;
		return;
	}
	int n;
	input++;
	n= *input;
	node[n - 1].parent = root;
	tree(n, root, 1);
	tree(n, root, 2);
	tree(n, root, 3);
	cout << n << ' ';
}

int main()
{
	cin >> len;
	int *alice = new int[len];
	int *oscar = new int[len * 2];
	node = new struct pos[len];
	used = new int[len * 2];
	for (int i = 0; i < len; i++)
	{
		cin >> alice[i];
		node[i].p1 = -1;
		node[i].p2 = -1;
	}
	int len2 = len * 2;
	for (int i = 0; i < len2; i++)
	{
		cin >> oscar[i];
		used[i] = 0;
		if (node[oscar[i] - 1].p1 == -1)
			node[oscar[i] - 1].p1 = i;
		else
			node[oscar[i] - 1].p2 = i;
	}
	cur = 0;
	input = alice;
	first = alice[0];
	node[alice[0] - 1].parent = 0;
	tree(alice[0], 0, 1);
	tree(alice[0], 0, 2);
	tree(alice[0], 0, 3);
	cout << first << endl;
	system("pause");
	return 0;
}