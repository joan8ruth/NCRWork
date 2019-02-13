#include<iostream>
#include<math.h>
using namespace std;

class point
{
	int x;
	int y;

    public:
	
		point(int a, int b)
		{
			x = a;
			y = b;
		}

		point(int a)
		{

			x = a;
			y = a;
		}

		friend void distance(point a, point b);
		
};

void distance(point a, point b)
{
	int dist=0;
	
	int X = a.x - b.x;
	int Y = a.y - b.y;
	//cout << "distance1 is :" << dist;
	cout << "in friend x in a is" << X<<" "<< Y<<endl;
	dist = sqrt((X*X) + (Y*Y));
	
	cout << "distance is :" << dist;
}

int main()
{
	point a(2, 3);
	point b(2);
	distance(a, b);


}