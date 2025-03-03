#include "stdc++.h"

using namespace std;



#define   ll     long long int



void sortt(ll &a, ll &b, ll &c)

{

    if (a < b) swap(a, b);

    if (b < c) swap(c, b);

    if (a < b) swap(a, b);

}



ll func(ll h, ll w)

{

    ll i, j, k, s = 1e15;

    ll first, second, third;

    ll w_second = w / 2;

    ll w_third = w - w_second;



    for (i = 1; i < h; i++) {

        first = i * w;

        j = h - i;

        second = j * w_second;

        third = j * w_third;

        sortt(first, second, third);

        s = min(s, first - third);



        first = i * w;

        ll h_second = j / 2;

        ll h_third = j - h_second;

        second = h_second * w;

        third = h_third * w;

        sortt(first, second, third);

        s = min(s, first - third);

        //cout << i << ' ' << first << ' ' << second << ' ' << third << '\n';

    }

    return s;

}



int main( )

{

    ll h, w;

    cin >> h >> w;

    if (h % 3 == 0 || w % 3 == 0) {

        cout << "0\n";

        return 0;

    }

    cout << min(func(h, w), func(w, h)) << '\n';

    return 0;

}
