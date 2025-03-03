//#pragma GCC optimize("O3")

#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/rope>

#define mem(a,v) memset((a), (v), sizeof (a))

#define enl printf("\n")

#define case(t) printf("Case #%d: ", (t))

#define ni(n) scanf("%d", &(n))

#define nl(n) scanf("%lld", &(n))

#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])

#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])

#define pri(n) printf("%d\n", (n))

#define prl(n) printf("%lld\n", (n))

#define pii pair<int, int>

#define pil pair<int, long long>

#define pll pair<long long, long long>

#define vii vector<pii>

#define vil vector<pil>

#define vll vector<pll>

#define vi vector<int>

#define vl vector<long long>

#define pb push_back

#define mp make_pair

#define fi first

#define se second

using namespace std;

using namespace __gnu_pbds;

typedef long long ll;

typedef cc_hash_table<int,int,hash<int>> ht;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;

const double pi = acos(-1);

const int MOD = 1e9 + 7;

const int INF = 1e9 + 7;

const int MAXN = 1e6 + 5;

const double eps = 1e-9;

int t[MAXN], v[MAXN], ans = 0, tmp[MAXN];

int miB[MAXN], miF[MAXN], mi[MAXN];



int main() {

	int n; ni(n); mem(miB, 0x3f), mem(miF, 0x3f);

	nai(t, n); nai(v, n); mem(mi, 0x3f);

	for (int i = 0; i < n; i++) t[i] *= 2, v[i] *= 2;

	for (int i = 1; i < n; i++) t[i] += t[i-1];

	for (int i = 1; i < n; i++) miB[t[i-1]] = v[i];

	miB[t[n-1]] = 0;

	for (int i = t[n-1]-1; ~i; i--) miB[i] = min(miB[i], miB[i+1]+1);

	for (int i = 0; i < n; i++) miF[t[i]] = v[i];

	miF[0] = 0;

	for (int i = 1; i <= t[n-1]; i++) miF[i] = min(miF[i], miF[i-1]+1);

	for (int i = 0; i < n; i++)

		for (int j = !i?0:t[i-1]; j <= t[i]; j++)

			mi[j] = min(mi[j], v[i]), tmp[j] = mi[j];

	for (int i = 0; i <= t[n-1]; i++) mi[i] = min(mi[i], min(miF[i],miB[i]));

	for (int i = 0; i < t[n-1]; i++) ans += (mi[i+1]+mi[i]);

	printf("%.20f\n", (double)ans/8.);

    return 0;

}
