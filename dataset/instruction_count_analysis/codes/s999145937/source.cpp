#include <cstdio>

#include <cstring>

#include <vector>

#include <algorithm>

const int MaxN = 131172;

int N;

int Point[MaxN], Next[MaxN], To[MaxN], W[MaxN], q;

long long d[MaxN];

void Add(int u, int v, int w){ Next[++q] = Point[u]; Point[u] = q; To[q] = v; W[q] = w; }

void dfs(int u, long long tmp)

{

	d[u] = tmp;

	for(int j = Point[u]; j; j = Next[j])

		dfs(To[j], tmp + W[j]);

}

struct pair{ int fir, sec; };

typedef std::vector<pair>::iterator iter;

std::vector<pair> S[MaxN], t;

bool cmp1(pair i, pair j){ return d[i.fir] < d[j.fir]; }

bool cmp2(pair i, pair j){ return d[i.sec] > d[j.sec]; }

bool cmp3(pair i, pair j){ return d[i.fir] > d[j.fir]; }

bool cmp4(pair i, pair j){ return d[i.sec] < d[j.sec]; }

bool dfs1(int u, long long v)

{

	S[u].clear();

	for(int j = Point[u]; j; j = Next[j])

	{

		if(dfs1(To[j], v)) return 1;

		if(S[u].empty()) std::swap(S[u], S[To[j]]);

		else

		{

			if(S[u].size() > S[To[j]].size()) std::swap(S[u], S[To[j]]);

			std::sort(S[u].begin(), S[u].end(), cmp2);

			std::sort(S[To[j]].begin(), S[To[j]].end(), cmp1);

			t.clear();

			iter k = S[To[j]].begin(); int sec = 0;

			for(iter i = S[u].begin(); i != S[u].end(); ++i)

			{	

				while(k != S[To[j]].end() && d[i->sec] + d[k->fir] <= v + (d[u] << 1))

				{

					if(d[k->sec] < d[sec]) sec = k->sec;

					++k;

				}

			/*	for(iter k = S[To[j]].begin(); k != S[To[j]].end(); ++k)

					if(d[i->sec] + d[k->fir] <= v + (d[u] << 1) && d[sec] > d[k->sec]) 

						sec = k->sec;*/

				if(sec) t.push_back((pair){i->fir, sec});

			}

			std::sort(S[u].begin(), S[u].end(), cmp3);

			std::sort(S[To[j]].begin(), S[To[j]].end(), cmp4);

			k = S[To[j]].begin(); int fir = 0;

			for(iter i = S[u].begin(); i != S[u].end(); ++i)

			{	

				while(k != S[To[j]].end() && d[k->sec] + d[i->fir] <= v + (d[u] << 1))

				{

					if(d[k->fir] < d[fir]) fir = k->fir;

					++k;

				}

				/*for(iter k = S[To[j]].begin(); k != S[To[j]].end(); ++k)

					if(d[k->sec] + d[i->fir] <= v + (d[u] << 1) && d[fir] > d[k->fir]) 

						fir = k->fir;*/

				if(fir) t.push_back((pair){fir, i->sec});

			}		

			std::swap(t, S[u]);

		}

	}

	if(!Point[u]) S[u].push_back((pair){u, u});

	return S[u].empty();

}

int main()

{

	scanf("%d", &N);

	for(int i = 2; i <= N; ++i)

	{

		int a, v;

		scanf("%d %d", &a, &v);

		Add(a, i, v);

	}

	d[0] = 1ll << 60;

	dfs(1, 0);

	//for(int i = 1; i <= N; ++i) printf("%d ", d[i]); puts("");

	long long l = -1, r = 1ll << 35;

	while(r - l > 1)

	{

		long long mid = l + r >> 1;

	//	printf("%lld\n", mid);

		if(dfs1(1, mid)) l = mid;

		else r = mid;

	}

	printf("%lld\n", r);

	return 0;

}