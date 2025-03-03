/*

 * Author : Andrew J

*/

#include "stdc++.h"

using namespace std;

#define fi first

#define se second

#define pb push_back

#define mp make_pair

#define all(x) x.begin() , x.end()

#define rall(x) x.rbegin() , x.rend()

#define vz(x) x.size()

using ll = long long;

using ii = pair <ll , ll>;

void in(ll &x);

const ll N = 1e5 + 10;

const ll INF = 1e18 + 50;

const ll MOD = 1e9 + 7;

ll n;



int main() {

  in(n);

  vector <ll> v(3 * n + 1);

  for (ll i = 1 ; i <= 3 * n ; i++) {

    in(v[i]);

  }



  vector <ll> pmax(3 * n + 1 , -INF), smin(3 * n + 2 , INF);

  {

    priority_queue <ll , vector <ll> , greater <ll>> pq;

    ll sum = 0;

    for (ll i = 1 ; i <= n ; i++) {

      sum += v[i];

      pq.push(v[i]);

    }

    pmax[n] = sum;

    for (ll i = n + 1 ; i <= 2 * n ; i++) {

      ll lowest = pq.top(); pq.pop();

      sum -= lowest;

      if (v[i] > lowest) {

        pq.push(v[i]);

        sum += v[i];

      } else {

        pq.push(lowest);

        sum += lowest;

      }

      pmax[i] = max(pmax[i - 1] , sum);

    }

  }

  {

    priority_queue <ll> pq;

    ll sum = 0;

    for (ll i = 3 * n ; i > 2 * n ; i--) {

      sum += v[i];

      pq.push(v[i]);

    }

    smin[n * 2 + 1] = sum;

    for (ll i = 2 * n ; i >= n + 1 ; i--) {

      ll highest = pq.top(); pq.pop();

      sum -= highest;

      if (v[i] < highest) {

        pq.push(v[i]);

        sum += v[i];

      } else {

        pq.push(highest);

        sum += highest;

      }

      smin[i] = min(smin[i + 1] , sum);

    }

  }



  ll ans = -INF;

  for (ll i = n ; i <= 2 * n ; i++) {

    ans = max(ans , pmax[i] - smin[i + 1]);

  }

  printf("%lld\n" , ans);

  return 0;

}



void in(ll &x){

	bool neg = false;

	register ll c;

	x = 0;

	c = getchar();

	if(c == '-'){

		neg = true;

		c = getchar();

	}

	for (; c > 47 && c < 58; c = getchar())

	x = (x << 1) + (x << 3) + c - 48;

	if (neg) x *= -1;

}
