#include "stdc++.h"





#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }



#define X real()

#define Y imag()



using namespace std;

using namespace __gnu_pbds;



template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ll  = long long;



using point = complex<double>;





void err(istream_iterator<string> it) {cerr << endl;}

template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}





const double EPS = 1e-8;

const long long mod = 1e9+7;



const int dx[] = {0, 0,1,-1,1,-1, 1,-1};

const int dy[] = {1,-1,0, 0,1,-1,-1, 1};



const int N = 1e5 + 5;



int n ,m,u,v;

vector<pair<int,int> > edgs;

int par[N],rnk[N];

void init(){

    for(int i = 1; i < N; ++i)

            par[i] = i, rnk[i] = 1;

}

int findpar(int u){



    return par[u] = (u == par[u] ? u : findpar(par[u]));

}

long long join(int u, int v){

        u = findpar(u);

        v = findpar(v);

        if(u == v)

            return 0;

        ll ret = rnk[u] * rnk[v];

        if(rnk[u] < rnk[v])

            swap(u,v);

        par[v] = u;

        rnk[u] += rnk[v];

        return ret;

}

int main()

{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){

            cin >> u >> v;

            edgs.push_back({u,v});

    }

    reverse(edgs.begin(),edgs.end());

    init();

    long long ans[N];

    memset(ans,0,sizeof ans);

    ans[0] = (1ll * n * ( n - 1)/2);



    for(int i = 0; i < m - 1; ++i){

            ll ret = join(edgs[i].first,edgs[i].second);

            ans[i + 1] = ans[i] - ret;

    }

    for(int i = 0; i <m; ++i)

            cout <<ans[m - i - 1] << '\n';



    return 0;

}
