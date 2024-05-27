#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int n = 0;
	char ch[101] = "*";
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		printf("%s\n",ch);
		strcat(ch, "*");
	}
	return 0;
}