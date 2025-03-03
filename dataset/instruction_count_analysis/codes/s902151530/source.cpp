#include "bits/stdc++.h"

using namespace std;



// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //



#define ll                                       long long

#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)

#define endl                                      '\n'



inline void INP();

const int N = 403, M = 1000000007, inf = INT_MAX;

const long long INF = LLONG_MAX;



int arr[N], n, Q;

ll sum[N], dp[N][N];



ll getans(int s, int e)

{     

      if( s >= e ) return 0;

      ll &mafia = dp[s][e];

      if( mafia != -1 ) return mafia;



      ll ans = INF;

      

      for(ll i = s; i < e; i++)

      {

            ll a1 = getans(s,i), a2 = getans(i+1, e);

            ll sum1 = sum[i] - sum[s-1], sum2 = sum[e] - sum[i];

            ll res = a1 + a2 + sum1 + sum2;

            ans = min(ans, res);

      }



      return mafia = ans;

}

void solve()

{

      cin >> n;

      lop(i,1,n+1) cin >> arr[i];

      lop(i,1,n+1) sum[i] = sum[i-1] + arr[i];

      lop(i,0,n+1) lop(j,i,n+1) dp[i][j] = -1;

      cout << getans(1, n);

}





int32_t main()

{

      

      ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);

      int t = 1;

      //cin >> t;

      while(t--) solve();



}





























// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //









      