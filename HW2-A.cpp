#include<iostream>
#include<vector>
using namespace std;

int **form;
short **Z_min;
short **Z_max;
char **state_min;
char **state_max;
int len, goal;

void find_min_path(short i, short j, short & min_z, char & min_s)
{
	if (Z_min[i][j] > 0)
	{
		min_z = Z_min[i][j];
		min_s = state_min[i][j];
		return;
	}
	if (i == 0)
	{
		short z, left_z;
		char s, left_s;
		find_min_path(0, j - 1, left_z, left_s);
		if (form[i][j] > form[0][j - 1])
			s = '+';
		else
			s = '-';

		if (left_s == s)
			z = left_z;
		else
			z = left_z + 1;

		Z_min[i][j] = z;
		state_min[i][j] = s;
		min_s = s;
		min_z = z;
		return;
	}
	if (j == 0)
	{
		short z, up_z;
		char s, up_s;
		find_min_path(i - 1, 0, up_z, up_s);
		if (form[i][j] > form[i - 1][0])
			s = '+';
		else
			s = '-';

		if (up_s == s)
			z = up_z;
		else
			z = up_z + 1;

		Z_min[i][j] = z;
		state_min[i][j] = s;
		min_s = s;
		min_z = z;
		return;
	}

	short z1, z2, up_z, left_z;
	char s1, s2, up_s, left_s;
	find_min_path(i - 1, j, up_z, up_s);
	find_min_path(i, j - 1, left_z, left_s);

	if (form[i][j] > form[i - 1][j])
		s1 = '+';
	else
		s1 = '-';
	if (s1 == up_s)
		z1 = up_z;
	else
		z1 = up_z + 1;

	if (form[i][j] > form[i][j - 1])
		s2 = '+';
	else
		s2 = '-';
	if (s2 == left_s)
		z2 = left_z;
	else
		z2 = left_z + 1;
	
	if (z1 < z2)
	{
		Z_min[i][j] = z1;
		state_min[i][j] = s1;
		min_s = s1;
		min_z = z1;
	}
	else
	{
		Z_min[i][j] = z2;
		state_min[i][j] = s2;
		min_s = s2;
		min_z = z2;
	}
}

void find_max_path(short i, short j, short & max_z, char & max_s)
{
	if (Z_max[i][j] > 0)
	{
		max_z = Z_max[i][j];
		max_s = state_max[i][j];
		return;
	}
	if (i == 0)
	{
		short z, left_z;
		char s, left_s;
		find_max_path(0, j - 1, left_z, left_s);
		if (form[i][j] > form[0][j - 1])
			s = '+';
		else
			s = '-';

		if (left_s == s)
			z = left_z;
		else
			z = left_z + 1;

		Z_max[i][j] = z;
		state_max[i][j] = s;
		max_s = s;
		max_z = z;
		return;
	}
	if (j == 0)
	{
		short z, up_z;
		char s, up_s;
		find_max_path(i - 1, 0, up_z, up_s);
		if (form[i][j] > form[i - 1][0])
			s = '+';
		else
			s = '-';

		if (up_s == s)
			z = up_z;
		else
			z = up_z + 1;

		Z_max[i][j] = z;
		state_max[i][j] = s;
		max_s = s;
		max_z = z;
		return;
	}

	short z1, z2, up_z, left_z;
	char s1, s2, up_s, left_s;
	find_max_path(i - 1, j, up_z, up_s);
	find_max_path(i, j - 1, left_z, left_s);

	if (form[i][j] > form[i - 1][j])
		s1 = '+';
	else
		s1 = '-';
	if (s1 == up_s)
		z1 = up_z;
	else
		z1 = up_z + 1;

	if (form[i][j] > form[i][j - 1])
		s2 = '+';
	else
		s2 = '-';
	if (s2 == left_s)
		z2 = left_z;
	else
		z2 = left_z + 1;

	if (z1 > z2)
	{
		Z_max[i][j] = z1;
		state_max[i][j] = s1;
		max_s = s1;
		max_z = z1;
	}
	else
	{
		Z_max[i][j] = z2;
		state_max[i][j] = s2;
		max_s = s2;
		max_z = z2;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin >> len >> goal;
	form = new int*[len];
	Z_min = new short*[len];
	Z_max = new short*[len];
	state_min = new char*[len];
	state_max = new char*[len];
	for (int i = 0; i < len; i++)
	{
		form[i] = new int[len];
		Z_min[i] = new short[len];
		Z_max[i] = new short[len];
		state_min[i] = new char[len];
		state_max[i] = new char[len];
		for (int j = 0; j < len; j++)
		{
			cin >> form[i][j];
			Z_min[i][j] = -1;
			Z_max[i][j] = -1;
		}
	}

	//Initialize 0,1
	Z_min[0][1] = 1;
	Z_max[0][1] = 1;
	if (form[0][1] > form[0][0])
	{
		state_min[0][1] = '+';
		state_max[0][1] = '+';
	}
	else
	{
		state_min[0][1] = '-';
		state_max[0][1] = '-';
	}

	//Initialize 1,0
	Z_min[1][0] = 1;
	Z_max[1][0] = 1;
	if (form[1][0] > form[0][0])
	{
		state_min[1][0] = '+';
		state_max[1][0] = '+';
	}
	else
	{
		state_min[1][0] = '-';
		state_max[1][0] = '-';
	}
	short MAX_z, MIN_z;
	char MAX_s, MIN_s;
	find_max_path(len - 1, len - 1, MAX_z, MAX_s);
	find_min_path(len - 1, len - 1, MIN_z, MIN_s);
	if (goal >= MIN_z && goal <= MAX_z)
		cout << "Yes";
	else
		cout << "No";
	system("PAUSE");
	return 0;
}

