#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int s[1001][1024] = {0};

int calc(int y, int x, int n) {
    n--;
    return s[y + n][x + n] - s[y + n][x - 1] - s[y - 1][x + n] + s[y - 1][x - 1];
}

int main() {
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char c;
                cin >> c;
                s[i][j] = (c == '*') + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int lb = 0, ub = n - max(i, j) + 2;
                while (ub - lb > 1) {
                    int m = (lb + ub) / 2;
                    if (calc(i, j, m)) ub = m;
                    else lb = m;
                }
                ans = max(ans, lb);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
