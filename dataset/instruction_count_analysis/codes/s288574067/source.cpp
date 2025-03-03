#include <iostream>

#include <utility>

#include <vector>

#include <string>

#include <algorithm>

#include <cmath>

using namespace std;

using ll=long long;

#define rep(i,a,b) for(ll i=a;i<ll(b);i++)

#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)

#define endl "\n"

#define ALL(x) x.begin(),x.end()

#define ALLR(x) x.rbegin(),x.rend()

#define INF 1e9

#define DEBUG(x) cout<<"debug: "<<x<<endl



vector<pair<ll, ll>> GetPrimes(ll parm){

    // first: prime, second: ex

    vector<pair<ll, ll>> res;



    ll ex = 0;

    while (parm % 2 == 0) {

        ex++;

        parm /= 2;

    }

    if(ex != 0) res.push_back({2, ex});



    for(ll i = 3; i*i <= parm; i += 2 ){

        ex = 0;

        while(parm % i == 0){

            ex++;

            parm /= i;

        }

        if(ex != 0) res.push_back({i, ex});

    }



    if(parm != 1) res.push_back({parm, 1});

    return res;

}



ll n, ans;

int main() {

    cin >> n;

    const auto &res = GetPrimes(n);



    for(auto p : res){

        ll ex = p.second;

        int i = 1;

        while(ex > 0){

            ex -= i; i++;

            if(ex >= 0) ans++;

        }

    }



    cout << ans << endl;



    return 0;

}
