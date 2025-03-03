#include "stdc++.h"

using namespace std;



const int MAXN = 200005;

 

int n, m, ret, a[MAXN], b[MAXN], c[MAXN];

 

int main() {

  cin>>n>>m;

  ret = n;

	for (int i = 1; i <= n; i ++) {

    cin>>a[i];

    c[a[i]]++;

		if (a[i] - c[a[i]] >= 0 && ++b[a[i] - c[a[i]]] == 1)

			ret--;

	}

	while(m--) {

		int x, y; cin>>x>>y;

		if (a[x] - c[a[x]] >= 0 && !--b[a[x] - c[a[x]]])

			ret ++;

		c[a[x]]--;

		a[x] = y;

		c[a[x]] ++;

		if (a[x] - c[a[x]] >= 0 && ++b[a[x] - c[a[x]]] == 1)

			ret --;

		cout<<ret<<'\n';

	}

}