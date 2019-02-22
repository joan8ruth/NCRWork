#include<iostream>

using namespace std;

int main()
{

	int n, *a, i, j,min,temp,k,flag=0;
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
		flag = 0;
		min = a[i];
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				flag = 1;
				k = j;
				min = a[j];
			}

		}

		if(flag==1)
		{
			temp = a[i];
			a[i] = min;
			a[k] = temp;
		}
	}

	cout << "The sorted array is" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}

	cin >> n;
}
