#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a = 0;
	double b = 0;
	scanf("%lf %lf", &a, &b);
	double c = a / b;
	printf("%.9lf", c);
	return 0;
}