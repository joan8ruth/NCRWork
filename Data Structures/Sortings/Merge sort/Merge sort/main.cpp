#include<iostream>

using namespace std;

int main()
{

	int n, *a, i, j, temp, flag;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	a = (int*)malloc(n * sizeof(int));
	cout << "Enter the elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];

	}

	return 0;

}