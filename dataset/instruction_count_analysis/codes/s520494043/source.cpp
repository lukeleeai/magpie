#include"stdc++.h"

using namespace std;



#define INF 2000000000

#define ll long long



int res;

int N, P;

vector<pair<int, int> > v;

vector<int> com;

int seg[530000];



void Init()

{

	for(int i=0; i<530000; i++)

		seg[i] = -INF;

}



int Update(int idx, int val, int n, int l, int r)

{

	if (r < idx || idx < l) return seg[n];

	if (l == r) return seg[n] = max(seg[n], val);

	int mid = l+r>>1;

	return seg[n] = max(Update(idx, val, n<<1, l, mid), Update(idx, val, n<<1|1, mid+1, r));

}



int Query(int L, int R, int n, int l, int r)

{

	if (r < L || R < l) return -INF;

	if (L <= l && r <= R) return seg[n];

	int mid = l+r>>1;

	return max(Query(L, R, n<<1, l, mid), Query(L, R, n<<1|1, mid+1, r));

}



int main()

{

	scanf("%d", &N);

	for(int i=1; i<=N; i++)

	{

		int x, y;

		scanf("%d %d", &x, &y);

		v.push_back({x, y});

		com.push_back(y);

	}

	sort(v.begin(), v.end());



	// 좌표 압축

	sort(com.begin(), com.end());

	com.erase(unique(com.begin(), com.end()), com.end());

	P = com.size();



	Init();

	vector<int> qry;

	for(int i=0; i<v.size(); i++)

	{

		int x = v[i].first, y = v[i].second;

		int idx = lower_bound(com.begin(), com.end(), y) - com.begin();

		Update(idx, -x-y, 1, 0, P-1);

		qry.push_back(i);



		if (i+1==v.size() || v[i].first != v[i+1].first)

		{

			for(int j : qry)

			{

				int x = v[j].first, y = v[j].second;

				int idx = lower_bound(com.begin(), com.end(), y) - com.begin();

				res = max(res, Query(0, idx, 1, 0, P-1)+x+y);

			}

			qry.clear();

		}

	}



	Init();

	for(int i=0; i<v.size(); i++)

	{

		int x = v[i].first, y = v[i].second;

		int idx = lower_bound(com.begin(), com.end(), y) - com.begin();

		Update(idx, -x+y, 1, 0, P-1);

		qry.push_back(i);



		if (i+1==v.size() || v[i].first != v[i+1].first)

		{

			for(int j : qry)

			{

				int x = v[j].first, y = v[j].second;

				int idx = lower_bound(com.begin(), com.end(), y) - com.begin();

				res = max(res, Query(idx, P-1, 1, 0, P-1)+x-y); // idx+1로 하면 Query가 -2e9라 음수 overflow...

			}

			qry.clear();

		}

	}



	printf("%d\n", res);

	return 0;

}