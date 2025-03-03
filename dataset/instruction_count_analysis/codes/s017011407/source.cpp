#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cmath>

#include<cstring>

#include<algorithm>

#include<vector>

#define ll long long

#define re register

#define il inline

#define pb push_back

#define fp(i,a,b) for(re int i=a;i<=b;++i)

#define fq(i,a,b) for(re int i=a;i>=b;--i)

using namespace std;

const int N=2e5+100,mod=1e9+7;

int n,x,X,Y,mn[N],mn1=mod,mn2=mod,ans=1,inv[N],tot;

vector<int>V[N];

il ll gi()

{

  re ll x=0,t=1;

  re char ch=getchar();

  while(ch!='-'&&(ch<'0'||ch>'9')) x=x*10+ch-48,ch=getchar();

  if(ch=='-') t=-1,ch=getchar();

  while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();

  return x*t;

}

int main()

{

  n=gi();X=gi();Y=gi();

  inv[0]=inv[1]=1;

  fp(i,1,n) x=gi(),V[x].pb(gi());

  fp(i,2,n) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;

  fp(i,2,n) inv[i]=1ll*inv[i]*inv[i-1]%mod;

  fp(i,1,n)

    if(V[i].size())

      {

	sort(V[i].begin(),V[i].end());

        mn2=min(mn2,mn[i]=V[i][0]);

	if(mn2<mn1) swap(mn1,mn2);

      }

    else mn[i]=mod;

  fp(i,1,n)

    {

      re int mm=(mn[i]==mn1?mn2:mn1),sz=V[i].size();

      while(sz>1&&V[i][sz-1]+mm>Y&&V[i][sz-1]+mn[i]>X) --sz;

      if(mm+mn[i]<=Y) ans=1ll*ans*inv[sz]%mod,tot+=sz;

    }

  fp(i,1,tot) ans=1ll*ans*i%mod;

  printf("%d\n",ans);

  return 0;

}
