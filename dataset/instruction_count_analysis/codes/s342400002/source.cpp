#include <cstdio>



using namespace std;



bool is_valid(const int D[10], int N) {

    while (N) {

        if (D[N%10]) return false;



        N /= 10;

    }

    return true;

}



int main() {

    int N, K;

    scanf("%d %d", &N, &K);



    int D[10]={};

    for (int i=0; i<K; ++i) {

        int d;

        scanf("%d", &d);

        ++D[d];

    }



    while (!is_valid(D, N))

        ++N;



    printf("%d\n", N);

    return 0;

}
