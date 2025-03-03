#include "stdc++.h"



using namespace std;



const int N = 200005;

int cnt[N], aux[N];



int main() {

    int n, k;

    cin >> n >> k;

    map <int, int> mp;

    for (int i = 0; i < n; i++) {

        int x;

        cin >> x;

        cnt[x]++;

    }

    int sz = 0;

    for (int i = 1; i < N; i++) {

        if (cnt[i]) {

            aux[sz++] = cnt[i];

        }

    }

    sort(aux, aux + sz);

    int res = 0;

    for (int i = 0; i < sz - k; i++) {

        res += aux[i];

    }

    cout << res;

    return 0;

}