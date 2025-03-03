//Compete against Yourself.

#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define pb push_back

#define sz(i) (int)(i.size())

#define F first

#define S second

#define L long double

#define P pair<int, int>

const int mod = (int)1e9 + 7;

using namespace std;

#if LOCAL

#include "../../tr.h"

#else

#define tr(...)

#define endl '\n'

#endif

template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}

const int N = 80;



int n, m, a[N][N], b[N][N];

gp_hash_table<int, int> dp[N][N];



void add(int x, int y, int red, int blue){

   if(x-1 >= 0){

      for(auto it: dp[x-1][y]){

         dp[x][y][abs(it.F+(red-blue))] = 1;

         dp[x][y][abs(it.F-(red-blue))] = 1;

      }

   }

   if(y-1 >= 0){

      for(auto it: dp[x][y-1]){

         dp[x][y][abs(it.F+(red-blue))] = 1;

         dp[x][y][abs(it.F-(red-blue))] = 1;

      }

   }

   if(x-1 < 0 and y-1 < 0){

      dp[x][y][abs(red-blue)] = 1;

   }

}





int32_t main(){_



   cin>>n>>m;



   for (int i = 0; i < n; ++i)

   {

      for (int j = 0; j < m; ++j)

      {

         cin >> a[i][j];

      }

   }



   for (int i = 0; i < n; ++i)

   {

      for (int j = 0; j < m; ++j)

      {

         cin >> b[i][j];

      }

   }



   for (int i = 0; i < n; ++i)

   {

      for (int j = 0; j < m; ++j)

      {

         add(i, j, a[i][j], b[i][j]);

      }  

   }

   

   int ans = 2e9;

   for(auto it: dp[n-1][m-1]){

      smin(ans, it.F);

   }



   cout<<ans;



   return 0;

}
