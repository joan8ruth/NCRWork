#include<stdio.h>


struct Date
{
	int d, m, y;
};

int getDifference(struct Date, struct Date);
int countLeap(struct Date);

const int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void main()
{
	int d;
	struct Date dt1 = { 1, 2, 2000 };
	struct Date dt2 = { 1, 2, 2004 };
	printf("The difference in days is %d", getDifference(dt1,dt2));
}

int getDifference(struct Date dt1,struct Date dt2)
{
	long int n1 = dt1.y * 365 + dt1.d;

	
	for (int i = 0; i < dt1.m - 1; i++)
		n1 += months[i];

	n1 += countLeap(dt1);


	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
		n2 += months[i];
	n2 += countLeap(dt2);
	return (n2 - n1);
}
int countLeap(struct Date d)
{
	int years = d.y;

	if (d.m <= 2)
		years--;

	return years / 4 - years / 100 + years / 400;
}