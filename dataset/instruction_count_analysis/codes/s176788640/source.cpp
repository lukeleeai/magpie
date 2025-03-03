#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); i++)

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

using ll = long long;

using namespace std;



struct P {

    ll taste;

    int a;

    int b;

    int c;



    bool operator<(const P &another) const {

        return taste < another.taste;

    };

};



int main() {

    int X, Y, Z, K;

    cin >> X >> Y >> Z >> K;

    vector<ll> A(X + 2000, -10000000000);

    vector<ll> B(Y + 2000, -10000000000);

    vector<ll> C(Z + 2000, -10000000000);

    rep(i, X) cin >> A[i];

    rep(i, Y) cin >> B[i];

    rep(i, Z) cin >> C[i];

    sort(rall(A));

    sort(rall(B));

    sort(rall(C));



    priority_queue<P> pq;

    P init = {A[0] + B[0] + C[0], 0, 0, 0};

    pq.push(init);

    map<vector<int>, int> cnt;

    cnt[{0, 0, 0}]++;

    vector<ll> ans;



    while (!pq.empty() && ans.size() < K) {

        P q = pq.top();

        pq.pop();

        // printf("taste=%d a=%d b=%d c=%d\n", q.taste, q.a, q.b, q.c);

        ans.push_back(q.taste);

        P newq1 = {A[q.a + 1] + B[q.b] + C[q.c], q.a + 1, q.b, q.c};

        P newq2 = {A[q.a] + B[q.b + 1] + C[q.c], q.a, q.b + 1, q.c};

        P newq3 = {A[q.a] + B[q.b] + C[q.c + 1], q.a, q.b, q.c + 1};



        if (q.a+1<X && cnt[{q.a + 1, q.b, q.c}] == 0) {

            // cout << "1だよ" << endl;

            pq.push(newq1);

            cnt[{q.a + 1, q.b, q.c}]++;

        }

        if (q.b+1<Y && cnt[{q.a, q.b + 1, q.c}] == 0) {

            // cout << "2だよ" << endl;

            pq.push(newq2);

            cnt[{q.a, q.b + 1, q.c}]++;

        }

        if (q.c+1<Z && cnt[{q.a, q.b, q.c + 1}] == 0) {

            // cout << "3だよ" << endl;

            pq.push(newq3);

            cnt[{q.a, q.b, q.c + 1}]++;

        }

    }

    rep(i, K) cout << ans[i] << endl;

}
