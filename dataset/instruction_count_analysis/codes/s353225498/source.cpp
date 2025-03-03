#include"stdc++.h"

#include<deque>

#include<iostream>

#include<algorithm>

using namespace std;

#define ll long long





const int maxn = 3e5 + 5;

int n, m;

ll t[maxn], p[maxn], f[maxn], g[maxn], F[maxn], G[maxn], h[maxn];

pair<int, ll> drink[maxn];

struct node

{

	ll x, y;

};

double k(const node &a, const node &b)

{

	return double(a.y - b.y) / double(a.x - b.x);

}

ll crossz(const node &a, const node &b, const node& c)

{

	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);

}

void rev(ll *a)

{

	for (int i = 1; i <= n - i + 1; ++i)swap(a[i], a[n - i + 1]);

}

void cal(ll *dp)

{

	p[0] = 0;

	for (int i = 1; i <= n; ++i)p[i] = p[i - 1] + t[i];

	deque<node> Q;

	Q.push_back({ 0, 0 });

	dp[0] = 0;

	for (ll i = 1; i <= n; ++i)

	{

		dp[i] = dp[i - 1];

		while (Q.size() > 1)

		{

			node temp = Q.back(); Q.pop_back();

			node temp2 = Q.back();

			ll ans1, ans2;

			ans1 = temp.y - i * temp.x - p[i] + (i*i + i) / 2;

			ans2 = temp2.y - i * temp2.x - p[i] + (i*i + i) / 2;

			if (ans1 > ans2)

			{

				Q.push_back(temp);

				break;

			}

		}

		dp[i] = max(dp[i], Q.back().y - i * Q.back().x - p[i] + (i*i + i) / 2);

		//add dp[i]

		node temp = { i, dp[i] + p[i] + (i * i - i) / 2 };

		while (Q.size() > 1)

		{

			node back = Q.back(); Q.pop_back();

			//用除法求斜率判大小，精度有误差

			double k1 = k(temp, back), k2 = k(back, Q.back());

			if (k1 < k2)

			//if(crossz(Q.back(), back, temp) < 0)

			{

				Q.push_back(back); break;

			}

		}

		Q.push_back(temp);

	}

}



void calh(int l, int r)

{

	if (l == r)

	{

		h[l] = max(h[l], f[l - 1] + g[r + 1] + 1 - t[l]);

		return;

	}

	int mid = (l + r >> 1);

	for (ll i = l; i <= mid; ++i)F[i] = f[i - 1] + p[i - 1] + (i*i - 3 * i) / 2 + 1;

	for (ll j = mid + 1; j <= r; ++j)G[j] = g[j + 1] - p[j] + (j*j + j * 3) / 2;

	deque<node> Q;

	for (int i = mid + 1; i <= r; ++i)

	{

		node now = { i,  G[i] };

		while (Q.size() > 1)

		{

			node tmp = Q.back(); Q.pop_back();

			double k1 = k(now, tmp), k2 = k(tmp, Q.back());

			if(k1 < k2)//if(crossz(Q.back(), tmp, now) < 0)//if (k1 < k2)

			{

				Q.push_back(tmp); break;

			}

		}

		Q.push_back(now);

	}

	ll t = -4e18;

	for (ll j = l; j <= mid; ++j)

	{

		while (Q.size() > 1)

		{

			ll ans1, ans2;

			node tmp = Q.back(); Q.pop_back();

			ans1 = tmp.y - tmp.x * j, ans2 = Q.back().y - Q.back().x * j;

			if (ans1 > ans2)

			{

				Q.push_back(tmp); break;

			}

		}

		t = max(t, Q.back().y - Q.back().x * j + F[j]);

		h[j] = max(t, h[j]);

	}

	calh(l, mid); calh(mid + 1, r);

}



void solve()

{

	cin >> n;

	for (int i = 1; i <= n; ++i)cin >> t[i];

	cin >> m;

	//for (int i = 1; i <= m; ++i)cin >> drink[i].first >> drink[i].second;

	memset(h, 0xbf, sizeof(h));//初值不能为0，因为要求i必选，值可能为负

	cal(f);

	rev(t); cal(g);

	rev(t); rev(g);

	for (int i = 1; i <= n; ++i)p[i] = p[i - 1] + t[i];

	calh(1, n);

	rev(t);

	for (int i = 1; i <= n; ++i)p[i] = p[i - 1] + t[i];

	swap(f, g); rev(f); rev(g);

	rev(h);

	calh(1, n);

	rev(t); rev(h); rev(f); rev(g);

	swap(f, g);



	for (int i = 1; i <= m; ++i)

	{

		ll p, v; cin >> p >> v;

		//ll p = drink[i].first, v = drink[i].second;

		ll ans = max(f[p - 1] + g[p + 1], h[p] + t[p] - v);

		cout << ans << "\n";

	}

}

signed main()

{

	ios::sync_with_stdio(false); cin.tie(0);

	//	int t; cin >> t;

	//	for(int i = 1; i <= t; ++i)

	solve();

	//system("pause");

	return 0;

}