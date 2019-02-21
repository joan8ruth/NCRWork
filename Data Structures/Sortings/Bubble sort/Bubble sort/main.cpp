#include<iostream>

using namespace std;

int main()
{

	int n, *a,i,j,temp,flag;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	a = (int*)malloc(n * sizeof(int));
	cout << "Enter the elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];

	}

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			flag = 0;
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}

	cout << "The sorted array is" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i]<<endl;
	}

	cin >> n;
	return 0;
}