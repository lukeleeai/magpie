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

















int N, A[1010101];

//---------------------------------------------------------------------------------------------------

int solve() {

    rep(i, 0, N - 1) A[i] = abs(A[i] - A[i + 1]);

    N--;



    int tot = 0;

    rep(i, 0, N) if (A[i] == 1 && (i | (N - 1 - i)) == N - 1) tot ^= 1;

    if (tot) return 1;



    rep(i, 0, N) if (A[i] == 1) return 0;



    tot = 0;

    rep(i, 0, N) if (A[i] == 2 && (i | (N - 1 - i)) == N - 1) tot ^= 2;

    return tot;

}

//---------------------------------------------------------------------------------------------------

void _main() {

    cin >> N; string S; cin >> S;

    rep(i, 0, N) A[i] = S[i] - '0';

    cout << solve() << endl;

}










