#include <iostream>
#include <time.h>

using namespace std;

void Generate(int* a, const int n, int low, int high, int i)
{
	a[i] = low + rand() % (high - low + 1);
	if (i < n - 1)
		Generate(a, n, low, high, i + 1);
}

void print(int* a, const int n, int i)
{
	cout << a[i] << " ";
	if (i < n - 1)
		print(a, n, i + 1);
}

int Multiple(int* a, const int n, int i, int p)
{
	if (i % 2 == 0 && i != 0)
			  p *= a[i];
	if (i < n - 1)
		return Multiple(a, n, i + 1, p);
	else
		return p;
}

int findfirst(int* a, const int n, int i)
{
		if (a[i] == 0)
			return i;
		if (i < n - 1)
			return findfirst(a, n, i + 1);
		else
			return -1;
}

int findlast(int* a, const int n, int i)
{
	if (a[i] == 0)
		return i;
	if (i >= 0)
		return findlast(a, n, i - 1);
	else
		return -1;
}

int Sum(int* a, const int n, int i, int sum)
{
	if (i <= findlast(a, n, n) && i >= findfirst(a, n, 0))
		sum += a[i];
	if (i < n - 1)
		return Sum(a, n, i + 1, sum);
     else 
		return sum;
}

void Sort(int* a, int n, int i, int j)
{
        if (a[i] >= 0)
		{
			if (i != j)
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		if (i < n - 1)
			Sort(a, n, i + 1, j);
		
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "Insert n:" << endl;
	cout << "n = "; cin >> n;

	const int high = 10;
	const int low = -10;
	int* a = new int[n];
	//int i = 0;
	//int p = 1;
	//int sum = 0;
	//int j = 0;

	Generate(a, n, low, high, 0);
	cout << "a[] = { ";
	print(a, n, 0);
	cout << "}" << endl;
	cout << "Multiplying matching numbers: " << Multiple(a, n, 0, 1) << endl;

	if (findfirst(a, n, 0) == -1 || findlast(a, n, 0) == -1)
		cout << "No zeros in the array, sum = 0" << endl;
	else
		cout << "Sum of the matching numbers: " << Sum(a, n, 0, 0) << endl;

	Sort(a, n, 1, 0);
	cout << "Sortified array: " << endl;
	cout << "a[] = { ";
	print(a, n, 0);
	cout << "}" << endl;
	delete[] a;

	system("pause");
	return 0;

}