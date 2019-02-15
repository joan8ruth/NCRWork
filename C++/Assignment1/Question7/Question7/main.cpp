#include<iostream>
using namespace std;

class matrix
{
	int rows;
	int cols;
	int **p=NULL;

public:

	matrix()
	{
		rows = 0;
		cols = 0;
		
	}
	matrix(int a, int b)
	{
		rows = a;
		cols = b;
		p = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			*(p + i) = new int[cols];
		}
	}

	void initialize()
	{
		cout << "Enter values for the matrix" << endl;
		for (int i = 0; i < rows; i++)
		{
			for
				(int j = 0; j < cols; j++)
			{
				cin >> *(*(p+i)+j);
			}
		}

	}

	void display()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << *(*(p + i) + j);
				
			}
			cout << endl;
		}

		cout << endl;
	}

	void multiply(matrix a, matrix b)
	{
		
		int sum = 0;
		rows = a.rows;
		cols = b.cols;
		p = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			*(p + i) = new int[cols];
		}
		for (int c = 0; c < a.rows; c++) {
			for (int d = 0; d < b.cols; d++) {
				for (int k = 0; k < b.rows; k++) {
					sum = sum + *(*(a.p + c) + k) * (*(*(b.p + k) + d));
				}

				*(*(p + c) + d) = sum;
				sum = 0;
			}
		}

	}

};

int main()
{
	matrix m1(2, 2), m2(2, 2),m3;
	m1.initialize();
	m2.initialize();

	m3.multiply(m1, m2);
	m3.display();
	
}