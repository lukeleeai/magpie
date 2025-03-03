#include"stdc++.h"

#define maxn 75

#define rep(i,j,k) for(int i=(j),LIM=(k);i<=LIM;i++)

#define per(i,j,k) for(int i=(j),LIM=(k);i>=LIM;i--)

#define mod 1000000007

#define vi vector<int>

#define pb push_back

using namespace std;



int n,K,fac[maxn << 2],invf[maxn << 2],inv[maxn << 2];

int C(int a,int b){ if(a<0 || b<0 || a-b<0) return 0;return fac[a] * 1ll * invf[b] % mod * invf[a-b]%mod; }

char s[maxn];

vi p;int ans;



bool check(){

	static bool vis[maxn];

	static int loc[maxn];

	memset(vis,0,sizeof vis);

	int j=1;

	for(int i=p.size()-1;i>=0 && p[i];i--){

		for(;j <= K && s[j] != 'r';j++);

		if(j > K) return 0;

		vis[j] = 1 , loc[i] = j , j++;

	}

	j=1;

	for(int i=p.size()-1;i>=0 && p[i];i--){

		j = max(j , loc[i]);

		for(;j <= K && s[j] != 'b';j++);

		if(j > K) return 0;

		vis[j] = 1 , loc[i] = j , j++;

	}

	j=1;

	for(int i=0;i<p.size() && p[i]==0;i++){

		for(;j <= K && (s[j] != 'r' || vis[j]);j++);

		if(j > K) return 0;

		vis[j] = 1 , j++;

	}

	j=1;

	for(int i=p.size()-1;i>=0 && p[i] > 1;i--){

		j = max(j , loc[i]);

		rep(k,2,p[i]){

			for(;j <= K && vis[j];j++);

			if(j > K) return 0;

			vis[j] = 1 , j++;

		}

	}

	return 1;

}



void dfs(int sz,int mx,int lim){

	if(sz > n) return;

	if(check()){

		int sm = fac[p.size()];

		for(int i=0,j;i<p.size();i=j){

			for(j=i;j<p.size() && p[j] == p[i];j++);

			sm = 1ll * sm * invf[j-i] % mod;

		}

		ans = (ans + 1ll * C(n-sz+mx-1,mx-1) * sm) % mod;

		//printf("%d %d %d %d\n",sm,ans,sz,mx);

	}

	else return;

	rep(i,lim,(n-sz+1)/2){

		p.pb(i);

		dfs(sz+max(2*i-1,1)+(sz!=0),mx+2*i+2,i);

		p.pop_back();

	}

}



int main(){//freopen("1.in","r",stdin);//freopen("2.out","w",stdout);

	scanf("%d%d",&n,&K);

	scanf("%s",s+1);

	fac[0] = inv[0] = inv[1] = fac[1] = invf[0] = invf[1] = 1;

	rep(i,2,(maxn << 2) - 1) fac[i] = 1ll * fac[i-1] * i % mod , inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod,

		invf[i] = 1ll * invf[i-1] * inv[i] % mod;

	dfs(0,1,0);

	printf("%d\n",(ans+mod)%mod);

}