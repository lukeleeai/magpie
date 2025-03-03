#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

ll x, y, A, B, C, a[N], b[N], c[N];

ll res[N];

bool cmp(ll x, ll y){

        return x > y;

};

int main() {

    scanf("%lld%lld%lld%lld%lld", &x, &y, &A, &B, &C);

    for (int i = 1; i <= A; i++)

        scanf("%lld", &a[i]);

    for (int i = 1; i <= B; i++)

        scanf("%lld", &b[i]);

    for (int i = 1; i <= C; i++)

        scanf("%lld", &c[i]);

    sort(a + 1, a + A + 1, cmp);

    sort(b + 1, b + B + 1, cmp);

    sort(c + 1, c + C + 1, cmp);

    int k = 0;

    for (int i = 1; i <= x; i++)

        res[++k] = a[i];

    for (int i = 1; i <= y; i++)

        res[++k] = b[i];

    sort(res + 1, res + k + 1, cmp);



    int index = 1;

    for (int i = k; i >= 1; i--) {

        if(res[i] < c[index]) {

            res[i] = c[index];

            index++;

        }

        if(index > C)

            break;

    }

    ll sum = 0;

    for (int i = 1; i <= k; i++)

        sum += res[i];

    printf("%lld\n", sum);

        return 0;

}


