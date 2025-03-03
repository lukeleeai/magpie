#include "stdc++.h"

#define ll long long

#define re register

#define IL inline

using namespace std;

const int maxn=1e5+10;

template<typename T> void read(T &x){

	T f=1;x=0;

	char s=getchar();

	while(s<'0' || s>'9'){if(s=='-') f=-1;s=getchar();}

	while(s>='0' && s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}

	x*=f;

}

ll n,m;

vector<int> t[maxn];

ll f[maxn];

ll ans[maxn];

bool book[maxn];

void dfs(int st){

	f[st]=1;

	book[st]=1;

	for(re int i=0;i<t[st].size();i++){

		if(!book[t[st][i]]){

			book[t[st][i]]=1;

		//	fa[t[st][i]]=st;

			dfs(t[st][i]);

			f[st]=(f[st]%m*(f[t[st][i]]+1)%m)%m;

		}

	}

	return;

}

void huangen(int st){

	//cout<<1<<endl;

	int len=t[st].size();

	int pre[len+5],suf[len+5];

	pre[0]=suf[len+1]=1;

	for(re int i=1;i<=len;i++){

		pre[i]=(pre[i-1]%m*(f[t[st][i-1]]+1)%m)%m;	

		suf[len-i+1]=(suf[len-i+2]%m*(f[t[st][len-i]]+1)%m)%m;

	}

	for(re int i=0;i<t[st].size();i++){

		if(ans[t[st][i]]!=-1) continue;

		int tmp1=f[st],tmp2=f[t[st][i]];

		f[st]=(pre[i]%m*suf[i+2]%m)%m;

		f[t[st][i]]=(f[t[st][i]]%m*(f[st]+1)%m)%m;

		ans[t[st][i]]=f[t[st][i]];

		huangen(t[st][i]);

		f[st]=tmp1;f[t[st][i]]=tmp2;

	}

	return;

}

int main(){

	//freopen(".in","r",stdin);

	//freopen(".out","w",stdout);

	read(n);read(m);

	for(re int i=1;i<n;i++){

		int x,y;

		read(x);read(y);

		t[x].push_back(y);

		t[y].push_back(x);

	}

	dfs(1);

	memset(ans,-1,sizeof ans);

	ans[1]=f[1];

	huangen(1);

	for(re int i=1;i<=n;i++) cout<<ans[i]%m<<endl;

	return 0;

}