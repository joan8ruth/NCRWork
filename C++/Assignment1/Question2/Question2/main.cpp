#include<iostream>
using namespace std;

class CollegeCourse
{
	char *name;
	char grade;
	int subject1, subject2, subject3;
	int len;
	int average;

	public:
		void set_Data(char *n, int sub1, int sub2, int sub3)
		{
			len = strlen(n);
			name = (char*)malloc((len + 1) * sizeof(char));
			strcpy(name, n);
			calculateAverage();
			ComputeGrade();
			subject1 = sub1;
			subject2 = sub2;
			subject3 = sub3;

		}

		void calculateAverage()
		{
			average = (subject1 + subject2 + subject3) / 3;
		}

		void ComputeGrade()
		{
			if (average > 60)
				grade = '1';
			else if (average > 50 && average < 60)
				grade = '2';
			else if (average > 40 && average < 50)
				grade = '3';
			else
				grade = 'F';
		}

		void display()
		{
			cout << "Name is " << name<<endl;
			cout << "Grade is " << grade<<endl;
			
		}

		~CollegeCourse() {
			if(name!=NULL)

			free(name);
		}

};

int main()
{
	char c[20];
	CollegeCourse c1;
	cout << "Enter a name" << endl;
	cin >> c;
	c1.set_Data(c, 100, 100, 100);
	c1.display();

	return 0;
}