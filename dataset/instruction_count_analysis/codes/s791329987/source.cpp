#include<cstdio>

using namespace std;

int a,b,x,i;

int main()

{

	scanf("%d%d%d",&x,&a,&b);

	x-=a;

	x%=b;

	printf("%d",x);

	return 0;

} 