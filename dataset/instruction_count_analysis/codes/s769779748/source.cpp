#include "stdc++.h"

using namespace std;



typedef long long ll;

const int N = 2e5;

vector<ll> tree(4 * N, 0);



void update(int l, int r, int idx, ll val, int node)

{

	if (l == r)

	{

		tree[node] = val;

	}

	else

	{

		int m = l + (r - l) / 2;

		if (idx >= l && idx <= m)

		{

			update(l, m, idx, val, 2 * node);

		}

		else

		{

			update(m + 1, r, idx, val, 2 * node + 1);

		}

		tree[node] = max(tree[2 * node], tree[2 * node + 1]);

	}

}



ll query(int l, int r, int ql, int qr, int node)

{

	if (ql <= l && qr >= r)

	{

		return tree[node];

	}

	if (ql > r || qr < l)

	{

		return 0;

	}

	int m = l + (r - l) / 2;

	return max(query(l, m, ql, qr, 2 * node), query(m + 1, r, ql, qr, 2 * node + 1));

}



int main()

{

	ios_base::sync_with_stdio(false);



	int n;

	cin >> n;

	vector<ll> h(n), a(n);

	for (int i = 0; i < n; i++)

	{

		cin >> h[i];

	}

	for (int i = 0; i < n; i++)

	{

		cin >> a[i];

	}

	ll answer = 0;

	for (int i = 0; i < n; i++)

	{

		ll temp = query(1, n, 1, h[i] - 1, 1) + a[i];

		answer = max(answer, temp);

		update(1, n, h[i], temp, 1);

	}

	cout << answer;



	return 0;

}