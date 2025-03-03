#include "stdc++.h"

#include <iostream>

#include <utility> // pair

#include <string>

#include <vector>

#define MAX_N 0001

#define rep(i, a, b) for(ll i=a; i<b; i++)

#define rer(i, a, b) for(ll i=a-1; i>=b; i--)

#define pb push_back

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

// vector< vector<int> > dp;



bool accessible(int x, vector<int> v){

    bitset<32001> dp;

    // int m = dp[0].size()/2, n=v.size();

    int m = 16000, n=v.size();

    // rep(i, 0, dp.size())rep(j, 0, dp[0].size()) dp[i][j] = 0;

    // dp[0][m] = 1;

    dp[m] = true;



    // rep(i, 0, n){

    //     rep(j, -m, m){

    //         if(j+m-v[i] < 0 && j+m+v[i] < dp[0].size()) dp[i+1][j+m] = dp[i][j+m+v[i]];

    //         else if(j+m-v[i] > 0 && j+m+v[i] > dp[0].size()) dp[i+1][j+m] = dp[i][j+m-v[i]];

    //         else dp[i+1][j+m] = dp[i][j+m-v[i]] || dp[i][j+m+v[i]];

    //     }

    // }

    rep(i, 0, n){

        // rep(j, -m, m){

            // dp[j+m] = dp[j+m-v[i]] || dp[j+m+v[i]];

            dp = (dp<<v[i]) | (dp>>v[i]);

        // }

    }

    // if(dp[n][x+m]==1) return true;

    // else return false;

    return dp[16000+x];

}



signed main(){

    string s; cin >> s;

    int x, y; cin >> x >> y;

    vector<int> fx(1, 0), fy(0, 0);

    int n = s.size();

    int cnt = 0;

    rep(i, 0, n){

        if(s[i] == 'F'){

            if(cnt%2==0) fx[cnt/2]++;

            else fy[cnt/2]++;

        }else if(s[i] == 'T'){

            cnt++;

            if(cnt%2==0) fx.pb(0);

            else fy.pb(0);

        }

    }

    if(cnt==s.size() && (x != 0 || y != 0)){

        cout << "No" << endl;

        return 0;

    }

    // rep(i, 0, fx.size()) cout << fx[i] << endl;

    // rep(i, 0, fy.size()) cout << fy[i] << endl;

    // dp = vector< vector<int> >(max(fx.size(), fy.size())+1, vector<int>(16001, 0));

    x -= fx[0];

    fx.erase(fx.begin());



    if(accessible(x, fx))

        if(accessible(y, fy)){

            cout << "Yes" << endl;

            return 0;

        }

    cout << "No" << endl;

    return 0;

}