#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;
const int INF = 1e9;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    vector<int> p(m);
    for (int &val : p) scanf("%d", &val);

    vector<int> dp(20001, INF);
    dp[0] = 0;
    int sum = 0;

    vector<int> c, e; // Declare without size but will reserve space
    c.reserve(n);
    e.reserve(n);

    for (int i = 0; i < n; i++) {
        c.push_back(0);
        e.push_back(0);
        scanf("%d %d", &c[i], &e[i]);
        for (int j = sum; j >= 0; j--) {
            if (j + c[i] <= 20000) {
                dp[j + c[i]] = min(dp[j + c[i]], dp[j] + e[i]);
            }
        }
        sum += c[i];
        sum = min(sum, 20000);
    }
    for (int i = sum; i >= 0; i--) {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    sort(p.rbegin(), p.rend());
    sum = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        sum += p[i];
        ans = max(ans, sum - dp[min(i + 1, 20000)]);
    }
    printf("%d\n", ans);
}
