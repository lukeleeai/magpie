#include<cstdio>

int a[1005],n,ans[1005],cnt;

long long sum[2];

int main(){

	scanf("%d",&n);bool t=0;

	for(int i=1;i<=n;++i)scanf("%d",a+i),a[i]>0?(t=1):0;

	if(n==2){printf("%d\n1\n%d\n",a[1]>a[2]?a[1]:a[2],a[1]>a[2]?2:1);return 0;}

	if(!t){

		int Max=1;for(int i=2;i<=n;++i)if(a[i]>a[Max])Max=i;

		printf("%d\n%d\n",a[Max],n-1);

		for(int i=n;i>Max;--i)printf("%d\n",i);

		for(int i=1;i<Max;++i)puts("1");

		return 0;

	}

	for(int i=1;i<=n;++i)if(a[i]>0)sum[i&1]+=a[i];

	if(sum[1]>sum[0]){

		printf("%lld\n",sum[1]);

		if((n&1)==0)ans[++cnt]=n--;

		bool ok=1;

		for(int i=n;i>=1;i-=2)if(a[i]<0)

			if(ok)ans[++cnt]=i,ans[++cnt]=i-1;

			else ans[++cnt]=i,i==1?(ans[++cnt]=1):0;

		else if(ok)ok=0;

			else ans[++cnt]=i+1;

	}

	else{

		printf("%lld\n",sum[0]);

		if(n&1)ans[++cnt]=n--;

		bool ok=1;

		for(int i=n;i>=1;i-=2)if(a[i]<0)

			if(ok)ans[++cnt]=i,ans[++cnt]=i-1;

			else ans[++cnt]=i;

		else if(ok)ok=0;

			else ans[++cnt]=i+1;

		ans[++cnt]=1;

	}

	printf("%d\n",cnt);

	for(int i=1;i<=cnt;++i)printf("%d\n",ans[i]);

	return 0;

}