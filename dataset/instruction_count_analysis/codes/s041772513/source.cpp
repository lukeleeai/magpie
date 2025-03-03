#include "stdc++.h"

 

using namespace std;

 

int n, p[200005], in[200005], ta, tb;

set< int > s[200005];

vector< int > x, y;

bool v[200005];

 

void go(int a) {

	v[a] = 1;

	for (int i = 0; ; i++)

		if (s[a].find(i) == s[a].end()) {

			s[p[a]].insert(i);

			break;

		}

	in[p[a]]--;

	if (in[p[a]] == 0)

		go(p[a]);

}

 

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		scanf("%d", p + i);

		in[p[i]]++;

	}

	for (int i = 1; i <= n; i++)

		if (!in[i] && !v[i])

			go(i);

	for (int i = 1; i <= n; i++)

		if (!v[i]) {

			ta = i;

			while (1) {

				x.push_back(ta);

				if (p[ta] == i)

					break;

				ta = p[ta];

			}

			break;

		}

	for (int i = 0; y.size() < 2; i++)

		if (s[x[0]].find(i) == s[x[0]].end())

			y.push_back(i);

	for (int i = 0; i < 2; i++) {

		in[0] = y[i];

		for (int j = 1; j < x.size(); j++)

			for (int k = 0; ; k++)

				if (in[j - 1] != k && s[x[j]].find(k) == s[x[j]].end()) {

					in[j] = k;

					break;

				}

		if (i == 0 && in[x.size() - 1] != y[0]) {

			printf("POSSIBLE\n");

			return 0;

		}

		if (i == 1 && in[x.size() - 1] == y[0]) {

			printf("POSSIBLE\n");

			return 0;

		}

	}

	printf("IMPOSSIBLE\n");

	return 0;

}