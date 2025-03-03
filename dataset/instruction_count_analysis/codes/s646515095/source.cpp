#include "stdc++.h"



using namespace std;



struct INFO {

	int zhou,ord;

	bool operator < (const INFO &b) const {

		return zhou < b.zhou;

	}

}X[100010],Y[100010];

int N,fa[100010];



int fin (int u) {

	if(fa[u] == u)

		return u;

	return fa[u] = fin(fa[u]);

}



struct edge {

	int u,v,w;

	bool operator < (const edge &b) const {

		return w < b.w;

	}

}e[200010];



int main () {

	scanf("%d",&N);



	for(int i = 1;i <= N;++i) {

		scanf("%d%d",&X[i].zhou,&Y[i].zhou);

		X[i].ord = i;

		Y[i].ord = i;

	}

	sort(X + 1,X + 1 + N);

	sort(Y + 1,Y + 1 + N);



	int l = 0,r = 1000000000;

	int mid,cnt;

	while(l <= r) {

		mid = (l + r) >> 1;

		cnt = 0;

		for(int i = 1;i <= N;++i)

			fa[i] = i;



		for(int i = 2;i <= N;++i) {

			if(X[i].zhou - X[i - 1].zhou <= mid) {

				if(fin(X[i].ord) != fin(X[i - 1].ord)) {

					fa[fin(X[i].ord)] = fin(X[i - 1].ord);

					++cnt;

				}

			}

			if(Y[i].zhou - Y[i - 1].zhou <= mid) {

				if(fin(Y[i].ord) != fin(Y[i - 1].ord)) {

					fa[fin(Y[i].ord)] = fin(Y[i - 1].ord);

					++cnt;

				}

			}

		}

		if(cnt == N - 1)

            r = mid - 1;

		else l = mid + 1;

	}

	mid = r + 1;

	cnt = 0;

	for(int i = 2;i <= N;++i) {

		if(X[i].zhou - X[i - 1].zhou <= mid) {

			e[++cnt].u = X[i].ord;

			e[cnt].v = X[i - 1].ord;

			e[cnt].w = X[i].zhou - X[i - 1].zhou;

		}

		if(Y[i].zhou - Y[i - 1].zhou <= mid) {

			e[++cnt].u = Y[i].ord;

			e[cnt].v = Y[i - 1].ord;

			e[cnt].w = Y[i].zhou - Y[i - 1].zhou;

		}

	}

	int ans = 0;

	sort(e +1,e + 1 + cnt);

	for(int i = 1;i <= N;++i)

		fa[i] = i;

	for(int i = 1;i <= cnt;++i) {

		if(fin(e[i].u) != fin(e[i].v)) {

			fa[fin(e[i].u)] = fin(e[i].v);

			ans += e[i].w;

		}

	}

	printf("%d\n",ans);



}
