#include<iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define long_long_min (-9223372036854775808)
using namespace std;

long long**dp;
long long *nbs;
long long cal;
long long cur;

/*
long long positive(int i, int j)
{
	if (dp[i][j] != long_long_min)
	{
		return dp[i][j];
	}
	if (i == 0 && j == 0)
	{
		dp[i][j] = nbs[0];
		cal = MAX(cal, dp[i][j]);
		return dp[i][j];
	}
	if (i == 0)
	{
		long long A = positive(i, j - 1);
		dp[i][j] = MAX(A, 0) + nbs[j];
		cal = MAX(cal, dp[i][j]);
		return dp[i][j];
	}

	long long tmp = positive(i - 1, j - 2);
	long long B = 0;
	if (j != i * 2)
		B = positive(i, j - 1);
	cur = MAX(tmp, cur);
	dp[i][j] = MAX(B, cur) + nbs[j];
	cal = MAX(cal, dp[i][j]);
	return dp[i][j];
}

long long negative(int i, int j)
{
	if (dp[i][j] != long_long_min)
	{
		return dp[i][j];
	}
	//if (i == 0 && j == 0)
	//{
	//	dp[i][j] = nbs[0];
	//	cal = MIN(cal, dp[i][j]);
	//	return dp[i][j];
	//}
	//if (i == 0)
	//{
	//	long long A = negative(i, j - 1);
	//	dp[i][j] = MIN(A, 0) + nbs[j];
	//	cal = MIN(cal, dp[i][j]);
	//	return dp[i][j];
	//}
	long long tmp = negative(i - 1, j - 2);
	cur = MIN(tmp, cur);
	long long B = 0;
	if (j != i * 2)
		B = negative(i, j - 1);
	dp[i][j] = MIN(B, cur) + nbs[j];
	cal = MIN(cal, dp[i][j]);
	return dp[i][j];
}
*/
int main()
{
	int times;
	cin >> times;
	while (times--)
	{
		cal = 0;
		int len, pick, multiplier;
		cin >> len >> pick >> multiplier;
		nbs = new long long[len];
		dp = new long long*[2];
		long long sum = 0;
		for (int i = 0; i < len; i++)
		{
			cin >> nbs[i];
			sum += nbs[i];
		}
		for (int k = 0; k < 2; k++)
		{
			dp[k] = new long long[len];
			for (int i = 0; i < len; i++)
				dp[k][i] = -92233720368547758;
		}
		if (multiplier > 0)
		{
			int a = 1, b = 0;
			dp[0][0] = nbs[0];
			cal = MAX(cal, dp[0][0]);
			for (int j = 1; j < len; j++)
			{
				dp[0][j] = MAX(dp[0][j - 1], 0) + nbs[j];
				cal = MAX(cal, dp[0][j]);
			}
			for (int i = 1; i < pick; i++)
			{
				for (int j = i * 2; j < len; j++)
				{
					cur = MAX(dp[b][j - 2], cur);
					long long B = 0;
					if (j != i * 2)
						B = dp[a][j - 1];
					dp[a][j] = MAX(B, cur) + nbs[j];
					cal = MAX(cal, dp[a][j]);
					//dp[0][j - 2] = dp[1][j - 2];
				}
				//dp[0][len - 2] = dp[1][len - 2];
				//dp[0][len - 1] = dp[1][len - 1];
				if (a == 0)
				{
					a = 1;
					b = 0;
				}
				else
				{
					a = 0;
					b = 1;
				}
				cur = 0;
			}
		}
		else
		{
			int a = 1, b = 0;
			dp[0][0] = nbs[0];
			cal = MIN(cal, dp[0][0]);
			for (int j = 1; j < len; j++)
			{
				dp[0][j] = MIN(dp[0][j - 1], 0) + nbs[j];
				cal = MIN(cal, dp[0][j]);
			}
			for (int i = 1; i < pick; i++)
			{
				for (int j = i * 2; j < len; j++)
				{
					cur = MIN(dp[b][j - 2], cur);
					long long B = 0;
					if (j != i * 2)
						B = dp[a][j - 1];
					dp[a][j] = MIN(B, cur) + nbs[j];
					cal = MIN(cal, dp[a][j]);
					//dp[b][j - 2] = dp[a][j - 2];
				}
				//dp[0][len - 2] = dp[1][len - 2];
				//dp[0][len - 1] = dp[1][len - 1];
				if (a == 0)
				{
					a = 1;
					b = 0;
				}
				else
				{
					a = 0;
					b = 1;
				}
				cur = 0;
			}
		}
		cout << cal * multiplier + sum - cal << endl;
	}
		system("PAUSE");
	return 0;
}