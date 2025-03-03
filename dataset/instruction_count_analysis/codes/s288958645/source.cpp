#include "stdc++.h"

using namespace std;

typedef long long ll;

using pint = pair<int,int>;

ll mod = 1000000007,mod2 = 998244353;



void chmin(long long &a, long long b) { if (a > b) a = b; }

void chmax(long long &a, long long b) { if (a < b) a = b; }

//void chmin(int &a, int b) { if (a > b) a = b; }

//void chmax(int &a, int b) { if (a < b) a = b; }



const long long INF = 1LL<<60;

ll gcd(ll a,ll b){

    if(b == 0) return a;

    else return gcd(b,a%b);

}



//重みある時

using Edge = pair<int,int>;

using Graph = vector<vector<Edge> >;





int main() {

    int n,k,r,s,p;

    ll ans = 0;

    cin >> n >> k >> r >> s >> p;

    string T;

    cin >> T;

    for (int i = 0; i < n; ++i) {

        if(i >= k){

            if(T[i-k] == T[i]) T[i] = '#';

            else{

                if(T[i] == 'r') ans += p;

                if(T[i] == 's') ans += r;

                if(T[i] == 'p') ans += s;

            }

        }else{

            if(T[i] == 'r') ans += p;

            if(T[i] == 's') ans += r;

            if(T[i] == 'p') ans += s;

        }

    }

    cout << ans << endl;

    return 0;

}
