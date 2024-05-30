#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int pow(int i, int n)
{
	printf("%d * %d = %d\n", n, i, n * i);
	return 0;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0;i < 9;i++)
		pow(i + 1, num);
	return 0;
}