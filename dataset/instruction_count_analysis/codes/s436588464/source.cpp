#include <stdio.h>

#include <string.h>

int main()

{

	char a[6];

	scanf("%s",a);

	if(strstr(a,"AC")) printf("Yes\n");

	else printf("No\n");

}