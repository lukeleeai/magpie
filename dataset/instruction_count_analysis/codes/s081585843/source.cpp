///

/**

 * @Samaritan

 */

#include"stdc++.h"

using namespace std;

typedef long long LL;



#define pb emplace_back

#define fi first

#define se second

#define PII pair<int, int>

#define PLL pair<LL, LL>



LL quick_pow (LL a, LL b, LL mod) {

    LL ans = 1, base = a;

    while (b) {

        if (b & 1) (ans *= base) %= mod;

        b >>= 1;

        (base *= base) %= mod;

    }

    return ans;

}



const int mod = 1e9 + 7;

const int N = 2e2 + 5;



struct node {

    int pos, v;

    bool operator < (const node& k) const {

        return v > k.v;

    }

};



char pic[N][N];



int main() {

    int a, b;

    scanf("%d %d", &a, &b);

    memset(pic, 0, sizeof pic);

    int n = 100;

    int cnt = b - 1;

    int max_col = 2;

    for (int i = 1; i <= n; ++i) {

        if (!cnt) break;

        for (int j = 1; j <= n; ++j) {

            if (i & 1 && j & 1) {

                pic[i][j] = '#';

                cnt--;

                if (!cnt) {

                        max_col = i + 1;

                    break;

                }

            }

        }

        if (!cnt) break;

    }

    for (int i = 1; i <= max_col; ++i) {

        for (int j = 1; j <= n; ++j) {

            if (!pic[i][j]) pic[i][j] = '.';

        }

    }

    cnt = a - 1;

    for (int i = max_col + 2; i <= n; ++i) {

        if (!cnt) break;

        for (int j = 1; j <= n; ++j) {

            if (i & 1 && j & 1) {

                pic[i][j] = '.';

                cnt--;

                if (!cnt) {

                    break;

                }

            }

        }

        if (!cnt) break;

    }

    for (int i = max_col + 1; i <= n; ++i) {

        for (int j = 1; j <= n; ++j) {

            if (!pic[i][j]) pic[i][j] = '#';

        }

    }

    printf("100 100\n");

    for (int i = 1; i <= n; ++i) printf("%s\n", pic[i] + 1);

    return 0;

}
