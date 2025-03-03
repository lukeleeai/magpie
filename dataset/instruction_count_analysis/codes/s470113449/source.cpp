#include <cstdio>

#include <cstring>

#include <algorithm>

#include <string>

#include <cmath>

#include <stack>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <list>

#include <iostream>

#include <sstream>

#include <climits>

#include <cfloat>

#include <complex>



using namespace std;



typedef long long ll;



ll count_rooms_lesseq_than(ll newRoomNo)

{

	int t[10], d;

	for (d = 0; newRoomNo; ++d, newRoomNo /= 10)

		t[d] = newRoomNo % 10;

	for (int i = d-1; i > 0; --i)

	{

		if (t[i] == 4 || t[i] == 6)

		{

			--t[i];

			for (int j = 0; j < i; ++j)

				t[j] = 9;

			break;

		}

	}



	ll res = 0;

	for (int i = 0; i < d; ++i)

	{

		ll a = 1;

		for (int j = 0; j < i; ++j)

			a *= 8;

		res += (t[i] - (t[i] >= 6 ? 2 : t[i] >= 4 ? 1 : 0)) * a;

	}

	return res;

}

int main()

{

	int n;

	while (scanf("%d", &n), n)

	{

		ll l, u;

		l = 1;

		u = n * 10LL;

		while (l < u)

		{

			ll m = (l + u) / 2;

			ll t = count_rooms_lesseq_than(m);

			if (t < n)

				l = m + 1;

			else

				u = m;

		}

		printf("%lld\n", l);

	}



	return 0;

}