#include<iostream>
#include<cmath>
using namespace std;

long long GCD(long long a, long long b)
{
	if (a == 1 || b == 1)
		return 1;
	if (a == b)
		return a;
	if (a > b)
	{
		while (b > 0)
		{
			long long c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	while (a > 0)
	{
		long long c = b % a;
		b = a;
		a = c;
	}
	return b;
}

int search()
{
	return 0;

}

int main()
{
	long long table[10][17] = { 0 };

	int n;
	cin >> n;
	int m = log2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> table[i][0];
	}
	for (int j = 1; j <= m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			table[i][j] = GCD(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
	
	system("PAUSE");
	return 0;
}