#include<cstdio>

#include<cmath>

using namespace std;

int main(){

	long long x,y,a=0,b=0;

	bool flag;

	scanf("%lld %lld",&x,&y);

	if(abs(x)>abs(y))

	a=abs(x)-abs(y),flag=false;

	else

	a=abs(y)-abs(x),flag=true;

	if(x>=0&&flag){

		if(y<0)

		++b;

		printf("%lld",a+b);

		return 0;

	}

	if(x<0&&flag){

		if(y>0)

		++b;

		else 

		b+=2;

		printf("%lld",a+b);

		return 0;

	}

	if(x>=0){

		if(y>0)

		b+=2;

		else

		++b;

		printf("%lld",a+b);

		return 0;

	}

	if(x<0){

		if(y>0)

		++b;

		printf("%lld",a+b);

		return 0;

	}

	return 0;

}