#include <stdio.h>

#include <tuple>

#include <queue>



int main(void){

    int L; scanf("%d", &L);

    int n = 0; while((1 << (n+1)) <= L) n++;

    std::queue<std::tuple<int, int, int>> Q;

    for(int x = 0; x + 1 <= n; ++x) Q.emplace(x, x+1, 0), Q.emplace(x, x+1, 1 << x);

    int N = (1 << n) - 1; int U = L - N - 1;

    int l = L;

    for(int d = n; d >= 0; --d) if((U >> d) & 1){ // 101

        Q.emplace(d, n, l - (1 << d) ); l -= (1 << d);

    }



    printf("%d %lu\n", n+1, Q.size());

    while(not Q.empty()){

        int x, y, c; std::tie(x, y, c) = Q.front(); Q.pop();

        printf("%d %d %d\n", x + 1, y + 1, c);

    }

    return 0;

}