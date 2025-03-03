#include <stdio.h>

#include <string.h>

const int maxn=1e5+5;



int t,q,p;

char ch;

char c[maxn];

char begin[maxn*2];

char end[maxn*2];

int k1=maxn*2-5;

int k2=0;



int main(){

	scanf("%s%d",c,&t);

	int change=1;

	while(t--){

		scanf("%d",&q);

		if(q==1)

			change=-change;

		else{

			scanf("%d %c%*c",&p,&ch);

			if(p==1){

				if(change>0)

				    begin[k1--]=ch;

				else 

					end[k2++]=ch;

			}

			else{

				if(change>0)

					end[k2++]=ch;

				else

					begin[k1--]=ch;

			}

		}

	}

	begin[k2]='\0';

	if(change>0){

		for(int i=k1+1;i<=maxn*2-5;i++)

			printf("%c",begin[i]);

		printf("%s",c);

		for(int i=0;i<k2;i++)

		    printf("%c",end[i]);

		printf("\n");

	}

	else{

		for(int i=k2-1;i>=0;i--)

			printf("%c",end[i]);

		int len=strlen(c)-1;

		for(int i=len;i>=0;i--)

			printf("%c",c[i]);

		for(int i=maxn*2-5;i>k1;i--)

			printf("%c",begin[i]);

		printf("\n");

	}

	

	return 0;

}

	