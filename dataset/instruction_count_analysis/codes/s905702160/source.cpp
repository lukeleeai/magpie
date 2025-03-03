#include"stdc++.h"

#define ll long long

#define cri const register int

#define re register

using namespace std;

const int mod=1e9+7;

inline int qpow(int a,int b,int ans=1){

	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;

	return ans;

}

int fac[201],inv[201],n,k,nxt[77],v[77],vv[77],ans,num,len[77],R[77];

char s[77];

inline int C(cri x,cri y){

	return x<y||x<0||y<0?0:1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;

}

inline char check(cri p){

	memset(v,0,sizeof v);memset(vv,0,sizeof vv);

	for(int i=p,l=1;i;i--,l++){

		if(l>num) return 0;

		v[R[l]]=1;

		if(len[i]>=2){

			if(!nxt[l]) return 0;

			v[nxt[l]]=1;vv[nxt[l]]=i;

		}

	}

	for(int i=k,sum=0;i;i--){

		if(!v[i]) sum++;

		else if(vv[i]){

			sum-=max(0,len[vv[i]]-2);

			if(sum<0) return 0;

		}

	}

	return 1;

}

char dfs(cri p,cri mn,cri LEN){

	if(LEN>n||!check(p)) return 0;

	int s=p+1;

	for(int i=1;i<=p;i++) s+=2*len[i]-1;

	int tmp=1ll*C(n-LEN+s-1,s-1)*fac[p]%mod,t=0;

	for(int i=1;i<=p;i++,t++) 

		if(len[i]!=len[i-1]) tmp=1ll*tmp*inv[t]%mod,t=0;

	ans=(ans+1ll*tmp*inv[t])%mod;

	if(p==num) return 1;

	for(int i=mn;i<=k;i++) 

		if(!dfs(p+1,len[p+1]=i,LEN+(p!=0)+(i<=2?1:i*2-3))) break;

	return 1;

}

int main(){

	cin>>n>>k;

	scanf("%s",s+1);

	for(int i=fac[0]=1;i<=200;i++) fac[i]=1ll*fac[i-1]*i%mod;

	inv[200]=qpow(fac[200],mod-2);

	for(int i=200;i;i--) inv[i-1]=1ll*inv[i]*i%mod;

	for(int i=1;i<=k;i++) if(s[i]=='r')

		for(int j=(R[++num]=i,i+1);j<=k;j++) if(!v[j]&&s[j]=='b'){

			nxt[num]=j;v[j]=1;break;

		}

	dfs(0,1,0);

	cout<<ans<<endl;

}