#include "stdc++.h"

#define REP(i, n) for(int i = 0;i < n;i++)

#define VSORT(v) sort(v.begin(), v.end())

#define VRSORT(v) sort(v.rbegin(), v.rend())

#define ll long long

using namespace std;

typedef pair<int, int> P;

typedef pair<ll, ll> LP;

typedef pair<int, P> PP;

typedef pair<ll, LP> LPP;

//typedef vector<unsigned int>vec;

typedef vector<ll>vec;

typedef vector<vec> mat;

typedef vector<vector<int>> Graph;



const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

//const int INF = 1000000000;

const ll LINF = 1000000000000000000;//1e18

const ll  MOD = 1000000007;

//const ll MOD = 998244353;

const double PI = acos(-1.0);

const double EPS = 1e-10;



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};



int N, Q;

string S;

char t[202020], d[202020];



bool left(int m){

    int cur = m;

    REP(i,Q){

        if(t[i] == S[cur]){

            if(d[i] == 'L') cur--;

            else cur++;

        }

        if(cur < 0) return true;

    }

    return false;

}



bool right(int m){

    int cur = m;

    REP(i,Q){

        if(t[i] == S[cur]){

            if(d[i] == 'L') cur--;

            else cur++;

        }

        if(cur >= N) return true;

    }

    return false;

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin >> N >> Q >> S;

    REP(i,Q) cin >> t[i] >> d[i];



    int l = -1, r = N;

    while(r - l > 1){

        int m = (l + r) / 2;

        if(left(m)) l = m;

        else r = m;

    }

    int vanished = l + 1;

    //cout << l << " " << r << endl;

    //cout << vanished << endl;

    l = -1, r = N;

    while(r - l > 1){

        int m = (l + r) / 2;

        if(right(m)) r = m;

        else l = m;

    }

    vanished += N - r;

    cout << N - vanished << endl;

}