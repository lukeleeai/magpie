#include<cstdio>

using namespace std;

int a,b,x;

int main(){

	scanf("%d%d%d",&x,&a,&b);

	x-=a;

	x-=x/b*b;

	printf("%d",x);

	return 0;

}