#include<stdio.h>

using namespace std;



int main(){

	int n,k,b,s[101],i,j;

	

	for(;scanf("%d%d",&n,&k),n|k;){

		for(i=0;i<k;i++)

			scanf("%d",s+i);

		for(i=0;i<n;i++){

			for(j=0;j<k;j++){

				scanf("%d",&b);

				s[j]-=b;

			}

		}

		b=1;

		for(i=0;i<k;)

			if(s[i++]<0)

				b=0;

		puts(b?"Yes":"No");

	}

}