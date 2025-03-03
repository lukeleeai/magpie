#include"stdc++.h"

#include<tr1/unordered_map>

#define CLR(a,x) memset(a,x,sizeof(a))

#define MP make_pair

#define fi first

#define se second

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int,int> pa;

const int maxn=1e5+10;



inline ll rd(){

    ll x=0;char c=getchar();int neg=1;

    while(c<'0'||c>'9'){if(c=='-') neg=-1;c=getchar();}

    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();

    return x*neg;

}



int eg[maxn*2][2],egh[maxn],ect;

int N,M,ans[maxn*2],l,r;

bool flag[maxn];



inline void adeg(int a,int b){

	eg[++ect][0]=b,eg[ect][1]=egh[a],egh[a]=ect;

}



void dfs(int x,bool d){

	flag[x]=1;

	for(int i=egh[x];i;i=eg[i][1]){

		int b=eg[i][0];if(flag[b]) continue;

		if(d) ans[++r]=b;

		else ans[--l]=b;

		dfs(b,d);break;

	}

}



int main(){

    //freopen("","r",stdin);

	N=rd(),M=rd();

	for(int i=1;i<=M;i++){

		int a=rd(),b=rd();

		adeg(a,b);adeg(b,a);

	}

	ans[l=r=1e5]=1;

	dfs(1,0),dfs(1,1);

	printf("%d\n",r-l+1);

	for(int i=l;i<=r;i++) printf("%d ",ans[i]);

    return 0;

}