//============================================================================

// Name        : training.cpp

// Author      : CoNKeR The Red Squirrel

//============================================================================

#include "stdc++.h"



#define MAX_N 200005

#define INF 1000000000

#define bit(mask, i) (mask & (1<<i))



using namespace std;



typedef pair<int, int> ii;

typedef pair<ii, int> iii;

typedef vector<ii> vii;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<vii> vvii;

typedef long long ll;

typedef double lf;



ll dp[MAX_N], frec[30], n;



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    //freopen("acmproject.in", "r", stdin);

    //freopen("acmproject.out", "w", stdout);



    string s;

    cin>>s;

    n = (ll)s.size();

    dp[0] = 1;

    frec[s[0] - 'a']++;

    for(ll i = 1; i < n; ++i) { dp[i] = dp[i - 1] + i - frec[s[i] - 'a']++; }

    cout<<dp[n - 1]<<"\n";



    return 0;

}