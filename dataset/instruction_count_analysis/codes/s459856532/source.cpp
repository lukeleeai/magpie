#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define MAXN 300010

#define LL long long

#define INF 1e16

int n,m,a[MAXN],st[MAXN],r;

LL f[MAXN],g[MAXN],h[MAXN],ans[MAXN],sum[MAXN],tmp[MAXN],t[MAXN];

double K(int x,int y)

{

	return (t[x]-t[y]+1LL*x*(x-1)/2-1LL*y*(y-1)/2+sum[x]-sum[y])*1.0/(x-y);

}

void DP()

{

	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

	st[r=1]=0;

	for(int i=1;i<=n;i++)

	{

		while(r>1&&K(st[r],st[r-1])<=i) r--;

		int j=st[r];

		t[i]=max(t[i-1],t[j]+1LL*(i-j)*(i-j+1)/2+sum[j]-sum[i]);

		while(r>1&&K(st[r],st[r-1])<K(i,st[r])) r--;

		st[++r]=i;

	}

}

void Solve(int L,int R)

{

	if(L==R)

	{

		h[L]=max(h[L],g[R+1]+f[L-1]+1-a[L]);

		return;

	}

	int mid=(L+R)/2;

	st[r=1]=L-1;

	for(int i=L;i<mid;i++)

	{

		while(r>1&&K(st[r],st[r-1])<K(i,st[r])) r--;

		st[++r]=i;

	}

	for(int i=mid;i<=R;i++)

	{

		while(r>1&&K(st[r],st[r-1])<=i) r--;

		int j=st[r];

		tmp[i]=t[j]+1LL*(i-j)*(i-j+1)/2+sum[j]-sum[i]+g[i+1];

	}

	for(int i=R-1;i>=mid;i--) tmp[i]=max(tmp[i],tmp[i+1]);

	for(int i=mid;i<=R;i++) h[i]=max(h[i],tmp[i]);

	Solve(L,mid);

	Solve(mid+1,R);

}

void Pre()

{

	DP();

	for(int i=1;i<=n;i++)

		f[i]=t[i];

	for(int i=1;i<=n/2;i++)

		swap(a[i],a[n-i+1]);

	DP();

	for(int i=1;i<=n;i++)

	{

		g[i]=t[n-i+1];

		ans[i]=-INF;

	}

	for(int i=1;i<=n/2;i++)

		swap(a[i],a[n-i+1]);

	for(int i=1;i<=n;i++)

	{

		t[i]=f[i];

		sum[i]=sum[i-1]+a[i];

		h[i]=-INF;

	}

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	Pre();

	Solve(1,n);

	for(int i=1;i<=n;i++)

		ans[i]=max(ans[i],h[i]);

	for(int i=1;i<=n;i++) swap(g[i],f[i]);

	for(int i=1;i<=n/2;i++)

	{

		swap(a[i],a[n-i+1]);

		swap(f[i],f[n-i+1]);

		swap(g[i],g[n-i+1]);

	}

	for(int i=1;i<=n;i++)

	{

		t[i]=f[i];

		sum[i]=sum[i-1]+a[i];

		h[i]=-INF;

	}

	Solve(1,n);

	for(int i=1;i<=n;i++)

		ans[i]=max(ans[i],h[n-i+1]);

	for(int i=1;i<=n/2;i++)

	{

        swap(f[i],f[n-i+1]);

        swap(g[i],g[n-i+1]);

        swap(a[i],a[n-i+1]);

    }

    for(int i=1;i<=n;i++)

    	swap(f[i],g[i]);

    scanf("%d",&m);

    while(m--)

    {

    	int x,y;

    	scanf("%d%d",&x,&y);

    	printf("%lld\n",max(f[x-1]+g[x+1],ans[x]+a[x]-y));

	}

}