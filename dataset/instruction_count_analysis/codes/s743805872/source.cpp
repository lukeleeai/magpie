#include <stdio.h>

int main()

{

	int a,n,cnt=1;

	char s[100000];

	scanf("%d",&n);

	getchar();

	for(a=0;a<n;a++){

		scanf("%c",&s[a]);

	}

	for(a=0;a<n-1;a++){

		if(s[a]!=s[a+1]){

			cnt++;

		}

	}

	printf("%d",cnt);

}