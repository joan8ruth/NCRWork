#include<iostream>
#include<string.h>
using namespace std;

class strings
{
	char *s;
	int len;

	public:
		strings()
		{
			s = NULL;
			len = 0;
		}

		strings(const char* p)
		{
			len = strlen(p);
			s = new char[len+1];
			strcpy(s, p);
		//	cout << "in constructor";
		}

		strings(strings &str)
		{
			len = str.len;
			s = new char[len+1];
			strcpy(s, str.s);
		}

		friend ostream& operator<<(ostream& cout, strings str);
		friend istream& operator >>(istream &, strings &);

		strings operator+(strings);
		char& operator[](int);
		strings operator=(strings);
};

ostream& operator <<(ostream& cout, strings str)
{
	int i = 0;
	while (i <= (str.len))
	{
		cout <<str.s[i];
		i++;
	}
	return cout;
}

istream& operator >>(istream &cin, strings &str)
{
	char temp[50];
	scanf("%[^\n]s", temp);
	str.len = strlen(temp);
	str.s = new char[str.len];
	strcpy(str.s, temp);

	return cin;
}

strings strings::operator+(strings str)
{
	strings temp;
	temp.len = len + str.len;
	temp.s = new char[len];

	strcpy(temp.s, s);
	strcat(temp.s, str.s);

	return temp;
}

char& strings::operator[](int n)
{
	try
	{
		if (n < len)
			return s[n];
		else
			throw s[n];
	}
	catch (char e)
	{
		cout << "Index out of bound" << endl;
	}

}

strings strings::operator=(strings str)
{
	if (s != NULL)
		free(s);

	len = str.len;
	s = new char[len];

	strcpy(s, str.s);
	return *this;
}


int main()
{
	//const char *p = "hello";
	strings msg1("hello"),s2(msg1),s(msg1);
	strings s3, s4, s5;
	

	cout << "Enter s4: ";
	cin >> s4;
	cout << "hi" << endl;
	s3 = s4;
	cout << "s3 is" << s3 << endl;
	cout << endl << "s3[3] = " << s3[3] << endl;
	return 0;
}