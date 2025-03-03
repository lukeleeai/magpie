#include<cstdio>

#include<cctype>

#include<cstring>

#include<algorithm>

#include<vector>

using std::vector;

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

#define reg register

typedef long long ll;

inline int read(){

    reg int x=0,f=1;reg char ch=getchar();

    for(;!isdigit(ch);f=ch=='-'?-1:1,ch=getchar());

    for(;isdigit(ch);x=x*10+(ch^48),ch=getchar());

    return x*f;

}

const int mod=1e9+7;

int n,c;

int a[405],b[405],f[405][405];

ll prod[405][405];

inline ll qpow(ll a,ll b){

    reg ll res=1;

    while(b){

        if(b&1)res=res*a%mod;

        a=a*a%mod;b>>=1;

    }

    return res;

}

int main(){

    n=read();c=read();

    for(reg int i=1;i<=n;i++)a[i]=read();

    for(reg int i=1;i<=n;i++){

        b[i]=read();prod[i][0]=b[i]-a[i]+1;

        for(reg int j=1;j<=c;j++)

            for(reg int k=a[i];k<=b[i];k++)prod[i][j]=(prod[i][j]+qpow(k,j))%mod;

    }

    f[0][0]=1;

    for(reg int i=1;i<=n;i++)

        for(reg int j=0;j<=c;j++)

            for(reg int k=0;k<=j;k++)

                f[i][j]=(f[i][j]+1ll*f[i-1][j-k]*prod[i][k]%mod)%mod;

    printf("%d\n",f[n][c]);

    return 0;

}