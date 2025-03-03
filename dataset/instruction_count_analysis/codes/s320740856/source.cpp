#include"stdc++.h"

#define rep(i,a,b) for(int i=a;i<b;i++)

#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define fore(i,a) for(auto &i:a)

#define all(x) (x).begin(),(x).end()

//#pragma GCC optimize ("-O3")

using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//---------------------------------------------------------------------------------------------------

/*---------------------------------------------------------------------------------------------------

　　　　　　　　　　　 ∧＿∧

　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!

　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0

　　　　／　　　＼　 　  |　|

　　　 /　　 /￣￣￣￣/　　|

　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿

　 　　　＼/＿＿＿＿/　（u　⊃

---------------------------------------------------------------------------------------------------*/





























int A, B, M;

int a[101010], b[101010];

//---------------------------------------------------------------------------------------------------

void _main() {

	cin >> A >> B >> M;

	rep(i, 0, A) cin >> a[i];

	rep(i, 0, B) cin >> b[i];



	int mi_a = inf;

	rep(i, 0, A) chmin(mi_a, a[i]);



	int mi_b = inf;

	rep(i, 0, B) chmin(mi_b, b[i]);



	int ans = mi_a + mi_b;

	rep(i, 0, M) {

		int x, y, c; cin >> x >> y >> c;

		y--; x--;

		chmin(ans, a[x] + b[y] - c);

	}

    cout << ans << endl;

}










