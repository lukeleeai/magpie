//AC 



//答案错误 ,原因：题意不清，理解错误，如果x,y在矩形中心就可以有多条切割 

#include<stdio.h>

int main()

{

	double n,m,x,y;

	while(~scanf("%lf%lf%lf%lf",&n,&m,&x,&y)){

		printf("%lf ",n*m/2);

		if(x==n/2&&y==m/2){

			printf("1\n");

		}else{

			printf("0\n");

		}

	}

}