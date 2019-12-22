#include<iostream>
#include<string>
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int times;
	cin >> times;
	for(int time=1;time<=times;time++)
	{
		string model, change;
		int ins, del, sub;
		cin >> ins >> del >> sub;
		if (sub > ins + del)
			sub = ins + del;
		cin >> change;
		cin >> model;
		int len1 = change.length();
		int len2 = model.length();
		long long **D = new long long*[len1 + 1];
		for (int i = 0; i <= len1; i++)
			D[i] = new long long[len2 + 1];
		for (int j = 0; j <= len2; j++)
			D[0][j] = j * ins;
		for (int i = 0; i <= len1; i++)
			D[i][0] = i * del;

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				int add;
				if (change[i - 1] == model[j - 1])
					add = 0;
				else
					add = sub;
				D[i][j] = min(min(D[i - 1][j - 1] + add, D[i - 1][j] + del), D[i][j - 1] + ins);
			}
		}
		cout << D[len1][len2] << endl;;

	}
	system("PAUSE");
	return 0;
}