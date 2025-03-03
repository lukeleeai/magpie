#include "stdc++.h"



#define forn(i, n) for (int i = 0; i < int(n); ++i)

#define for1(i, n) for (int i = 1; i <= int(n); ++i)

#define ms(a, x) memset(a, x, sizeof(a))

#define F first

#define S second

#define all(x) (x).begin(),(x).end()



using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

template<typename... Args> void rd(Args&... args) {((cin >> args), ...);}

template<typename... Args> void write(Args... args) { ((cout << args << " "), ...); cout<<endl;}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int ans=0;

    ll x;

    cin>>x;

    ll n=100;

    while(n<x){

        n=n*1.01;

        ans++;

    }

    cout<<ans;

    return 0;

}


