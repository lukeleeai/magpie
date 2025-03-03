#include<cstdio>

#include<algorithm>

using namespace std;

int main()

{

	#ifdef LOACL

	freopen("in.txt","r",stdin);

	freopen("out.txt","w",stdout);

	#endif

	int a,b;

	scanf("%d %d",&a,&b);

	if((a*b)%2==0)printf("Even\n");

	else printf("Odd\n");

	return 0;

}