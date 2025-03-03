#include "stdc++.h"

#define mem(a,v) memset((a), (v), sizeof (a))

#define ni(n) scanf("%d", &(n))

#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])

using namespace std;

const int MAXN = 1e5 + 5;

int t[MAXN], v[MAXN], ans = 0, n;

int miB[MAXN], miF[MAXN], mi[MAXN];



int main() {

	ni(n); mem(miB, 0x3f), mem(miF, 0x3f);

	nai(t, n); nai(v, n); mem(mi, 0x3f);

	for (int i = 0; i < n; i++) t[i] *= 2, v[i] *= 2;

	for (int i = 1; i < n; i++) t[i] += t[i-1];

	for (int i = 1; i < n; i++) miB[t[i-1]] = v[i];

	miB[t[n-1]] = miF[0] = 0;

	for (int i = t[n-1]-1; ~i; i--) miB[i] = min(miB[i], miB[i+1]+1);

	for (int i = 0; i < n; i++) miF[t[i]] = v[i];

	for (int i = 1; i <= t[n-1]; i++) miF[i] = min(miF[i], miF[i-1]+1);

	for (int i = 0; i < n; i++) for (int j = !i?0:t[i-1]; j <= t[i]; j++) mi[j] = min(mi[j], v[i]);

	for (int i = 0; i <= t[n-1]; i++) mi[i] = min(mi[i], min(miF[i],miB[i]));

	for (int i = 0; i < t[n-1]; i++) ans += (mi[i+1]+mi[i]);

	printf("%.20f\n", (double)ans/8.);

	return 0;

}
