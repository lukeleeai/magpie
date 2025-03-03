#include <iostream>

#include <map>

#include <vector>

#include <algorithm>

#include <map>

#include <string>

#include <queue>

#include <set>

#include <math.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

typedef pair<ll, P> Q;

const ll mod = 1000000007;

const ll INF = 1000000000000000;

ll bit[100010], num;

ll par[100010], sz[100010];

ll n, a;

multiset<ll> st;





struct edge { ll to, cost; };

ll V;

vector<edge> G[300010];

ll d[300010];



ll root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}

	if (par[x] == x) return x;

	return par[x] = root(par[x]);

}



void unite(int x, int y) { // x��y�̖؂𕹍�

	int rx = root(x); //x�̍���rx

	int ry = root(y); //y�̍���ry

	if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�

	par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���

}



bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�

	int rx = root(x);

	int ry = root(y);

	return rx == ry;

}



ll sum(ll i)

{

	ll s = 0;

	while (i > 0)

	{

		s += bit[i];

		i -= i & -i;

	}

	return s;

}



void add(ll i, ll x)

{

	while (i <= num)

	{

		bit[i] += x;

		i += i & -i;

	}

}



ll po(ll x, ll y)

{

	if (y == 0) return 1;

	if (y % 2)

	{

		return po(x, y - 1) * x % mod;

	}

	else

	{

		ll yyy = po(x, y / 2);

		return yyy * yyy % mod;

	}

}



ll pow_mod(ll x, ll y)

{

	ll res = 1;

	while (y > 0)

	{

		if (y % 2 == 1)

		{

			(res *= x) %= mod;

		}

		(x *= x) %= mod;

		y /= 2;

	}

	return res;

}



ll div(ll x)

{

	return po(x, mod - 2);

}



int main(void)

{

	cin >> n;

	for (int i = 0; i < n; i++)

	{

		cin >> a;

		if (i == 0)

		{

			st.insert(a);

		}

		else

		{

			auto itr = st.lower_bound(a);

			if (itr != st.begin())

			{

				itr--;

				st.erase(itr);

			}

			st.insert(a);

		}

	}



	cout << st.size() << endl;



	int www;

	cin >> www;

}
