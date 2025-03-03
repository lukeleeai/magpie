#include"stdc++.h"

using namespace std;

typedef long long ll;

const int maxn = 3005;

const int mod = 998244353;

#define pb push_back

#define pii pair<int,int>

#define fi first

#define se second

int t;

int n,m; 

int c[maxn];

int f[maxn];

int add(int a,int b){ a+=b; return a>=mod?a-mod:a;}  



int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;++i) scanf("%d",c+i);

	int ans = 0;

	for(int i=n;i>=1;--i)

	{

		++f[0];

		for(int j=m;j>=c[i];--j)

		{

			f[j] = add(f[j],f[j-c[i]]);

		}

		ans = add(ans,f[m]);

	}

	printf("%d\n",ans);

}