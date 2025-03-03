#include"stdc++.h"

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;

#define eps 1e-6

#define eq(x,y) (fabs((x)-(y)) < eps)

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<int,int>pii;

const int mod = 998244353;

long double PI = acosl(-1);

const ll infl = 1e18+100;

const int inf = 2e9+100;

const int nmax = 600+5;

const int MAXLG = log2(nmax)+1;

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;



const int N = 2e5+5;

int sq[N];



int vis[2][nmax][nmax];

int n;



vector<pii>dydx;



inline bool thikase(int i, int j, int idx){

    if(i<0 or j<0 or i>=2*n or j>=2*n) return false;

    if(vis[idx][i][j]!=-1) return false;

    return true;

}



int delx[4] = {-1,1,-1,1};

int dely[4] = {-1,1,1,-1};





void dfs(int i, int j, int idx, int pi=-1, int pj=-1){

    if(pi==-1) vis[idx][i][j] = 0;

    else vis[idx][i][j] = vis[idx][pi][pj]^1;



    for(pii z : dydx){

        for(int k=0; k<4; k++){

            if(thikase(i+z.first*delx[k], j+z.second*dely[k], idx) ){

                dfs(i+z.first*delx[k], j+z.second*dely[k], idx, i, j);

            }

        }

    }

}



void alu(int idx, int D){

    dydx.clear();

    for(int i=0; i<=D; i++){

        if(sq[i]!=-1 and sq[D-i]!=-1){

            dydx.push_back({sq[i], sq[D-i]});

        }

    }



    for(int i=0; i<2*n; i++){

        for(int j=0; j<2*n; j++){

            if(vis[idx][i][j]==-1)

                dfs(i,j,idx);

        }

    }

}





int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



    memset(vis, -1, sizeof vis);

    memset(sq, -1, sizeof sq);



    for(int i=0; i*i<N; i++) sq[i*i] = i;



    int D1,D2;

    cin>>n>>D1>>D2;



    alu(0, D1);

    alu(1, D2);



    vector<vector<pii> >types(4);

    for(int i=0; i<2*n; i++){

        for(int j=0; j<2*n; j++){

            int num = vis[0][i][j] + 2*vis[1][i][j];

            types[num].push_back({i,j});

        }

    }

    for(int i=0; i<4; i++){

        if(types[i].size()>=n*n){

            while(types[i].size()>n*n) types[i].pop_back();

            for(pii z : types[i])

                cout<<z.first<<" "<<z.second<<"\n";

            break;

        }

    }

}

/*



*/
