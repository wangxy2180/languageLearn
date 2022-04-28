#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
	char* a = (char*)malloc(1 * sizeof(char));
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'b';
	printf("len %ld, %s \n",strlen(a),a);
	char* b = a+3;
	b[0] = 'b';
	b[1] = 'c';
	printf("len %ld, %s \n", strlen(a), a);
	b[2] ='\0';
	printf("len %ld, %s \n", strlen(a),a);
	printf("str: %s \n", a);
}