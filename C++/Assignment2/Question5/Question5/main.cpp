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
			cout << "in constructor";
		}

		friend ostream& operator<<(ostream& cout, strings str);
};

ostream& operator<<(ostream& cout, strings str)
{
	int i = 0;
	while (i <= (str.len))
	{
		cout <<str.s[i];
		i++;
	}
	return cout;
}

int main()
{
	//const char *p = "hello";
	strings msg("hello");
	cout << msg;
	return 0;
}