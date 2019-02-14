#include<iostream>

using namespace std;

class distance2;
class distance1 {

	int meters;
	int centimeters;



    public:
		friend void add_distance(distance1, distance2);
		void set_values(int a, int b)
		{
			meters = a;
			centimeters = b;
		}

};

class distance2 {

	int feet;
	int inches;

public:
	friend void add_distance(distance1, distance2);
	void set_values(int a, int b)
	{
		feet = a;
		inches = b;
	}
};

void add_distance(distance1 d1, distance2 d2)
{
	float dist;

	dist = (d1.meters) + ((d1.centimeters)*0.01) + (d2.feet*0.3048) + (d2.inches*0.0254);

	cout << "distance in meters is " << dist;

	
}

int main()
{
	int a, b;
	distance1 d1;
	distance2 d2;
	cout << "Enter values for distance 1" << endl;
	cin >> a;
	cin >> b;
	d1.set_values(a, b);
	cout << "Enter values for distance 2" << endl;
	cin >> a;
	cin >> b;
	d2.set_values(a, b);

	add_distance(d1, d2);

	return 0;
}