#include<stdio.h>

#include<math.h>

#include<string.h> 

int main() {

	int a,b;

	scanf("%d %d",&a,&b);

	int i,j;

	int cnt=0;

	for(i=a;i<=b;i++){

		int c,d,e,f,g;

		c=i/10000;

		d=i%10000/1000;

		e=i%1000/100;

		f=i%100/10;

		g=i%10;

		if(c==g&&d==f){

			cnt++;

		}

	}

	printf("%d",cnt);

	return 0;

}