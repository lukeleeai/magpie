#include<cstdio>

#include<algorithm>

#define fo(i,a,b) for(i=a;i<=b;i++)

#define fd(i,a,b) for(i=a;i>=b;i--)

using namespace std;

typedef long long ll;

const int maxn=200000+10,mo=1000000007,inf=1000000005;

int mi[maxn],c[maxn],w[maxn],cnt[maxn],fac[maxn],inv[maxn];

int i,j,k,l,t,n,m,ans,num,x,y;

int qsm(int x,int y){

    if (!y) return 1;

    int t=qsm(x,y/2);

    t=(ll)t*t%mo;

    if (y%2) t=(ll)t*x%mo;

    return t;

}

int C(int n,int m){

    if (n<m||m<0) return 0;

    return (ll)fac[n]*inv[m]%mo*inv[n-m]%mo;

}

int main(){

    scanf("%d%d%d",&n,&x,&y);

    fo(i,1,n) mi[i]=inf;

    fac[0]=1;

    fo(i,1,n) fac[i]=(ll)fac[i-1]*i%mo;

    inv[n]=qsm(fac[n],mo-2);

    fd(i,n-1,0) inv[i]=(ll)inv[i+1]*(i+1)%mo;

    fo(i,1,n){

        scanf("%d%d",&c[i],&w[i]);

        mi[c[i]]=min(mi[c[i]],w[i]);

        cnt[c[i]]++;

    }

    fo(i,1,n) 

        if (mi[i]!=inf){

            if (m==0) m=i;

            else if (mi[i]<mi[m]) m=i;

        }

    t=inf;

    fo(i,1,n)

        if (mi[i]!=inf&&i!=m) t=min(t,mi[i]);

    fo(i,1,n){

        if (w[i]!=mi[c[i]]&&w[i]+mi[c[i]]<=x) continue;

        if (c[i]!=m&&w[i]+mi[m]<=y) continue;

        if (c[i]==m&&w[i]+t<=y) continue;

        cnt[c[i]]--;

    }

    num=cnt[m];

    fo(i,1,n)

        if (mi[i]!=inf&&i!=m)

            if (mi[i]+mi[m]<=y) num+=cnt[i];

    ans=1;

    fo(i,1,n)

        if (mi[i]!=inf&&(i==m||mi[i]+mi[m]<=y)){

            ans=(ll)ans*C(num,cnt[i])%mo;

            num-=cnt[i];

        }

    printf("%d\n",ans);

}