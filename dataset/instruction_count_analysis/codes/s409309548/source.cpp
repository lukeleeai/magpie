#include"stdc++.h"

#define pir pair<int,int>

#define fi first

#define se second

#define ll long long

#define pb push_back

using namespace std;



const int N=510,M=100010;

int n,prime[M],cnt;

ll res[N][N];

bool vis[M];

vector<pir> v;



void pre(int m) {

    for(int i=2;i<=m;i++) {

        if(!vis[i]) prime[++cnt]=i;

        for(int j=1;j<=cnt;j++) {

            int tmp=prime[j]*i;

            if(tmp>m) break;

            vis[tmp]=1;

            if(i%prime[j]==0) break;

        }

    }

}



bool cmp1(pir a,pir b) {

    if(a.fi+a.se!=b.fi+b.se) return a.fi+a.se<b.fi+b.se;

    return a<b;

}



bool cmp2(pir a,pir b) {

    if(a.fi+a.se!=b.fi+b.se) return a.fi-a.se<b.fi-b.se;

    return a<b;

}



ll lcm(ll a,ll b) {

    return a/__gcd(a,b)*b;

}



int main() {

    pre(100000);

    scanf("%d",&n);

    if(n==2) return printf("2 3\n5 4\n"),0;

    for(int i=1;i<=n;i++) {

        for(int j=1;j<=n;j++) {

            if((i+j)%2==0) v.pb({i,j});

            res[i][j]=1;

        }

    }

    sort(v.begin(),v.end(),cmp1);

    pir pre={0,0};

    int* ptr=prime;

    for(auto p:v) {

        if(p.fi+p.se!=pre.fi+pre.se) ptr++;

        res[p.fi][p.se]*=*ptr;pre=p;

    }

    sort(v.begin(),v.end(),cmp2);

    pre={0,0};

    for(auto p:v) {

        if(p.fi-p.se!=pre.fi-pre.se) ptr++;

        res[p.fi][p.se]*=*ptr;pre=p;

    }

    for(int i=1;i<=n;i++) {

        for(int j=1;j<=n;j++) {

            if((i+j)%2) {

                if(i>1) res[i][j]=lcm(res[i][j],res[i-1][j]);

                if(j>1) res[i][j]=lcm(res[i][j],res[i][j-1]);

                if(i<n) res[i][j]=lcm(res[i][j],res[i+1][j]);

                if(j<n) res[i][j]=lcm(res[i][j],res[i][j+1]);

                printf("%lld ",res[i][j]+1);

            }

            else printf("%lld ",res[i][j]);

        }

        puts("");

    }

    return 0;

}