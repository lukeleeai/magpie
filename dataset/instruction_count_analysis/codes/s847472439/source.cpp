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

#define def inf

template<class V, int NV> struct SegTree { //[l,r)

    V comp(V& l, V& r) { return min(l, r); };



    vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }

    V get(int x, int y, int l = 0, int r = NV, int k = 1) {

        if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];

        auto a = get(x, y, l, (l + r) / 2, k * 2); 

        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);

        return comp(a, b);

    }

    void update(int i, V v) {

        i += NV; val[i] = v;

        while (i>1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);

    }

    void add(int i, V v) { update(i, val[i + NV] + v); }

    V operator[](int x) { return get(x, x + 1); }

};

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

vector<pair<int,int>> coupons[101010];

SegTree<int, 1 << 17> st;

//---------------------------------------------------------------------------------------------------

void _main() {

	cin >> A >> B >> M;

	rep(i, 0, A) cin >> a[i];

	rep(i, 0, B) cin >> b[i];

    rep(i, 0, B) st.update(i, b[i]);



	rep(i, 0, M) {

		int x, y, c; cin >> x >> y >> c;

		y--; x--;



		coupons[x].push_back({ y, c });

	}



	int ans = inf;

	rep(i, 0, A) {

        fore(cp, coupons[i]) {

            chmin(ans, a[i] + b[cp.first] - cp.second);

            st.update(cp.first, inf);

        }



        chmin(ans, a[i] + st.get(0, B));



        fore(cp, coupons[i]) st.update(cp.first, b[cp.first]);

	}

    cout << ans << endl;

}










