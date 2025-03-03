#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;



const int MAXN = 1000;

const int MAXM = 200000;



vector<int>G[MAXN + 5]; int to[MAXM + 5];

void addedge(int u, int i) {G[u].push_back(i);}



int tag[MAXN + 5], que[2*MAXN + 5];

bool ans1[MAXM + 5], ans2[MAXM + 5];



int n, m;

int main() {

	scanf("%d%d", &n, &m);

	for(int i=1;i<=m;i++) {

		int a; scanf("%d%d", &a, &to[i]);

		addedge(a, i);

	}

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=n;j++) tag[j] = 0;

		int s = 1, t = 0;

		for(int p=0;p<G[i].size();p++)

			tag[que[++t] = to[G[i][p]]] = G[i][p];

		while(s<=t) {

			int x = que[s++], y = tag[x];

			for(int p=0;p<G[x].size();p++) {

				int q = to[G[x][p]];

				if( q != i ) {

					if( tag[q] != -1 ) {

						if( tag[q] == 0 )

							tag[que[++t] = q] = y;

						else if( tag[q] != y )

							tag[que[++t] = q] = -1;

					}

				}

				else ans1[G[x][p]] = 1;

			}

		}

		for(int p=0;p<G[i].size();p++)

			if( tag[to[G[i][p]]] == -1 ) ans2[G[i][p]] = 1;

	}

	for(int i=1;i<=m;i++)

		puts(ans1[i] ^ ans2[i] ? "diff" : "same");

}