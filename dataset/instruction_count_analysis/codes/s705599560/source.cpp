#include <iostream>

#include <algorithm>

using namespace std;

const int N = 305;

int a[N][N], id[N], cnt[N];

bool vis[N];

int main()

{

	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= m; j++)

			cin >> a[i][j];

	for (int i = 1; i <= n; i++)

	{

		id[i] = 1;

		cnt[a[i][1]]++;

	}

	int ans = *max_element(cnt + 1, cnt + m + 1);

	for (int i = 1; i < m; i++)

	{

		vis[max_element(cnt + 1, cnt + m + 1) - cnt] = true;

		fill(cnt + 1, cnt + m + 1, 0);

		for (int j = 1; j <= n; j++)

		{

			while (vis[a[j][id[j]]])

				id[j]++;

			cnt[a[j][id[j]]]++;

		}

		ans = min(ans, *max_element(cnt + 1, cnt + m + 1));

	}

	cout << ans << endl;

	return 0;

}