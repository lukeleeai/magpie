#include <cstdio>

using namespace std;



int gcd(int a, int b) {

    return b ? gcd(b, a%b) : a;

}



int main() {

    int N, K; scanf("%d%d", &N, &K);

    int g = -1, ma = 0;

    for(int i=0; i<N; i++) {

        int p; scanf("%d", &p);

        if(g < 0) g = p;

        else g = gcd(g, p);

        if(ma < p) ma = p;

    }



    printf("%s\n", (K % g || K > ma ? "IMPOSSIBLE" : "POSSIBLE"));

    return 0;

}