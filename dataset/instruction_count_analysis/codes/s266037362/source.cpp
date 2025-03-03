#include"stdc++.h"

#define F(i,a,b) for(int i=(a);i<=(b);++i)

#define F2(i,a,b) for(int i=(a);i<(b);++i)

#define dF(i,a,b) for(int i=(a);i>=(b);--i)

#define dF2(i,a,b) for(int i=(a);i>(b);--i)

#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)

using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;



int n;

int t[4001],a[4001];

int b[4001];

int f[2001][2001];

int bit[4001];

inline void Add(int p,int x){for(;p<=n+n;p+=p&-p)bit[p]+=x;}

inline int Qur(int p){int A=0;for(;p;p-=p&-p)A+=bit[p];return A;}



int main(){ char s[3];

	scanf("%d",&n);

	F(i,1,n+n) scanf("%s%d",s,a+i), t[i]=*s=='B', b[t[i]*n+a[i]]=i;

	f[0][0]=0;

	F(i,0,n){

		memset(bit,0,sizeof bit);

		F(j,1,n+n) Add(j,1);

		F(j,1,i) Add(b[j],-1);

		F(j,i?0:1,n){

			if(j) Add(b[n+j],-1);

			f[i][j]=INF;

			if(i) f[i][j]=min(f[i][j],f[i-1][j]+Qur(b[i]));

			if(j) f[i][j]=min(f[i][j],f[i][j-1]+Qur(b[n+j]));

		}

	} printf("%d",f[n][n]);

	return 0;

}