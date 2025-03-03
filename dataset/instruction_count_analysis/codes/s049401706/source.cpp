#include"stdc++.h"

#define reg register

typedef long long ll;

using namespace std;

const int MN=3e5+5;

int n,m,a[MN];

ll s[MN],f[MN],g[MN];

inline ll Y1(int i){return f[i]+s[i]+1ll*i*(i+1)/2;}

inline ll Y2(int i){return g[i]+s[i]+1ll*i*(i+1)/2;}

inline ll Y3(int i){return f[i]+s[i]+1ll*i*(i-1)/2;}

inline ll Y4(int i){return g[i]+s[i]+1ll*i*(i-1)/2;}

inline double slope1(int i,int j){

	return 1.*(Y1(i)-Y1(j))/(1.*(i-j));

}

inline double slope2(int i,int j){

	return 1.*(Y2(i)-Y2(j))/(1.*(i-j));

}

inline double slope3(int i,int j){

	return 1.*(Y3(i)-Y3(j))/(1.*(i-j));

}

inline double slope4(int i,int j){

	return 1.*(Y4(i)-Y4(j))/(1.*(i-j));

}

int stk[MN],top;

#define mid (l+r>>1)

ll h[MN],t[MN];

void solve(int l,int r){

	if(l==r){h[l]=max(h[l],f[l-1]+g[l+1]+1-a[l]);return;}

	solve(l,mid);solve(mid+1,r);

	s[l-1]=top=0;

	for(reg int i=l;i<=r;i++)s[i]=s[i-1]+a[i];

	for(reg int i=l-1;i<mid;i++){

		while(top>1&&slope3(stk[top-1],stk[top])<=slope3(stk[top-1],i))top--;

		stk[++top]=i;

	}

	for(reg int i=mid+1,j;i<=r;i++){

		while(top>1&&slope3(stk[top-1],stk[top])<=i)top--;

		j=stk[top];

		t[i]=f[j]+1ll*(i-j)*(i-j+1)/2-s[i]+s[j]+g[i+1];

	}

	reg ll res=-1e18;

	for(reg int i=r;i>mid;i--)

		res=max(res,t[i]),h[i]=max(h[i],res);

	s[r+1]=top=0;

	for(reg int i=r;i>=l;i--)s[i]=s[i+1]+a[i];

	for(reg int i=r+1;i>mid+1;i--){

		while(top>1&&slope4(stk[top-1],stk[top])>=slope4(stk[top-1],i))top--;

		stk[++top]=i;

	}

	for(reg int i=mid,j;i>=l;i--){

		while(top>1&&slope4(stk[top-1],stk[top])>=i)top--;

		j=stk[top];

		t[i]=g[j]+1ll*(j-i)*(j-i+1)/2-s[i]+s[j]+f[i-1];

	}

	res=-1e18;

	for(reg int i=l;i<=mid;i++)

		res=max(res,t[i]),h[i]=max(h[i],res);

}

int main(){

	scanf("%d",&n);

	for(reg int i=1;i<=n;i++)scanf("%d",a+i);

	for(reg int i=1;i<=n+1;i++)s[i]=s[i-1]+a[i];

	stk[top=1]=0;

	for(reg int i=1,j;i<=n+1;i++){

		while(top>1&&slope1(stk[top-1],stk[top])<=i)top--;

		j=stk[top];

		f[i]=max(f[i-1],f[j]+1ll*(i-j)*(i-j-1)/2-s[i-1]+s[j]);

		while(top>1&&slope1(stk[top-1],stk[top])<=slope1(stk[top-1],i))top--;

		stk[++top]=i;

	}

	reverse(a+1,a+1+n);

	for(reg int i=1;i<=n+1;i++)s[i]=s[i-1]+a[i];

	stk[top=1]=0;

	for(reg int i=1,j;i<=n+1;i++){

		while(top>1&&slope2(stk[top-1],stk[top])<=i)top--;

		j=stk[top];

		g[i]=max(g[i-1],g[j]+1ll*(i-j)*(i-j-1)/2-s[i-1]+s[j]);

		while(top>1&&slope2(stk[top-1],stk[top])<=slope2(stk[top-1],i))top--;

		stk[++top]=i;

	}

	reverse(a+1,a+1+n);

	reverse(g,g+2+n);

	memset(h,~0x3f,sizeof(h));

	solve(1,n);scanf("%d",&m);

	while(m--){

		static int x,y;scanf("%d%d",&x,&y);

		printf("%lld\n",max(f[x]+g[x],h[x]+a[x]-y));

	}

	return 0;

}