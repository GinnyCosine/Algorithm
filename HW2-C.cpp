#include<iostream>
using namespace std;

int heapsize;

void Heapify(int * A, int * B, int i)
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int large;
	if (left <= heapsize && A[left] > A[i])
		large = left;
	else
		large = i;
	if (right <= heapsize && A[right] > A[large])	//!!! large !!!
		large = right;
	if (large != i)
	{
		swap(A[i], A[large]);
		swap(B[i], B[large]);
		Heapify(A, B, large);
	}
}

void BuildHeap(int * A, int *B, int length)
{
	heapsize = length;


	for (int i = heapsize / 2; i >= 1; i--)
	{
		Heapify(A, B, i);
	}
}

void HeapSort(int * A, int *B, int length)
{
	BuildHeap(A, B, length);
	for (int i = length; i > 1; i--)
	{
		swap(A[1], A[i]);
		swap(B[1], B[i]);
		heapsize--;
		Heapify(A, B, 1);
	}
}


int main()
{
	int nb_dolls, limit;
	cin >> nb_dolls >> limit;
	int *weight = new int[nb_dolls + 1];
	int *value = new int[nb_dolls + 1];
	long long **form = new long long*[nb_dolls + 1];
	int **max_size = new int*[nb_dolls + 1];
	for (int i = 1; i <= nb_dolls; i++)
	{
		cin >> weight[i] >> value[i];
		form[i] = new long long[limit + 1];
		max_size[i] = new int[limit + 1];
	}
	form[0] = new long long[limit + 1];
	max_size[0] = new int[limit + 1];
	form[nb_dolls] = new long long[limit + 1];
	max_size[nb_dolls] = new int[limit + 1];

	//陣列初始化成0
	for (int i = 0; i <= nb_dolls; i++)
	{
		for (int j = 0; j <= limit; j++)
		{
			form[i][j] = 0;
			max_size[i][j] = 0;
		}
	}

	HeapSort(weight, value, nb_dolls);

	for (int i = 0; i < nb_dolls; ++i)		// 窮舉每種物品
	{
		for (int j = 0; j <= limit; ++j)
		{					
			int size = weight[i + 1];		// 窮舉每種重量
			if (j - size < 0)
			{
				form[i + 1][j] = form[i][j];
				max_size[i + 1][j] = max_size[i][j];
			}
			else
			{
				long long a = form[i][j];
				long long b = 0;
				
				int head = 0;
				int tail = i;
				int pre = 0;
				int mid = (head + tail) / 2;
				while (head < tail)
				{
					if (max_size[mid][j - size] * 2 == size)
					{
						break;
					}
					else if (max_size[mid][j - size] * 2 > size)
					{
						tail = mid - 1;
						mid = (head + tail) / 2;
					}
					else
					{
						head = mid + 1;
						pre = mid;
						mid = (head + tail) / 2;
					}
				}
				if(max_size[mid][j - size] * 2 <= size)
					b = form[mid][j - size] + value[i + 1];
				else
					b = form[pre][j - size] + value[i + 1];
				
				if (a >= b)
				{
					form[i + 1][j] = a;
					max_size[i + 1][j] = max_size[i][j];
				}
				else
				{
					form[i + 1][j] = b;
					max_size[i + 1][j] = size;
				}
			}
		}
	}
	
	cout << form[nb_dolls][limit];

	system("PAUSE");
	return 0;
}

/*
print


	for (int i = 0; i <= nb_dolls; i++)
	{
		for (int j = 0; j <= limit; j++)
		{
			if (form[i][j] < 10)
				cout << " ";
			if (form[i][j] < 100)
				cout << " ";
			cout << form[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i <= nb_dolls; i++)
	{
		for (int j = 0; j <= limit; j++)
		{

			cout << max_size[i][j] << " ";
		}
		cout << "\n";
	}

*/