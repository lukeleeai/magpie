#include"stdc++.h"

using namespace std;

#define ll long long

#define ull unsigned long long

#define mp make_pair

typedef pair<int,int> pii;

typedef priority_queue<int,vector<int>,greater<int> > small_heap;

typedef priority_queue<int> big_heap;

int n,m;

vector<int>v[60];

ll path[60];

void dfs(int x,int fa,ll num){

    path[x]=num;

    for(auto vv:v[x]){

        if(vv==fa)continue;

        dfs(vv,x,num|(1ll<<vv));

    }

}

ll info[60];

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=n-1;i++){

        int x,y;scanf("%d%d",&x,&y);

        v[x].push_back(y);v[y].push_back(x);

    }

    dfs(1,0,0ll);

    scanf("%d",&m);

    for(int i=0;i<m;i++){

        int x,y;scanf("%d%d",&x,&y);

        info[i]=(path[x]^path[y]);

    }

    ll maxstate=(1ll<<m)-1;

    ll ans=0ll;

    for(int i=0;i<=maxstate;i++)

    {

        ll num=0ll;

        int cnt=0;

        for(int j=0;j<=m-1;j++)

        {

            if(i&(1<<j))

            {

                cnt++;

                num|=info[j];

            }

        }

        int free=n-1-__builtin_popcountll(num);

        ans+=(1ll<<free) * (cnt & 1 ? -1ll : 1ll);//这边奇为减，是因为直接计算合法的总数，2^ n-1  --

    }

    cout<<ans<<endl;

    return 0;

}