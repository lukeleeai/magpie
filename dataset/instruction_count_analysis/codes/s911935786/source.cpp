#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int INF = 1e9;

const ll LINF = 1e18;

template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }

template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }

template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }

template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }



/*

 <url:>

 問題文============================================================

 =================================================================

 解説=============================================================

 ================================================================

 */



bool check(int minx,int miny,int maxx,int maxy,int key,vector<vector<char>>& masu){

    for(int i = minx; i <= maxx; i++){

        for(int j = miny; j <= maxy;j++){

            if(masu[i][j] == '*' || masu[i][j] == key) continue;

            return false;

        }

    }

    return true;

}



void Fill(int minx,int miny,int maxx,int maxy,vector<vector<char>>& masu){

    for(int i = minx; i <= maxx; i++){

        for(int j = miny; j <= maxy;j++){

            masu[i][j] = '*';

        }

    }

}



string solve(){

    ll H,W; cin >> H >> W;

    vector<vector<char>> masu(H,vector<char>(W));

    for(int i = 0; i < H;i++){

        for(int j = 0; j < W;j++){

            cin >> masu[i][j];

        }

    }

    vector<pair<pii,pii>> X(26,{{INF,INF},{-INF,-INF}});

    for(int i = 0; i < H;i++){

        for(int j = 0; j < W;j++){

            if(masu[i][j] == '.') continue;

            masu[i][j] -= 'A';

            pair<pii,pii>& piiii = X[masu[i][j]];

            piiii.first.first = min(piiii.first.first,i);

            piiii.first.second = min(piiii.first.second,j);

            piiii.second.first = max(piiii.second.first,i);

            piiii.second.second = max(piiii.second.second,j);

        }

    }

    while(true){

        bool update = [&]{

            for(int i = 0; i < 26;i++){

                if(X[i].first.first == INF) continue;

                if(check(X[i].first.first,X[i].first.second,X[i].second.first,X[i].second.second,i,masu)){

                    Fill(X[i].first.first,X[i].first.second,X[i].second.first,X[i].second.second,masu);

                    X[i].first.first = INF;

                    return true;

                }

            }

            return false;

        }();

        if(update) continue;

        else break;

    }

    

    for(int i = 0; i < H;i++){

        for(int j = 0; j < W;j++){

            if(masu[i][j] == '.') continue;

            if(masu[i][j] == '*') continue;

            return "SUSPICIOUS";

        }

    }

    return "SAFE";

}

int main(void) {

    cin.tie(0); ios_base::sync_with_stdio(false);

    ll T; cin >> T;

    while(T--){

        cout << solve() << endl;

    }

    return 0;

}


