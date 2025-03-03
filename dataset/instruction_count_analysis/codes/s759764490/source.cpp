#include <cstdio>

using namespace std;

int main() {

    int N, M; scanf("%d%d", &N, &M);

    int submit_time = 100*N + 1800*M;

    printf("%d\n", submit_time * (1 << M));

    return 0;

}