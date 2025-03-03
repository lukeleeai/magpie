#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<vector>

#define pii pair<int,int>

#define fi first

#define se second

#define pb push_back

#define mp make_pair

using namespace std;

inline int read(){

	int f=1,ans=0;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}

	return ans*f;

}

const int MAXN=300001;

int N,M,tot;

struct BIT{

	int Ans[MAXN];

	int lowbit(int x){return x&-x;}

	void Modify(int x,int w){for(;x<=N;x+=lowbit(x)) Ans[x]+=w;}

	int Query(int x){int res=0;for(;x;x-=lowbit(x)) res+=Ans[x];return res;}

	void Add(int l,int r,int w){tot++;Modify(l,w),Modify(r+1,-w);return;}

}T;

vector<pii> vec[MAXN];

int main(){

	M=read(),N=read();

	for(int i=1;i<=M;i++){int l=read(),r=read();vec[r-l+1].pb(mp(l,r));}

	for(int i=1;i<=N;i++){

		int cur=i-1;for(int j=0;j<vec[cur].size();j++) T.Add(vec[cur][j].fi,vec[cur][j].se,1);

		int Ans=M-tot;for(int j=i;j<=N;j+=i) Ans+=T.Query(j);printf("%d\n",Ans);

	}return 0;

}
