#include <cstdio>

#include <cstring>

#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;

int vis[maxn], prime[maxn], notPrime[maxn], num[maxn];

int total, n, maxx = 0, ans = 0, tmp;

void getPrime(int sum) {

    for (int i = 2; i <= sum; i++) {

        if (!notPrime[i]) {

            prime[++total] = i;

        }

        for (int j = 1; prime[j] * i <= sum; j++) {

            notPrime[i * prime[j]] = prime[j];

            if (i % prime[j] == 0)

                break;

        }

    }

}



void getInit() {

    memset(vis, 0, sizeof(vis));

    memset(notPrime, 0, sizeof(notPrime));

    memset(vis, 0, sizeof(vis));

}



int main() {

    getInit();

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d", &num[i]);

        maxx = max(maxx, num[i]);

    }

    getPrime(maxx);

    for (int i = 1; i <= n; i++) {

        while (notPrime[num[i]]) {

            tmp = notPrime[num[i]];

            vis[tmp]++;

            ans = max(ans, vis[tmp]);

            while (num[i] % tmp == 0)

                num[i] /= tmp;

        }

        if (num[i] != 1) {

            vis[num[i]]++;

            ans = max(ans, vis[num[i]]);

        }

    }

    if (ans <= 1)

        printf("pairwise coprime\n");

    else if (ans < n)

        printf("setwise coprime\n");

    else

        printf("not coprime\n");

    getchar();

    getchar();

    return 0;

}
