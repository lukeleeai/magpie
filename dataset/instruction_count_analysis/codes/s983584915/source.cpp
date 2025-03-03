#include<cstdio>

#include<algorithm>

using namespace std;



int a[5],cnt;



int main()

{

	scanf("%d %d %d",&a[1],&a[2],&a[3]);

	sort(a+1,a+4);

	cnt+=a[3]-a[2];

	a[1]+=cnt;

	cnt+=(a[3]-a[1])/2+((a[3]-a[1])&1)*2;

	printf("%d\n",cnt);

	return 0;

}