#include<cstdio>

#define MAXN 100010

#define ll long long

#define max(a,b) (a>b?a:b)

#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;



int n;

ll c,x[MAXN],v[MAXN];

ll k[5][MAXN],ma[5][MAXN];



int main()

{

	scanf("%d%lld",&n,&c);

	for(register int i=1;i<=n;i++)

		scanf("%lld%lld",&x[i],&v[i]);

	x[n+1]=c;  x[0]=0LL;

	long long sum=0LL,ans=-1e18;

	for(register int i=1;i<=n;i++)

	{

		sum=sum-(x[i]-x[i-1])+v[i];

		ans=max(ans,sum);

	}

	sum=0LL;

	for(register int i=n;i>=1;i--)

	{

		sum=sum-(x[i+1]-x[i])+v[i];

		ans=max(ans,sum);

	}

	for(register int i=1;i<=n;i++)

	{

		k[1][i]=k[1][i-1]+v[i]+2*x[i-1]-2*x[i];

		k[2][i]=k[2][i-1]+v[i]+x[i-1]-x[i];

	}

	for(register int i=n;i>=1;i--)

	{

		k[3][i]=k[3][i+1]+v[i]+2*(c-x[i+1])-2*(c-x[i]);

		k[4][i]=k[4][i+1]+v[i]+(c-x[i+1])-(c-x[i]);

	}

	//  1: 顺 - 先到i    v[1]+v[2]+...+v[i] - 2x[i] 

	//  2: 顺 - 后到i    v[1]+v[2]+...+v[i] - x[i]

	//  3: 逆 - 先到i    v[n]+v[n-1]+...+v[i] - 2(c-x[i])

	//  4: 逆 - 后到i    v[n]+v[n-1]+...+v[i] - (c-x[i])

	

	//  1: 逆 - 后到 i~n 的最大值

	//  2: 逆 - 先到 i~n 的最大值

	//  3: 顺 - 后到 1~i 的最大值

	//  4: 顺 - 先到 1~i 的最大值

	for(register int i=n;i>=1;i--)

	{

		ma[1][i]=max(ma[1][i+1],k[4][i]);

		ma[2][i]=max(ma[2][i+1],k[3][i]);

	}

	for(register int i=1;i<=n;i++)

	{

		ma[3][i]=max(ma[3][i-1],k[2][i]);

		ma[4][i]=max(ma[4][i-1],k[1][i]);

	}

	for(register int i=1;i<=n;i++)

	{

		sum=k[1][i]+ma[1][i+1];//先顺到 i 再逆到 j  (i<j)

		ans=max(sum,ans);

		sum=k[3][i]+ma[3][i-1];//先逆到 i 再顺到 j  (i>j)

		ans=max(sum,ans);

		sum=k[2][i]+ma[2][i+1];//后顺到 i 先逆到 j  (i<j)

		ans=max(sum,ans);

		sum=k[4][i]+ma[4][i-1];//后逆到 i 先顺到 j  (i>j)

		ans=max(sum,ans);

	}

	if(ans<0LL)  puts("0");

	else  printf("%lld",ans);

	return 0;

}