#include"stdc++.h"



#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define LL long long

#define pii pair<int,int>

#define SZ(x)  (int)x.size()

#define all(x) x.begin(),x.end()



using namespace std;



LL gcd(LL a, LL b) {return b ? gcd(b, a % b) : a;}

LL lcm(LL a, LL b) {return a / gcd(a, b) * b;}

LL powmod(LL a, LL b, LL MOD) {LL ans = 1; while (b) {if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2;} return ans;}

const int N = 2e5 + 11;

int n;

struct uzi

{

	int a, b;

	bool operator <(const uzi & t)const {

		return 	atan2(a, b) < atan2(t.a, t.b);

	}

} p[N];

double get(LL l, LL r) {

	return sqrt(l * l + r * r);

}

int main() {

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)cin >> p[i].a >> p[i].b;

	sort(p + 1, p + 1 + n);

	double ans = 0;

	for (int i = 1; i <= n; i++) {

		LL x = 0, y = 0;

		for (int j = 0; j < n; j++) {

			x += p[((i + j) % n) == 0 ? n : ((i + j) % n)].a;

			y += p[((i + j) % n) == 0 ? n : ((i + j) % n)].b;

			ans = max(ans, get(x, y));

		}

	}

	cout << fixed << setprecision(20) << ans << endl;

	return 0;

}