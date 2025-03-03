#include "stdc++.h"

#define REP(i,n) for (int i = 0; i < (n); ++i)

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}

template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

using namespace std;

using ll = long long;

using P = pair<int,int>;

using Pl = pair<long long,long long>;

using veci = vector<int>;

using vecl = vector<long long>;

using vecveci = vector<vector<int>>;

using vecvecl = vector<vector<long long>>;



int main() {

    int N;

    cin >> N;

    ll ans = 0;

    for(ll i = 1; i <= N; i++) {

        ll cnt = N/i;

        ans += i*cnt*(cnt+1)/2;

    }

    cout << ans << endl;

}