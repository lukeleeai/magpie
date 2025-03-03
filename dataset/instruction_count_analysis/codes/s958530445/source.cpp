#include"stdc++.h"

#define debug puts("&&&&&&")

#define read(x) scanf("%d",&x)

using namespace std;

typedef long long LL;

const int maxn=1e5+5;

const int mod=1e9+7;

int n,k;

int u[maxn],v[maxn];

LL next[maxn],cnt,temp;

LL cnt1;

vector<int> ma[maxn];

void dfs(int f,int t,int deep) {

    cnt1++;

    if(deep==0){

        return;

    }

    for(int i=0;i<ma[f].size();i++) {

        if(ma[f][i] != t) {

            dfs(ma[f][i],f,deep-1);

        }

    }

}

int main() {

    while(read(n) != EOF) {

        read(k);

        for(int i=0;i<=n;i++) {

            ma[i].clear();

        }

        cnt=0;

        temp=0;

        LL ans=0;

        for(int i=1;i<=n-1;i++) {

            read(u[i]);

            read(v[i]);

            ma[u[i]].push_back(v[i]);

            ma[v[i]].push_back(u[i]);

        }

        if(k%2==1) {

            for(int i=1;i<=n-1;i++) {

                cnt=0;

                cnt1=0;

                dfs(u[i],v[i],k/2);

                dfs(v[i],u[i],k/2);

                cnt+=cnt1;

                ans=max(ans,cnt);

            }

        }

        else {

            for(int i=1;i<=n;i++) {

                cnt=0;

                cnt1=0;

                dfs(i,0,k/2);

                cnt+=cnt1;

                ans=max(ans,cnt);

            }

        }

        printf("%d\n",n-ans);

    }

}
