#include<cstdio>

using namespace std;

int main(void){

	int n;

	int t,a;

	int h;

	int i;

	int x,ans,MIN;

	int sum;

	scanf("%d%d%d",&n,&t,&a);

	MIN=1000000000;

	ans=0;

	for(i=1;i<=n;i++){

		scanf("%d",&h);

		x=t*1000-h*6;

		sum=x-a*1000;

		if(sum<0)	sum*=-1;

		if(MIN>sum){

			MIN=sum;

			ans=i;

		}

	}

	printf("%d\n",ans);

	return 0;

}