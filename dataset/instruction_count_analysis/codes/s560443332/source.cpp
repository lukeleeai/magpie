#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cmath>

#include <vector>

#include <list>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <cctype>

#include <climits>

#include <string>

#include <bitset>

#include <cfloat>

#include <unordered_set>

using namespace std;

typedef long double ld;

typedef long long int ll;

typedef unsigned long long int ull;

typedef vector<int> vi;

typedef vector<char> vc;

typedef vector<bool> vb;

typedef vector<double> vd;

typedef vector<string> vs;

typedef vector<ll> vll;

typedef vector<pair<int,int> > vpii;

typedef vector<vector<int> > vvi;

typedef vector<vector<char> > vvc;

typedef vector<vector<string> > vvs;

typedef vector<vector<ll> > vvll;

#define rep(i,n) for(int i = 0; i < (n); ++i)

#define rrep(i,n) for(int i = 1; i <= (n); ++i)

#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)

#define fin(ans) cout<<(ans)<<endl

#define STI(s) atoi(s.c_str())

#define mp(p,q) make_pair(p, q)

#define pb(n) push_back(n)

#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()

#define Sort(a) sort(a.begin(), a.end())

#define Rort(a) sort(a.rbegin(), a.rend())

#define MATHPI acos(-1)

#define itn int

template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

struct io{io(){ios::sync_with_stdio(false);cin.tie(0);};};

const ll MOD = 1000000007;

const int INF = INT_MAX;

const ll LLINF = 1LL<<62;



int lcs(string s, string t) {

    vvi dp(s.size() + 1, vi(t.size() + 1));

    

    for(int i = 0; i < s.size(); i++) {//LCS

        for(int j = 0; j < t.size(); j++) {

            if(s[i] == t[j]) {

                dp[i + 1][j + 1] = dp[i][j] + 1;

            }

            else{

                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

            }

        }

    }

    return dp[(int)s.size()][(int)t.size()];

}



int main(void){



   int n;

   string s;

   cin>>n>>s;

   ll ans=0;

   for(char i='0';i<='9';i++){

       for (char j = '0'; j <= '9'; j++)

       {

           for (char k = '0'; k <= '9'; k++)

           {

               string tmp="";tmp+=i;tmp+=j;tmp+=k;

               if(lcs(s,tmp)==3)ans++;

           }

       }

   }

   fin(ans);

}