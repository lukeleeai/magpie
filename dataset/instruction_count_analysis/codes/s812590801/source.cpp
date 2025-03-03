#include<cmath>

#include<queue>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#define mod 1000000007

using namespace std;



int n;

long long dp1[300010],dp2[300010],a[300010],sum1,sum2;



priority_queue<long long,vector<long long>,greater<long long> > q;

priority_queue<long long> q2;



int main()

{

	//fuck!!!

	scanf("%d",&n);

	memset(dp1,0,sizeof(dp1));

	memset(dp2,0x3f,sizeof(dp2));

	for(int i=1;i<=3*n;i++)

	{

		scanf("%lld",&a[i]);

	}

	for(int i=1;i<=n;i++)

	{

		q.push(a[i]);

		sum1+=a[i];

	}

	dp1[n]=sum1;

	for(int i=n+1;i<=3*n;i++)

	{

		if(q.top()<a[i])

		{

			sum1-=q.top();

			sum1+=a[i];

			q.pop();

			q.push(a[i]);

		}

		dp1[i]=sum1;

	}

	for(int i=3*n;i>2*n;i--)

	{

		q2.push(a[i]);

		sum2+=a[i];

	}

	dp2[2*n+1]=sum2;

	for(int i=2*n;i>=1;i--)

	{

		if(q2.top()>a[i])

		{

			sum2-=q2.top();

			sum2+=a[i];

			q2.pop();

			q2.push(a[i]);

		}

		dp2[i]=sum2;

	}

	long long ans=-0x3f3f3f3f3f3f3f3f;

	for(int i=n;i<=2*n;i++)

	{

//		printf("%d %lld %lld\n",i,dp1[i],dp2[i]);

		ans=max(ans,dp1[i]-dp2[i+1]);

	}

	printf("%lld\n",ans);

}