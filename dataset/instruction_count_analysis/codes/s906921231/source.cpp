#include <cstdio>

#include <algorithm>



const int MAXN = 2e5 + 5;



int n, k;

long long int ans;

int arr[MAXN];



int main() {

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {

        scanf("%d", &arr[i]);

    }

    k = n - k;

    std::sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= k; ++i) {

        ans += arr[i];

    }

    printf("%lld", ans);

    return 0;

}