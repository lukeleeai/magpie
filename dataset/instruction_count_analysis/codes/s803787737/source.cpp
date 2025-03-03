#include "stdc++.h"



using namespace std;



int p[111111], q[30][111111];

int main()

{

	int N, m, n = 0;

	cin >> N >> m;

	for (int i = 0; i < N; i++) {

		int s, t, c;

		scanf("%d%d%d", &s, &t, &c);

		n = max(n, t);

		if (!q[--c][s])

			q[c][s--] = 1;

		if (q[c][t]) t--;

		else q[c][t] = 1;

		while (s < t) p[s++]++;

	}

	m = 0;

	for (int i = 1; i <= n; i++)

		m = max(m, p[i]);

	cout << m << endl;

	return 0;

}
