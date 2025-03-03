#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<algorithm>

#include<ctime>

#define INF 1e9

using namespace std;

const int maxn=100010;

const double Pi=acos(-1.0);

template<class T>void read(T &x)

{

	x=0;int f=0;char ch=getchar();

	while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}

	x=f?-x:x;

	return;

}

int n,num[maxn],book[21],s;

int f[(1<<17)+10],ans;

int dp(int s)

{

	if(!s)

		return 0;

	if(f[s])

		return f[s];

	f[s]=INF;

	for(int i=1;i<=15;i++)

	{

		if(!(s&(1<<i)))

			continue;

		for(int j=1;j<=15;j++)

		{

			if(i==j||!(s&(1<<j)))

				continue;

			int k=i^j;

			int t=s^(1<<i)^(1<<j)^(1<<k);

			if(s&(1<<k))

				f[s]=min(f[s],dp(t)+2);

			else

				f[s]=min(f[s],dp(t)+1);

		}

	}

	return f[s];

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int a,b,c;

		scanf("%d%d%d",&a,&b,&c);

		num[a]^=c;

		num[b]^=c;

	}

	for(int i=0;i<n;i++)

		book[num[i]]++;

	for(int i=1;i<=15;i++)

	{

		ans+=(book[i]>>1);

		s|=((book[i]&1)<<i);//奇数最后剩下

	}

	printf("%d",ans+dp(s));

	return 0;

}