#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<int, int> pii;

typedef pair<int, pii> pipii;

typedef pair<pii, int> piipi;

typedef pair<pii, pii> piipii;



#define mp make_pair

#define fi first

#define se second

#define all(a) (a).begin(), (a).end()

#define sz(a) (int)(a).size()

#define eb emplace_back



int x[10005], y[10005];

pii a[20005];



int val[20005];

struct twosat{

    int n;

    vector<vector<int> > adj, radj, scc;

    vector<int> sid, vis;

    stack<int> st;

    int cnt;



    void init(int m){

        n = m;

        adj.clear();

        radj.clear();

        sid.clear();

        vis.clear();

        scc.clear();



        adj.resize(m);

        radj.resize(m);

        sid.resize(m);

        vis.resize(m);

    }



    void impl(int x, int y){

        adj[x].push_back(y);

        radj[y].push_back(x);

    }

    void vee(int x, int y){

        impl(x^1, y);

        impl(y^1, x);

    }

    void nand(int x, int y){

        vee(x^1, y^1);

    }

    void xoro(int x, int y){

        vee(x, y);

        // vee(x^1, y^1);

    }



    void dfs1(int x){

        if(vis[x]++) return;

        for(int i=0;i<adj[x].size();i++) dfs1(adj[x][i]);

        st.push(x);

    }

    void dfs2(int x){

        if(!vis[x]) return;

        vis[x] = 0;

        sid[x] = cnt;

        scc.back().push_back(x);

        for(int i=0;i<radj[x].size();i++) dfs2(radj[x][i]);

    }

    bool two_sat(){

        cnt = 0;

        for(int i=0;i<n;i++) dfs1(i);

        while(!st.empty()){

            int v = st.top();

            st.pop();

            if(vis[v]){

                scc.push_back(vector<int>());

                dfs2(v);

                cnt++;

            }

        }

        for(int i=0;i<n;i+=2){

            if(sid[i] == sid[i+1]) return false;

        }

        return true;

    }

};



twosat sat;

void build(int n, int s, int e){

    if(s == e){

        val[s] = n;

        return;

    }

    else{

        int mid = (s+e)/2;

        build(n+n, s, mid);

        build(n+n+1, mid+1, e);

        sat.impl((n+n)*2, n*2);

        sat.impl((n+n+1)*2, n*2);

    }

}

void add(int n, int s, int e, int l, int r, int q){

    if(s > r || l > e) return;

    if(l <= s && e <= r){

        sat.nand(n*2, q*2);

        return;

    }

    int mid = (s+e)/2;

    add(n+n, s, mid, l, r, q);

    add(n+n+1, mid+1, e, l, r, q);

}

int idx[10005][2];

int main(){

    int n;

    scanf("%d", &n);

    for(int i=1;i<=n;i++){

        scanf("%d%d", &x[i], &y[i]);

        a[i] = mp(x[i], i);

        a[i+n] = mp(y[i], i);

    }

    sort(a+1, a+2*n+1);

    for(int i=1;i<=2*n;i++){

        if(idx[a[i].se][0] == 0) idx[a[i].se][0] = i;

        else idx[a[i].se][1] = i;

    }



    int lo = 1, hi = 1e9, ans = 0;

    while(lo <= hi){

        int mid = (lo+hi)/2;



        sat.init(16*n+2);

        build(1, 1, 2*n);



        int l = 1, r = 1;

        for(int i=1;i<=2*n;i++){

            l = min(l, i);

            r = max(r, i);

            while(a[i].fi-a[l].fi >= mid) l++;

            while(r+1 <= 2*n && a[r+1].fi-a[i].fi < mid) r++;



            if(i != l) add(1, 1, 2*n, l, i-1, val[i]);

            if(i != r) add(1, 1, 2*n, i+1, r, val[i]);

        }

        for(int i=1;i<=n;i++){

            int x = val[idx[i][0]], y = val[idx[i][1]];

            sat.xoro(x*2, y*2);

        }

        int ok = sat.two_sat();

        if(ok == 1) ans = mid, lo = mid+1;

        else hi = mid-1;

    }

    printf("%d\n", ans);

}