#include <stdio.h>

#include <string.h>

int main()

{

	int h,w,i,j;

	char c[310][300];

	scanf("%d %d",&h,&w);

	getchar();

	for(i=1;i<=h;i++){

		scanf("%s",&c[i]);

	}

	for(i=1;i<=h;i++){

			puts(c[i]);

			puts(c[i]);

	}

	return 0;

}