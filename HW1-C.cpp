#include<iostream>
using namespace std;

int **ans;

void calculate(int x, int y, int size,int **arr,int a,int b)
{
	int s1 = x - a;
	int s2 = y - b;
	if (size == 2)
	{
		ans[x][y] = arr[s1][s2] + arr[s1 + 1][s2];
		ans[x][y + 1] = arr[s1][s2 + 1] + arr[s1 + 1][s2 + 1];
		ans[x + 1][y] = arr[s1][s2] - arr[s1 + 1][s2];
		ans[x + 1][y + 1] = arr[s1][s2 + 1] - arr[s1 + 1][s2 + 1];
		return;
	}
	int half = size / 2;
	int **tmp = new int *[size];
	for (int i = 0; i < half; i++)
	{
		tmp[i] = new int[size];
		for (int j = 0; j < size; j++)
			tmp[i][j] = arr[s1 + i][s2 + j] + arr[s1 + i + half][s2 + j];
	}
	for (int i = half; i < size; i++)
	{
		tmp[i] = new int[size];
		for (int j = 0; j < size; j++)
			tmp[i][j] = arr[s1 + i - half][s2 + j] - arr[s1 + i][s2 + j];
	}
	calculate(x, y, half, tmp, x, y);
	calculate(x + half, y, half, tmp, x, y);
	calculate(x, y + half, half, tmp, x, y);
	calculate(x + half, y + half, half, tmp, x, y);
	for (int i = 0; i < size; i++)
	{
		delete[]tmp[i];
	}
	delete[]tmp;
}

int main()
{
	int size;
	cin >> size;
	int **input = new int *[size];
	ans = new int *[size];
	for (int i = 0; i < size; i++)
	{
		input[i] = new int[size];
		ans[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			cin >> input[i][j];
		}
	}
	calculate(0, 0, size, input, 0, 0);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}