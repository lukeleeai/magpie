#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.reserve(100000); // Reserve enough space to avoid repeated allocations
    int a, b, n, o = 0;
    while (scanf("%d", &b) != EOF) {
        v.clear();
        o = 0;
        if (b == 0) break;
        else {
            for (int i = 0; i < b; i++) {
                scanf("%d", &a);
                v.push_back(a);
            }
            int max_sum = v[0], current_sum = v[0];
            for (int i = 1; i < b; i++) {
                current_sum = max(v[i], current_sum + v[i]);
                max_sum = max(max_sum, current_sum);
            }
            printf("%d\n", max_sum);
        }
    }
    return 0;
}
