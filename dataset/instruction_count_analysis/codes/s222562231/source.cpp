#include "stdc++.h"

using namespace std;



typedef long long ll;



const int maxn = 1e5 + 5;



int n, m, k;

int w[maxn], f[maxn];

ll ans;

priority_queue <int, vector<int>, greater<int>> q[maxn];

multiset <int> s;



int find(int x)

{

	return f[x] == x ? x : f[x] = find(f[x]);

}



void merge(int x, int y)

{

	int fx = find(x);

	int fy = find(y);

	if(fx != fy)

		f[fx] = fy;

}



int main()

{

	int u, v;

	scanf("%d%d", &n, &m);

	k = n - m;

	if(2 * k - 2 > n)

	{

		puts("Impossible");

		return 0;

	}

	if(k == 1)

	{

		puts("0");

		return 0;

	}

	for(int i = 1; i <= n; i++)

	{

		scanf("%d", &w[i]);

		f[i] = i;

	}

	for(int i = 1; i <= m; i++)

	{

		scanf("%d%d", &u, &v);

		u++, v++;

		merge(u, v);

	}

	for(int i = 1; i <= n; i++)

	{

		find(i);

		q[f[i]].push(w[i]);

	}

	for(int i = 1; i <= n; i++)

		if(!q[i].empty())

		{

			ans += q[i].top();

			q[i].pop();

	//		printf("val = %lld\n", val);

		}

	for(int i = 1; i <= n; i++)

		while(!q[i].empty())

		{

			s.insert(q[i].top());

			q[i].pop();

		}	

//	for(auto it = s.begin(); it != s.end(); it++)

//		printf("%d\n", *it);

	auto it = s.begin();

	for(int i = 1; i <= k - 2; i++, it++)

	{

		ans += *it;

	//	printf("%lld\n", ans);

	}

	printf("%lld\n", ans);

	return 0;

}