#include"stdc++.h"



using namespace std;



#define fi first

#define se second

#define pb push_back

#define mp make_pair



typedef pair<int,int> ii;



int n,f[100005],up[100005];

long long ans[100005],sum[100005],cnt[100005];



vector<ii> graph[100005];

bool vis[100005];

vector<int> all;

vector<ii> tree[100005];



void dfs(int u,int p){

    f[u] = 1;

    for(int i = 0;i<graph[u].size();i++){

        int v = graph[u][i].fi;

        if(!vis[v] && v!=p){

            dfs(v,u);

            f[u]+=f[v];

        }

    }

}



int fin(int u,int p,int sz){

    for(int i = 0;i<graph[u].size();i++){

        int v = graph[u][i].fi;

        if(!vis[v] && v!=p){

            if(2*f[v]>sz) return fin(v,u,sz);

        }

    }

    return u;

}



void dist(int u,int p,int id,int val){

    all.pb(val); tree[id].pb(mp(val,u)); up[u] = val;

    for(int i = 0;i<graph[u].size();i++){

        int v = graph[u][i].fi,w = graph[u][i].se;

        if(!vis[v] && v!=p)

            dist(v,u,id,min(w,val));

    }

}

void centroid(int cen){

    dfs(cen,cen);

    int u = fin(cen,cen,f[cen]);

    vis[u] = 1;

    all.clear();

    for(int i = 0;i<graph[u].size();i++){

        int v = graph[u][i].fi,w = graph[u][i].se;

        if(vis[v]) continue;

        tree[v].clear();

        dist(v,u,v,w);

        sort(tree[v].begin(),tree[v].end());

    }

    sort(all.begin(),all.end());

    for(int i = 0 ;i<all.size();i++)

        ans[u]+=all[i];

    sum[all.size()] = 0;

    for(int i = 0 ;i<all.size();i++){

        sum[i] = all[i];

        if(i == 0) continue;

        sum[i]+=sum[i-1];

    }

    for(int i = 0 ;i<graph[u].size();i++){

        int v = graph[u][i].fi;

        if(vis[v]) continue;

        cnt[tree[v].size()] = 0;

        for(int j = 0;j<tree[v].size();j++){

            cnt[j] = tree[v][j].fi;

            if(j == 0) continue;

            cnt[j]+=cnt[j-1];

        }

        for(int j = 0;j<tree[v].size();j++){

            //cout<<tree[v][j].fi<<" "<<tree[v][j].se<<"\n";

            int node = tree[v][j].se,val = up[node],it;

            ans[node]+=val;

            it = upper_bound(all.begin(),all.end(),val)-all.begin();

            if(it-1>=0)

            ans[node]+=sum[it-1];

            ans[node]+=val*(all.size()-it);

            it = lower_bound(tree[v].begin(),tree[v].end(),ii(val+1,-1))-tree[v].begin();

            if(it-1>=0)

            ans[node]-=cnt[it-1];

            ans[node]-=val*(tree[v].size()-it);

        }

    }

    for(int i = 0;i<graph[u].size();i++){

        int v = graph[u][i].fi;

        if(!vis[v])

            centroid(v);

    }

}



int main(){

    cin.tie(0),ios::sync_with_stdio(0);

    cin>>n;

    int u,v,w;

    for(int i = 1;i<=n-1;i++){

        cin>>u>>v>>w;

        graph[u].pb(mp(v,w));

        graph[v].pb(mp(u,w));

    }

    centroid(1);

    for(int i = 1;i<=n;i++)

        cout<<ans[i]<<"\n";

}
