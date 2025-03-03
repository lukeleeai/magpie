#include <iostream>

#include <algorithm>

#include <vector>

#define fs first

#define sc second

using namespace std;

const int maxn = 1e5+10;

using pii = pair<int,int>;

vector<pii> G[maxn];

vector<int> ans;

int N,M;

pii arr[maxn];

bool vis[maxn];

int ca[maxn];

int dfs(int u){

    vis[u] = true;

    int st = ca[u];

    for(auto v:G[u]){

        if(vis[v.fs]) continue;

        int r = dfs(v.fs);

        if(r) {

            ans.push_back(v.sc);

            st ^= 1;

        }

    }

    return st;

}

int main(){

    cin>>N>>M;

    for(int i = 1;i<=N;i++) scanf("%d %d",&arr[i].fs,&arr[i].sc);

    sort(arr+1,arr+N+1);

    ca[1] = arr[1].sc;

    for(int i = 2;i<=N;i++) ca[i] = arr[i].sc^arr[i-1].sc;

    ca[N+1] = arr[N].sc;

    //for(int i = 1;i<=N;i++) cout<<ca[i]<<" ";cout<<endl;

    for(int i = 1;i<=M;i++){

        int a,b;

        scanf("%d %d",&a,&b);

        int l = lower_bound(arr+1,arr+N+1,pii(a,0))-arr;

        int r = upper_bound(arr+1,arr+N+1,pii(b,1))-arr; //cout<<l<<" "<<r<<endl;

        if(l == r) continue;

        G[l].push_back({r,i});

        G[r].push_back({l,i});

    }

    for(int i = 1;i<=N;i++){

        if(vis[i]) continue;

        if(dfs(i)){

            cout<<-1<<endl;

            return 0;

        }

    }

    cout<<ans.size()<<endl;

    sort(ans.begin(),ans.end());

    for(auto v:ans) cout<<v<<" ";



    return 0;

}