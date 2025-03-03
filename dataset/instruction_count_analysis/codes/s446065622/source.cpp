#include <cstdio>

#include <algorithm>

#include <cstdint>



using namespace std;



int main() {

    int64_t N, X;

    scanf("%lld %lld", &N, &X);



    int64_t res=N;

    N -= X;

    if (N < X) swap(N, X);



    while (X) {

        res += 2*(N/X)*X;



        if (N % X == 0) {

            res -= X;

            break;

        }



        swap(N%=X, X);

    }



    printf("%lld\n", res);

    return 0;

}
