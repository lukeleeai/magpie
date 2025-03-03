#include "bits/stdc++.h"

 

using namespace std;

typedef long long ll;

typedef vector<ll> vll;

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

/*----------------------------------------------------------------*/



// int MOD = 998244353;

int MOD = 1000000007;





/*----------------------------------------------------------------*/

signed main(){



    string s;

    cin >> s;

    

    int mx = 0;

    int a,b;

    for(int i = 0;i < s.size();i++){

        int cnt = 0;

        rep(j,s.size()){

            if(i+j >= s.size() || (s[i+j] != 'A' && s[i+j] != 'T' && s[i+j] != 'C' && s[i+j] != 'G'))break;

            cnt++;

        }

        mx = max(mx,cnt);

    }

    cout << mx << endl;

    



	return 0;

}

/*----------------------------------------------------------------*/



// g++ -std=c++14 code1.cpp

// sudo pip3 install --upgrade online-judge-tools

// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c

// rm -r -f test;oj dl https://ddcc2020-qual.contest.atcoder.jp/tasks/ddcc2020_qual_b

// rm -r -f test;oj dl https://abc122.contest.atcoder.jp/tasks/abc122_b