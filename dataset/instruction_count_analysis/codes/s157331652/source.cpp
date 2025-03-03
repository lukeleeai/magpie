/*

 * Author : Andrew J

*/

#include "stdc++.h"

using namespace std;

#define rall(x) x.rbegin() , x.rend()

#define all(x) x.begin() , x.end()

#define fi first

#define se second

#define pb push_back

using ll = long long;

using ii = pair <ll , ll>;

void in(ll &x);

const ll N = 2e5 + 10;

#define singleCase

// #define multipleCase

ll n,a[N],ps[N];

map <ll , ll> freq;



void work() {

   in(n);

   for (ll i = 1 ; i <= n ; i++) {

      in(a[i]);

      ps[i] = ps[i - 1] + a[i];

   }

   for (ll i = 0 ; i <= n ; i++) {

      freq[ps[i]]++;

   }

   ll sol = 0;

   for (ii x : freq) {

      sol += (x.se * (x.se - 1)) / 2;

   }

   printf("%lld\n" , sol);

   return;

}



int main() {

   #ifdef multipleCase

      ll nQ; in(nQ);

      while (nQ--)

         work();

   #endif

   #ifdef singleCase

      work();

   #endif

   return 0;

}



void in(ll &x) {

	bool neg = false;

	register ll c;

	x = 0;

	c = getchar();

	if(c == '-') {

		neg = true;

		c = getchar();

	}

	for (; c > 47 && c < 58; c = getchar())

	  x = (x << 1) + (x << 3) + c - 48;

	if (neg) x *= -1;

}
