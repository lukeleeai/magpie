#include<cstdio>

#define ll long long

#define mod 1000000007ll

struct Edge{

    int to,nex;

}edge[3000010];

int c[200010],head[200010],pos[200010],cnt[200010],tot;

ll w[200010],fac[200010],rfac[200010],min[200010];

bool v[200010];

ll pow(ll a,ll b){

    ll ans=1,base=a;

    while(b){

        if(b&1)ans=(ans*base)%mod;

        base=(base*base)%mod;

        b>>=1;

    }

    return ans;

}

ll C(ll n,ll k){

    return(((fac[n]*rfac[n-k])%mod)*rfac[k])%mod;

}

void add(int a,int b){

    tot++;

    edge[tot].to=b;

    edge[tot].nex=head[a];

    head[a]=tot;

}

void dfs(int x){

    v[x]=1;

    for(int i=head[x];i;i=edge[i].nex){

        if(!v[edge[i].to])dfs(edge[i].to);

    }

}

int main(){

    int n,i,fir,sec=0;

    ll X,Y,min1,min2,tot,ans;

    scanf("%d%lld%lld",&n,&X,&Y);

    fac[0]=1;

    for(i=1;i<=n;i++){

        scanf("%d%lld",c+i,w+i);

        fac[i]=(i*fac[i-1])%mod;

        min[i]=2147483647;

    }

    rfac[n]=pow(fac[n],mod-2);

    for(i=n;i>0;i--)rfac[i-1]=(i*rfac[i])%mod;

    for(i=1;i<=n;i++){

        if(w[i]<min[c[i]]){

            min[c[i]]=w[i];

            pos[c[i]]=i;

        }

    }

    for(i=1;i<=n;i++){

        if(i!=pos[c[i]]&&w[i]+min[c[i]]<=X){

            add(i,pos[c[i]]);

            add(pos[c[i]],i);

        }

    }

    min1=min2=2147483647;

    for(i=1;i<=n;i++){

        if(w[i]<min1){

            min1=w[i];

            fir=i;

        }

    }

    for(i=1;i<=n;i++){

        if(w[i]<=min2&&c[i]!=c[fir]){

            min2=w[i];

            sec=i;

        }

    }

    for(i=1;i<=n;i++){

        if(i==fir)continue;

        if(c[i]!=c[fir]&&w[i]+w[fir]<=Y){

            add(i,fir);

            add(fir,i);

        }

        if(sec&&c[i]!=c[sec]&&w[i]+w[sec]<=Y){

            add(i,sec);

            add(sec,i);

        }

    }

    dfs(fir);

    tot=0;

    for(i=1;i<=n;i++){

        if(v[i]){

            tot++;

            cnt[c[i]]++;

        }

    }

    ans=1;

    for(i=1;i<=n;i++){

        if(cnt[i]){

            ans=(ans*C(tot,cnt[i]))%mod;

            tot-=cnt[i];

        }

    }

    printf("%lld",ans);

}