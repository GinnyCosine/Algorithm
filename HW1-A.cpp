#include<iostream>
#include<cmath>
using namespace std;
long long k;
int test(long long n)
{
	int l2 = log2(n);
	int sq = sqrt(n);
	if((((k * 1000000000 / n) / sq) / l2) >= 1)
		return 1;
	return 0;
}


int main()
{
	int times;
	cin >> times;
	while (times--)
	{
		cin >> k;
		//int *limit = new int[7];

		//�]�}�Y
		long long nb1;
		long long nb;
		long long nb3;
		int flg;
		if (k < 10)
		{
			nb1 = 151321;
			nb3 = 652187;
			if (k < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (10 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 100)
		{
			nb1 = 652189;
			nb3 = 2831095;
			if (k - 10 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (100 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 1000)
		{
			nb1 = 2831097;
			nb3 = 12365829;
			if (k - 100 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (1000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 10000)
		{
			nb1 = 12365831;
			nb3 = 54288815;
			if (k - 1000 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (10000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 100000)
		{
			nb1 = 54288817;
			nb3 = 239382782;
			if (k - 10000 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (100000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 1000000)
		{
			nb1 = 239382784;
			nb3 = 1059437399;
			if (k - 100000 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (1000000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 10000000)
		{
			nb1 = 1059437401;
			nb3 = 4605069259;
			if (k - 1000000 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (10000000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else if (k < 100000000)
		{
			nb1 = 4605069260;
			nb3 = 20528047059;
			if (k - 10000000 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (100000000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else  if (k < 1000000000)
		{
			nb1 = 20528047061;
			nb3 = 91720332232;
			if (k - 100000000 < 10)
			{
				nb = nb1;
				flg = 1;
			}
			else if (1000000000 - k < 10)
			{
				nb = nb3;
				flg = 2;
			}
			else
			{
				nb = (nb1 + nb3) / 2;
				flg = 3;
			}
		}
		else
		{
			cout << 91720332233 << endl;
			continue;
		}
		
		//nb = 91719047060;
		//flg = 1;
		switch (flg)
		{
		case 1:
			while (test(nb))
				nb++;
			cout << nb - 1 << endl;
			break;
		case 2:
			while (test(nb) == 0)
				nb--;
			cout << nb << endl;
			break;
		case 3:
			int t1 = test(nb);
			int t2 = test(nb + 1);
			while (!(t1 == 1 && t2 == 0))
			{
				if (t1 == 1)
				{
					nb1 = nb;
					nb = (nb + nb3) / 2;
				}
				else
				{
					nb3 = nb;
					nb = (nb + nb1) / 2;
				}
				t1 = test(nb);
				t2 = test(nb + 1);
			}
			cout << nb << endl;
			break;
		}
	}
	system("PAUSE");
	return 0;
}