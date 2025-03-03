#include "bits/stdc++.h"

 

typedef long long ll;

#define int ll

#define fi first

#define se second

#define SORT(a) sort(a.begin(),a.end())

#define rep(i,n) for(int i = 0;i < (n) ; i++) 

#define REP(i,n) for(int i = 0;i < (n) ; i++) 

#define MP(a,b) make_pair(a,b)

#define pb(a) push_back(a)

#define INF LLONG_MAX/2

#define all(x) (x).begin(),(x).end()

#define debug(x) cerr<<#x<<": "<<x<<endl

#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl

using namespace std;

int MOD = 1000000007;

vector<int> G[100100];



signed main(){

    string s;

    cin >> s;

    int mx = 0;

    int cnt = 0;

    rep(i,s.size()){

        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){

            cnt++;

            mx = max(mx,cnt);

        }else{

            cnt = 0;

        }

    }

    cout << mx << endl;

    

    return 0; 

}



// g++ -std=c++14 code1.cpp

// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d

// rm -r -f test;oj dl http://abc122.contest.atcoder.jp/tasks/abc122_a