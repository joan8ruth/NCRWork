#include<iostream>

using namespace std;

void insertion_sort(int *a, int n);

int main()
{
	int n, *a, i;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	a = (int*)malloc(n * sizeof(int));
	cout << "Enter the elements" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];

	}

	insertion_sort(a, n);
	cin >> i;

	return 0;
}

void insertion_sort(int *a, int n)
{
	int i,temp,j=0;
	
	cout << "in function";

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		temp = a[i];
		while (j >= 0&&a[j]>temp)
		{
		
			
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}


	cout << "sorted array is" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i]<<endl;

	}
}