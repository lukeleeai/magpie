#include <stdio.h>

#include <vector>

#include <algorithm>

#include <map>



using namespace std;



struct union_find {

    int uf[100000];

    long long sum[100000];

    

    int id_[200000];

    int uf_[200000];

    long long sum_[200000];

    int k;



    int find(int x) {

        while (uf[x] >= 0) x = uf[x];

        return x;

    }



    void store(int x) {

        id_[k] = x;

        uf_[k] = uf[x];

        sum_[k] = sum[x];

        k++;

    }



    void restore() {

        k--;

        int x = id_[k];

        uf[x] = uf_[k];

        sum[x] = sum_[k];

    }



    void skip() {

        k--;

    }



    void unite(int x, int y) {

        x = find(x);

        y = find(y);

        if (-uf[x] < -uf[y]) swap(x, y);

        store(x);

        store(y);

        uf[x] += uf[y];

        sum[x] += sum[y];

        uf[y] = x;

    }



    bool same(int x, int y) {

        return find(x) == find(y);

    }

} uf;





int N, M;

int X[100000];

int A[100000], B[100000], Y[100000], P[100000];

int used[100000];



int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {

        scanf("%d", &X[i]);

        uf.uf[i] = -1;

        uf.sum[i] = X[i];

    }

    for (int i = 0; i < M; i++) {

        scanf("%d %d %d", &A[i], &B[i], &Y[i]);

        A[i]--;

        B[i]--;

        P[i] = i;

    }

    sort(P, P + M, [&](int i, int j) { return Y[i] < Y[j]; });

    for (int i = 0; i < M; i++) {

        int j = P[i];

        if (!uf.same(A[j], B[j])) {

            uf.unite(A[j], B[j]);

            used[j] = 1;

        }

    }

    int ans = 0;

    for (int i = M - 1; i >= 0; i--) {

        int j = P[i];

        long long sum = uf.sum[uf.find(A[j])];

        if (used[j]) {

            if (sum < Y[j]) {

                ans++;

                uf.restore();

                uf.restore();

            } else {

                uf.skip();

                uf.skip();

            }

        } else {

            if (sum < Y[j]) {

                ans++;

            }

        }

    }

    printf("%d\n", ans);

    return 0;

}




