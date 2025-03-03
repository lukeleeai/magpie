#include<iostream>

#include<cstdio>

using namespace std;

int a[1010],sum1[1010],sum2[1010],sum[1010];long long Sum1=0,Sum2=0,Sum;int cnt2=0,cnt1=0,cnt=0;

int ans[1010],Cnt=0;

int main()

{

	int n;scanf("%d",&n);

	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	for(int i=1;i<=n;i+=2)if(a[i]>0)sum1[++cnt1]=i,Sum1+=a[i];

	for(int i=2;i<=n;i+=2)if(a[i]>0)sum2[++cnt2]=i,Sum2+=a[i];

	if(Sum1>Sum2){for(int i=1;i<=cnt1;i++)sum[i]=sum1[i];Sum=Sum1;cnt=cnt1;}

	else {for(int i=1;i<=cnt2;i++)sum[i]=sum2[i];Sum=Sum2;cnt=cnt2;}

	if(Sum==0)

	{

		int Max=-1e9-7,id;

		for(int i=1;i<=n;i++)if(a[i]>Max)Max=a[i],id=i;

		printf("%d\n",Max);

		for(int i=n;i>id;i--)ans[++Cnt]=i;

		for(int i=1;i<id;i++)ans[++Cnt]=1;

		printf("%d\n",Cnt);

		for(int i=1;i<=Cnt;i++)printf("%d\n",ans[i]);

		return 0; 

	}

	printf("%lld\n",Sum);

	int l=sum[1],r=sum[cnt],K=0;

	for(int i=n;i>r;i--)ans[++Cnt]=i;

	for(int i=1;i<l;i++)ans[++Cnt]=1;

	for(int i=2;i<=n;i++)

	{

		K++;

		int mid=(sum[i]-sum[i-1])>>1;

		for(int j=mid;j>=1;j--)ans[++Cnt]=1+j;

	}

	printf("%d\n",Cnt);

	for(int i=1;i<=Cnt;i++)printf("%d\n",ans[i]);

	return 0;

}