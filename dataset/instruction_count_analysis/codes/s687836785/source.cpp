#include<cstdio>

#include<algorithm>

#define F(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef long long ll;



int n,m;

int a[100001],b[100001],t;

int fa[100001];

int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}

ll Sum;



int main(){

	int x,y;

	scanf("%d%d",&n,&m);

	if(m==n-1) return puts("0"),0;

	F(i,1,n) scanf("%d",a+i), Sum+=a[i];

	F(i,1,m){

		scanf("%d%d",&x,&y);

		x=ff(x+1); y=ff(y+1);

		Sum-=max(a[x],a[y]);

		b[++t]=max(a[x],a[y]);

		if(a[x]>a[y]) fa[x]=y;

		else fa[y]=x;

	}

	if(t<n-m-2) return puts("Impossible"),0;

	sort(b+1,b+t+1);

	F(i,1,n-m-2) Sum+=b[i];

	printf("%lld",Sum);

	return 0;

}