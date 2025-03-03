#include <cstdio>

using namespace std;



long long int N, A[100010];

int main() {

    scanf("%lld", &N);

    long long int sum = 0, div = N*(N+1)/2;

    for(int i=0; i<N; i++) {

        scanf("%lld", &A[i]);

        sum += A[i];

    }



    bool ok = (sum % div == 0);

    long long int sum_op = sum / div;

    for(int i=0; i<N; i++) {

        long long int val = A[i] - A[(i+1)%N] + sum_op;

        ok &= (val >= 0 && val % N == 0);

    }

    printf("%s\n", ok ? "YES" : "NO");

    return 0;

}