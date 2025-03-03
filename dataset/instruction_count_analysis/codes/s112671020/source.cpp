

#include"stdc++.h"

#define LL long long

#define MOD (LL)1000000007

#define pi acos(-1.0)

#define ULL unsigned long long

#define mem_1(str) memset(str,-1,sizeof(str))

#define mem0(str) memset(str,0,sizeof(str))

#define rep(i,a,n) for (int i=a;i<n;i++)

#define per(i,a,n) for (int i=n-1;i>=a;i--)

#define INF 999999999

using namespace std;

LL num[300000];

LL id[300000];

LL sum[300000];

int m,idd[300000];;

inline int lowbit(int x)

{

	return x&(-x);

}

void add(int x)

{

    for(int i=x;i<=m;i+=lowbit(i))

    {

    	sum[i]++;

	}    

}

LL add2(int x)

{

    LL ans=0;

    for(int i=x;i>0;i-=lowbit(i))

    {

    	ans=ans+sum[i];

	}        

    return ans;

}

int main()

{

	mem0(id);

	mem0(num);

	mem0(sum);

	mem0(idd);

	int n,k; 

		LL ans=0;

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

	{

		int a;

		scanf("%d",&a);

		id[i]=num[i]=num[i-1]+a-k;

		if(id[i]>=0) ans++;

	}

	sort(num+1,num+n+1);

	m=unique(num+1,num+n+1)-num-1;

	for(int i=1;i<=n;i++)

	{

		idd[i]=lower_bound(num+1,num+m+1,id[i])-num;

	}



	for(int i=1;i<=n;i++)

	{

		ans+=add2(idd[i]);

		add(idd[i]);

	}

	printf("%lld\n",ans);

}