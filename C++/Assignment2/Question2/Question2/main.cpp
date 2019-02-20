#include<iostream>

using namespace std;

class student
{
	int id;
	char *name = NULL;
	int s1, s2, s3;
	int total;
	int average;
	
	public:
		student()
		{
			id = 0;
			name = NULL;
			s1 = s2 = s3 = 0;
			total = 0;
			average = 0;
		}
		student(int i,const char *n,int m1,int m2,int m3)
		{
			int len;
			id = i;
			len = strlen(n);
			name = new char[len + 1];
			strcpy(name, n);
			s1 = m1;
			s2 = m2;
			s3 = m3;
			total = s1 + s2 + s3;
			average = total / 3;

		}
		student(const student &s)
		{
			name = s.name;
			id = s.id;
			s1 = s.s1;
			s2 = s.s2;
			s3 = s.s3;
			total = s.total;
			average = s.average;

		}

		friend ostream& operator<<(ostream& cout, student str);
		friend istream& operator>>(istream& cin, student &str);
		friend void generate_results(student s[], int n);
		
		
};

void generate_results(student s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].total = s[i].s1 + s[i].s2 + s[i].s3;
		s[i].average = s[i].total / 3;
	}

}

 istream& operator>>(istream& cin, student &s)
{
	 int len;
	 char n[20];
	 cin >> s.id;
	 cin >> n;
	 len = strlen(n);
	 s.name = new char[len + 1];
	 strcpy(s.name, n);
	 cin >> s.s1;
	 cin >> s.s2;
	 cin >> s.s3;
	
	 return cin;


}

ostream& operator<<(ostream& cout, student s)
{
	int len;
	cout << "ID is " << s.id << endl;
	len = strlen(s.name);
	int i = 0;
	while (i <= (len))
	{
		cout << s.name[i];
		i++;
	}
	cout << endl;
	cout << "Marks are :" << s.s1 << endl;
	cout << "Marks are :" << s.s2 << endl;
	cout << "Marks are :" << s.s3 << endl;
	cout << "Total is :" << s.total << endl;
	cout << "Average is :" << s.average<< endl;
	return cout;
}

int main()
{
	student s[3];
	int i;
	cout << "Enter data for 3 students " << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "Enter student " << i << "details" << endl;
		cin >> s[i];

	}

	generate_results(s, 3);

	//cout << "The entered values are " << endl;
	for (i = 0; i < 3; i++)
	{
		cout << "student " << i << "details are" << endl;
		cout << s[i];

	}

	
	return 0;
}