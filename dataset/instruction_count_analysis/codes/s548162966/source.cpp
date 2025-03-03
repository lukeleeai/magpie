#include <stdio.h>

 

int main(void){

 

	int in[2]={0};

	

	int i;

	int count=0;

	int rev=0,num=0;

	scanf("%d %d",&in[0],&in[1]);

	

	

	for(i=in[0];i<=in[1];i++){

		

		num=i;

		rev=0;

		while(num>0){

			rev=rev*10+num%10;

			num/=10;

		}

		

		if(i==rev){

			count++;

		}

	}

	

	printf("%d",count);	

	

	return 0;

}