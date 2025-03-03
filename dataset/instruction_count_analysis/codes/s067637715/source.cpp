#include "stdc++.h"

using namespace std;

using ll = long long;

const ll m = (ll)1e9 + 7;

const ll N = 100500;

char s[N];

ll n,dp[N][15];



ll ctoi(char x) {

   return x - '0';

}



ll add(ll a , ll b) {

   return (a + b) % 13;

}



ll madd(ll a , ll b) {

   return ((a % m) + (b % m)) % m;

}



ll f(ll curr , ll sum) {

   if (curr >= n) return sum == 5;

   ll &sol = dp[curr][sum];

   if (sol != -1) return sol;

   if (s[curr] != '?') {

      sol = f(curr + 1 , add(sum * 10 , ctoi(s[curr])));

   } else {

      sol = 0;

      for (ll dig = 0 ; dig < 10 ; dig++) {

         sol = madd(sol , f(curr + 1 , add(sum * 10 , dig)));

      }

   }

   return sol % m;

}



int main() {

   scanf("%s" , s);

   n = strlen(s);

   memset (dp , -1 , sizeof dp);

   printf("%lld\n" , f(0 , 0));

}
