#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct P {
    int p, d;
} P;

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        P m;
        m.d = -1; // Initialize to a low value
        for (int i = 0; i < n; i++) {
            int p, d1, d2;
            scanf("%d%d%d", &p, &d1, &d2);
            int total_d = d1 + d2;
            if (total_d > m.d) {
                m = {p, total_d};
            }
        }
        printf("%d %d\n", m.p, m.d);
    }

    return 0;
}
