//Compete against Yourself.

#include "stdc++.h"

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define int long long

#define pb push_back

#define sz(i) (int)(i.size())

#define F first

#define S second

#define L long double

#define P pair<int, int>

const int inf = 0x3f3f3f3f3f3f3f3LL;

const int mod = (int)1e9 + 7;

using namespace std;

#if LOCAL

#include "../../tr.h"

#else

#define tr(...)

#define endl '\n'

#endif

template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}

const int N = 5*(int)1e5 + 10;



const int M = 62;



int n, a[N];

int32_t main(){_



   cin>>n;



   for (int i = 0; i < n; ++i)

   {

      cin>>a[i];

   }



   vector<int> cnt(M, 0);

   for (int i = 0; i < n; ++i)

   {

      for (int j = 0; j < M; ++j)

      {

         if(a[i] & (1LL << j))

            cnt[j]++;

      }

   }

   

   int ans = 0;

   for (int j = 0; j < M; ++j)

   {

      int ok = (cnt[j]) * (n - cnt[j]) % mod;

      ok *= ((1LL << j) % mod);

      ok %= mod;

      ans += ok;

      ans %= mod;

   }

   

   cout<<ans;



   return 0;

}
