#include "bits/stdc++.h"

using namespace std;



// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //



#define int                                       long long

#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)

#define rlop(i,e,s)                               for(int i=e;i>=s;i--)

#define prvec(v)                                  lop(R15,0,v.size())cout << v[R15] <<" "; cout << endl;

#define prarr(arr,s1,e1)                          lop(R15,s1,e1)cout << arr[R15] << " "; cout << endl;



#define endl                                      '\n'

#define ff                                        first

#define ss                                        second

#define pii                                       pair<int,int>



#define pb                                        push_back

#define all(v)                                    v.begin(),v.end()         



#define bug(...)                                  __f (#__VA_ARGS__, __VA_ARGS__)

#define rtn                                       if(0)return;

template <typename Arg1>

void __f (const char* name, Arg1&& arg1) { rtn cout << name << " : " << arg1 << endl; }

template <typename Arg1, typename... Args>

void __f (const char* names, Arg1&& arg1, Args&&... args)

{     rtn 

     const char* comma = strchr (names + 1, ',');

     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);

}



// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //



inline void INP();

const int N = 1e3 + 7, M = 1000000007, inf = INT_MAX;

const long long INF = LLONG_MAX;



int arr[N], n, Q, sum[N];

int dp[N][N];



int getsum(int s, int e)

{     

      int sum = 0;

      lop(i,s,e+1) sum += arr[i];

      return sum;

}



int getans(int s, int e)

{     

      if( s >= e ) return 0;

      int &mafia = dp[s][e];

      if( mafia != -1 ) return mafia;



      int ans = INF;

      

      for(int i = s; i < e; i++)

      {

            int a1 = getans(s,i), a2 = getans(i+1, e);

            int sum1 = getsum(s, i), sum2 = getsum(i+1, e);

            int res = a1 + a2 + sum1 + sum2;

            ans = min(ans, res);

      }



      return mafia = ans;

}

void solve()

{

      cin >> n;

      lop(i,1,n+1) cin >> arr[i];

      memset(dp, -1, sizeof dp);

      cout << getans(1, n) << endl ;

}





int32_t main()

{

      

      ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);

     // INP(); 

      int t = 1;

      //cin >> t;

      while(t--) solve();



}























inline void INP()

{

      #ifndef ONLINE_JUDGE

          freopen("input.txt",  "r",  stdin);

          freopen("output.txt", "w", stdout);

      #endif

}





// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //









      