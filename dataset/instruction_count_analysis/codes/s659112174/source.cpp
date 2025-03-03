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

 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1194&lang=jp>

 問題文============================================================

 =================================================================

 解説=============================================================

 ================================================================

 */

double R;

int n;

int base = 50;

bool building[55][100];

double solve(){

    fill(*building,*building+100*55,0);

    double res = 0;

    vector<int> xl(n),xr(n),h(n);

    for(int i = 0; i < n;i++) cin >> xl[i] >> xr[i] >> h[i];

    for(int i = 0; i < n;i++){

        xl[i] += base; xr[i] += base;

        for(int j = xl[i]; j < xr[i];j++){

            for(int k = 0; k < h[i];k++){

                building[k][j] = true;

            }

        }

    }

//    for(int i = 10; i >= 0; i--){

//        for(int j = 40; j <= 60; j++){

//            cout << building[i][j];

//        }

//        cout << endl;

//    }

    

    double l = 0,r = 50;

    for(int i = 0; i < 50;i++){

        double m = (l+r)/2;

        bool ok = true;

        for(int x = -R; x < 0; x++){

            double from = R - sqrt(R*R-(abs(x)-1)*(abs(x)-1));

            double H = m - from;

            if(H < 0) continue;

            if(building[(int)H][x+base] == 0) ok = false;

        }

        for(int x = 0; x < R; x++){

            double from = R - sqrt(R*R-x*x);

            double H = m - from;

            if(H < 0) continue;

            if(building[(int)H][x+base] == 0) ok = false;

        }

        if(ok){

            l = m;

        }else{

            r = m;

        }

    }

    res = l;

    return res;

}

int main(void) {

    cin.tie(0); ios_base::sync_with_stdio(false);

    while(cin >> R >> n){

        if(n == 0 && R < 1e-9) break;

        cout << fixed << setprecision(4) << solve() << endl;

    }

    return 0;

}


