#include <cstdio>

using namespace std;



int main() {

    int N, cnt = 0; scanf("%d", &N);

    for(int i=0; i<N; i++) {

        int p; scanf("%d", &p);

        cnt += (p % 2);

    }

    printf("%s\n", (cnt % 2) ? "NO" : "YES");

    return 0;

}