#include <cstdio>

using namespace std;



long long int A[100010], B[100010];

int main() {

    int N; scanf("%d", &N);

    for(int i=0; i<N; i++) {

        scanf("%lld%lld", &A[i], &B[i]);

    }



    long long int ofs = 0;

    for(int i=N-1; i>=0; i--) {

        A[i] += ofs;

        if(A[i] == 0) continue;

        if(A[i] <= B[i]) ofs += B[i] - A[i];

        else {

            long long int mo = A[i] % B[i];

            ofs += (B[i] - mo) % B[i];

        }

    }

    printf("%lld\n", ofs);

    return 0;

}