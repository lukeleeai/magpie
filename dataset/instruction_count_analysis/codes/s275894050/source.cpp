#include "stdc++.h"

using namespace std;



typedef long long ll;



const int mxN = 2e5 + 5;

const ll INF = 1e18;

int N, M, ls[mxN], rs[mxN];

ll a[mxN], dp[mxN], tree[4 * mxN], lz[4 * mxN];

vector<int> st[mxN], en[mxN];



inline void add(ll* arr, int v, ll val) {

    arr[v] += val;

}



void lazy(int node) {

    add(lz, 2 * node, lz[node]);

    add(tree, 2 * node, lz[node]);

    add(lz, 2 * node + 1, lz[node]);

    add(tree, 2 * node + 1, lz[node]);

    lz[node] = 0;

}



void update(int l, int r, int ql, int qr, ll val, int node) {

    if (ql > qr) {

        return;

    }

    if (ql > r || qr < l) {

        return;

    }

    if (ql <= l && qr >= r) {

        add(tree, node, val);

        add(lz, node, val);

        return;

    }

    lazy(node);

    int mid = l + (r - l) / 2;

    update(l, mid, ql, qr, val, 2 * node);

    update(mid + 1, r, ql, qr, val, 2 * node + 1);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);

}



ll query(int l, int r, int ql, int qr, int node) {

    if (ql > qr) {

        return -INF;

    }

    if (ql > r || qr < l) {

        return -INF;

    }

    if (ql <= l && qr >= r) {

        return tree[node];

    }

    lazy(node);

    int mid = l + (r - l) / 2;

    return max(query(l, mid, ql, qr, 2 * node), query(mid + 1, r, ql, qr, 2 * node + 1));

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);



    cin >> N >> M;

    for (int i = 0; i < M; i++) {

        cin >> ls[i] >> rs[i] >> a[i];

        st[ls[i]].push_back(i);

        en[rs[i]].push_back(i);

    }

    ll ans = 0;

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {

        for (int idx : st[i]) {

            update(0, N, 0, i - 1, a[idx], 1);

        }

        dp[i] = query(0, N, 0, i - 1, 1);

        ans = max(ans, dp[i]);

        update(0, N, i, i, dp[i], 1);

        for (int idx : en[i]) {

            update(0, N, 0, ls[idx] - 1, -a[idx], 1);

        }

    }

    cout << ans;



    return 0;

}