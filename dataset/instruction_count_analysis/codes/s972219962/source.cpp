#include "stdc++.h"



using namespace std;

#define int long long

int n;

vector<pair<int, pair<int, int> > > d;



int par[100005];

long long res[100005];

int lazy[100005];



vector<int> child[100005];



void Union(int u, int v, int w)

{

    if (child[par[u]].size() > child[par[v]].size())

    {

        swap(u, v);

    }

    int k = par[u];

    lazy[par[v]] += w*child[k].size();

    for (int i = 0; i < child[k].size(); i++)

    {

        par[child[k][i]] = par[v];

        res[child[k][i]] += w*child[par[v]].size() - lazy[par[v]] + lazy[k];

    }

    for (int i = 0; i < child[k].size(); i++)

    {

        child[par[v]].push_back(child[k][i]);

    }

    lazy[k] = 0;

    child[k].clear();

}



signed main()

{

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)

    {

        int x, y, l; cin >> x >> y >> l;

        d.push_back({l,{x,y}});

    }

    for (int i = 1; i <= n; i++)

    {

        child[i].push_back(i);

        par[i] = i;

        lazy[i] = 0;

    }

    sort(d.begin(), d.end());

    memset(res, 0, sizeof res);

    memset(lazy, 0, sizeof lazy);

    reverse(d.begin(), d.end());

    for (int i = 0; i < n-1; i++)

    {

        Union(d[i].second.first, d[i].second.second, d[i].first);

    }

    for (int i = 1; i <= n; i++)

    {

        cout << res[i] + lazy[par[i]] << endl;

    }

}
