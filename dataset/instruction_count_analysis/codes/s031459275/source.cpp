#define mod 1000000007

#define PI acos(-1)

#include<time.h>

#include<stdio.h>

#include<string.h>

#include<math.h>

#include<map>

#include<queue>

#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

typedef long long ll;

const ll INF=0x7fffffffffffffff;

const int inf=0x7fffffff;

const int N=2e5+5;

clock_t start,finish;

void time_in(){start=clock();}

void time_out(){finish=clock();double tim=(double)(finish-start)/CLOCKS_PER_SEC;printf("Running time is %lf\n",tim);}

inline ll mul(ll a,ll b){ll s=0;while(b){if(b&1)s=(s+a)%mod;a=(a<<1)%mod;b>>=1;}return s%mod;}

inline ll pow_mul(ll a,ll b){ll s=1;while(b){if(b&1)s=mul(s,a);a=mul(a,a);b>>=1;}return s;}

inline ll poww(ll a,ll b){ll s=1;while(b){if(b&1)s=(s*a)%mod;a=(a*a)%mod;b>>=1;}return s%mod;}

inline bool read(int &ret){char c=getchar();int sgn;if(c==EOF)return 0;while(c!='-'&&(c<'0'||c>'9'))c=getchar();

	sgn=((c=='-')?-1:1);ret=((c=='-')?0:(c-'0'));while(c=getchar(),c>='0'&&c<='9')ret=ret*10+(c-'0');ret*=sgn;return 1;}

inline void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}

int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};

int st[4][2]={1,0,0,1,-1,0,0,-1};

int t,cas;

int n,m,k;

int main()

{

	int a[N];

	int sum[N];

	int ans[N];

	while(~scanf("%d",&n))

	{

		int cnt=0;

		for(int i=1;i<=n;i++)

		{

			scanf("%d",&a[i]);

			sum[i]=0;

		}

		for(int i=n;i>=1;i--)

		{

			if(sum[i]%2!=a[i])

			{

				ans[cnt++]=i;

				for(int j=1;j*j<=i;j++)

				{

					if(i%j==0)

					{

						sum[j]++;

						if(j*j!=i)sum[i/j]++;

					}

				}

			}

		}

		sort(ans,ans+cnt);

		printf("%d\n",cnt);

		for(int i=0;i<cnt;i++)

		{

			printf("%d",ans[i]);

			printf(i==cnt-1?"\n":" ");

		}

	}

}
