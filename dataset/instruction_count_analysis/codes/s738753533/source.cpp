#include <algorithm>

#include <iostream>

#include <cstdlib>

#include <cstring>

#include <cstdio>

#include <vector>

#include <cmath>

#define re register

using namespace std;



inline int read() {

    int X=0,w=1; char c=getchar();

    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }

    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();

    return X*w;

}



const int N=600000+10;

const int mod=924844033;

inline int qpow(int a,int b) { int c=1;

    for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) c=1ll*c*a%mod;

    return c;

}



int n;



struct edge { int v,nxt; } e[N<<1];

int head[N];

inline void addEdge(int u,int v) {

    static int c=0;

    e[++c]=(edge){v,head[u]},head[u]=c;

}



int fac[N],ifac[N];

inline void init(int n) {

    fac[0]=1;

    for (re int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;

    ifac[n]=qpow(fac[n],mod-2);

    for (re int i=n;i;--i) ifac[i-1]=1ll*ifac[i]*i%mod;

}

inline int C(int n,int m) {

    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;

}



int cnt[N],sz[N];

inline void dfs(int u,int fa) {

    sz[u]=1;

    for (re int i=head[u];i;i=e[i].nxt) {

        int v=e[i].v; if (v==fa) continue;

        dfs(v,u),sz[u]+=sz[v],++cnt[sz[v]];

    }

    ++cnt[n-sz[u]];

}



int r[N],F[N],G[N];

inline void NTT(int* A,int n,int op) {

    for (re int i=0;i<n;++i) if (i<r[i]) swap(A[i],A[r[i]]);

    for (re int i=1;i<n;i<<=1) {

        int rot=qpow(op==1?5:554906420,(mod-1)/(i<<1));

        for (re int j=0;j<n;j+=i<<1)

            for (re int k=0,w=1;k<i;++k,w=1ll*w*rot%mod) {

                int x=A[j+k],y=1ll*w*A[j+k+i]%mod;

                A[j+k]=(x+y)%mod,A[j+k+i]=(x-y+mod)%mod;

            }

    }

    if (op==-1) { int inv=qpow(n,mod-2);

        for (re int i=0;i<n;++i) A[i]=1ll*A[i]*inv%mod;

    }

}



int main() {

    n=read();

    for (re int i=1;i<n;++i) {

        int u=read(),v=read();

        addEdge(u,v),addEdge(v,u);

    }

    dfs(1,0); init(n);

    for (re int i=1;i<=n;++i) F[i]=1ll*cnt[i]*fac[i]%mod;

    reverse(F,F+n+1);

    for (re int i=0;i<=n;++i) G[i]=ifac[i];

    int lim=1,l=0;

    for (;lim<=n<<1;lim<<=1,++l);

    for (re int i=0;i<lim;++i) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));

    NTT(F,lim,1),NTT(G,lim,1);

    for (re int i=0;i<lim;++i) F[i]=1ll*F[i]*G[i]%mod;

    NTT(F,lim,-1);

    reverse(F,F+n+1);

    for (re int i=1;i<=n;++i)

        printf("%lld\n",(1ll*n*C(n,i)%mod

                        -1ll*ifac[i]*F[i]%mod+mod)%mod);

    return 0;

}