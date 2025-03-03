#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>



using namespace std;

template <typename T>

using V = vector<T>;

template <typename S, typename T>

using P = pair<S, T>;

using ll = long long;



#define FOR(i, a, b) for (ll i = (a); i < (b); i++)

#define NREP(i, n) FOR(i, 1, n + 1)

// Natural REP runs from 1 to n 



/* ---------- ここまでマクロ ----------- */



ll N;

V<ll> A(200010), sum(200010, 0);





// 区間[b, e]をできるだけ均等に2等分したときの、

// 各配列の総和をペアで返す

P<ll, ll> divide(ll b, ll e) {

    ll ok = b, ng = e;

    ll ds = sum[e] - sum[b - 1];



    // 二分探索で[b, ok]の和が[b, e]の半分以下になる

    // 最大のokを探す

    while (ng - ok > 1) {

        ll mid = (ok + ng) / 2;

        ll ps = sum[mid] - sum[b - 1];

        if (ps * 2 <= ds) {

            ok = mid;

        } else {

            ng = mid;

        }

    }



    // P <= Qの場合

    P<ll, ll> ret1 = make_pair(sum[ok] - sum[b - 1], sum[e] - sum[ok]);

    // P > Qの場合

    P<ll, ll> ret2 = make_pair(sum[ok + 1] - sum[b - 1], sum[e] - sum[ok + 1]);

    

    // 両者を比較

    if (ret1.first - ret1.second > ret2.second - ret2.first) {

        return ret1;

    } else {

        return ret2;

    }

}





// [0, itr)と[itr, N)に分割したときの最適解

ll cut(ll itr) {

    V<P<ll, ll>> psum(2);

    

    psum[0] = divide(1, itr);        // (P, Q)

    psum[1] = divide(itr + 1, N);    // (R, S)



    V<ll> elem;

    // psumを統合する

    

    for (auto p : psum) {

        elem.push_back(p.first);

        elem.push_back(p.second);

    }



    sort(elem.begin(), elem.end());

    return elem.back() - elem.front();

    // 最大値と最小値の差を返す(B問題その2を参照)

}





int main() {

    cin >> N;

    NREP(i, N) {

        cin >> A[i];

        sum[i] = sum[i - 1] + A[i];

        // 同時に累積和も計算

    }



    ll ans = sum[N];



    FOR(i, 2, N - 1) {

        // 全ての2分割を試す(ただし分割後の要素数>=2)

        ans = min(ans, cut(i));

    }



    cout << ans << endl;

    return 0;

}