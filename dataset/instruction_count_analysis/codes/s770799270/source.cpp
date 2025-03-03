#include "stdc++.h"

using namespace std;

#define N 1050

typedef long long ll;

int ir,ic,grid[N][N];

ll memo[N][N];

const ll m = (ll)1e9 + 7;



bool inside(int r , int c) {

    return r >= 1 && r <= ir && c >= 1 && c <= ic;

}



ll add(ll a , ll b) {

    return ((a % m) + (b % m)) % m;

}



ll dp(int r , int c) {

    if (r == ir && c == ic) return 1;

    if (grid[r][c] == -1) return 0;

    if (!inside(r , c)) return 0;

    ll &sol = memo[r][c];

    if (sol != -1) return sol;

    return sol = add(dp(r + 1 , c) , dp(r , c + 1));

}



int main() {

    scanf("%d%d" , &ir , &ic);

    for (int r = 1 ; r <= ir ; r++) {

        char inp[N]; scanf("%s" , inp);

        for (int c = 0 ; c < strlen(inp) ; c++) {

            int keep = 0;

            if (inp[c] == '#') keep = -1;

            grid[r][c + 1] = keep;

        }

    }

    memset (memo , -1 , sizeof memo);

    printf("%lld\n" , dp(1 , 1));

}
