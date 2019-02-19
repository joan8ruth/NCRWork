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
			s = new char[len];
			strcpy(s, p);
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
	const char *p = "hello";
	strings msg(p);
	cout << msg;
	return 0;
}