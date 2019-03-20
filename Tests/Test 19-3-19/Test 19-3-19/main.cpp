#include<iostream>
#include<string.h>

using namespace std;

class myString
{
	char *name;
	int length;

    public:

		//Default constructor
		myString()
		{
			name = NULL;
			length = 0;
		}

		//Copy constructor
		myString(myString &ms)
		{
			length = ms.length;
			name = new char[length+1];
			strcpy(name, ms.name);

		}

		//Parameterised constructor
		myString(const char *ms_name)
		{
			int l;
			l = strlen(ms_name);
			length = l;
			name = new char[length+1];
			strcpy(name, ms_name);
		}


		/*boolean operator=(myString &s)
		{
			if(strcmp(name,s.name))
				return 1;
			else
				return 0;
			
		}*/

		//This appends two strings into a new string
		myString operator+(myString s1)
		{
			myString temp;
			int i, j;
			temp.length = length + s1.length;
			temp.name = new char[length + 1];
			
			for (i = 0; i < length; i++)
			{
				temp.name[i] = name[i];
			}

			for (j = 0; j < s1.length; j++)
			{
				temp.name[i] = s1.name[j];
				i++;
			}
			temp.name[i] = '\0';
			
			
			return temp;

		}

		


		friend istream& operator>>(istream& cin, myString &ms);
		friend ostream& operator<<(ostream& cout, myString ms);
		friend void sortings(myString* ms, int n);

		~myString()
		{
			if (name != NULL)
				delete name;
			
		}


};

void sortings(myString* ms, int n)
{
	int i, j, flag;
	myString temp;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			flag = 0;
			if (ms[j].name[0] < ms[j - 1].name[0])
			{
				temp = ms[j];
				ms[j] = ms[j - 1];
				ms[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}

	cout << "sorted list is" << endl;
	for (i = 0; i < n; i++)
	{
		cout << ms[i].name << endl;
	}
}


istream& operator>>(istream& cin, myString &ms)
{
	char temp[50];

	cout << "Enter the string" << endl;
	cin >> temp;

	ms.length = strlen(temp);
	ms.name = new char[ms.length+1];
	strcpy(ms.name, temp);

	return cin;
}

ostream& operator<<(ostream& cout, myString ms)
{
	
	cout << "The string is " << ms.name<<endl;
	
	return cout;
}




int main()
{
	myString s1,s2,s3;
	//myString s[5];

	//cout << "Enter the array of strings" << endl;

	/*for (int i = 0; i < 5; i++)
	{
		cin >> s[i];
	}
*/
	//sortings(s, 5);
	cin >> s2;

	cout << s2;

	/*s1 = s2;
	cout << "printing s1" << s1 << endl;
	s3 = s1 + s2;
	cout << "printing s3" << endl;
	cout << s3<<endl;
	*/

	return 0;
}