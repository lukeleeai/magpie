#include "bits/stdc++.h"

using namespace std;

#define ll long long int

#define rep(i,n) for( int i = 0; i < n; i++ )

#define rrep(i,n) for( int i = n; i >= 0; i-- )

#define REP(i,s,t) for( int i = s; i <= t; i++ )

#define RREP(i,s,t) for( int i = s; i >= t; i-- )

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF 2000000000

#define mod 1000000007

#define INF2 1000000000000000000



vector<int> v[200010];

int A[200010];

bool isOK(int index, int key) {

    int size = v[index].size();

    if (v[index][size - 1] < key) return true;

    else return false;

}



// 汎用的な二分探索のテンプレ

int binary_search(int key, int size) {

    int ng = -1;

    int ok = size;



    /* ok と ng のどちらが大きいかわからないことを考慮 */

    while (abs(ok - ng) > 1) {

        int mid = (ok + ng) / 2;



        if (isOK(mid, key)) ok = mid;

        else ng = mid;

    }

    return ok;

}



int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int N; cin >> N;

    rep(i, N) cin >> A[i];

    int size = 0;

    rep(i, N) {

        int idx = binary_search(A[i], size);

        v[idx].push_back(A[i]);

        size = max(size, idx + 1);

    }

    cout << size << endl;



    return 0;

}
