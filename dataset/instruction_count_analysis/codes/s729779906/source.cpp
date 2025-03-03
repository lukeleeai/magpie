#include <cstdio>

using namespace std;

long long N, K, i, t, a, b;

long long arr[100001] = {0};

int main() {

    scanf("%ld %ld", &N, &K);

    for(i = 0; i < N; i++) {

        scanf("%ld %ld", &a, &b);

        arr[a] += b;

    }

    for(i = 1, t = 0; i <= 100001; i++) {

        t += arr[i];

        if(t >= K) {printf("%ld", i); break;}

    }

}