#include<cstdio>



long long S,x1,x2,x3,y1,y2,y3;



int main(){

	scanf("%lld",&S);

	if (S<=1e9){

		x1=0,y1=0;

		x2=S,y2=0;

		x3=0,y3=1;

		printf("%lld %lld %lld %lld %lld %lld",x1,y1,x2,y2,x3,y3);

		return 0;

	}

	x1=0,y1=0;	//S=x3y2-y3x2;

	x3=1e9;

	y2=S/x3+(S%x3?1:0);

	y3=1;

	x2=x3*y2-S;

	printf("%lld %lld %lld %lld %lld %lld",x1,y1,x2,y2,x3,y3);

	return 0;

}
