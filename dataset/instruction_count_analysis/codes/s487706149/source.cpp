#include <cstdio>

#include <iostream>



#define MAXN 2050

#define ll long long

#define Mod 1000000007



using namespace std ; int i, j ; int N, M ; 

ll Fac[MAXN * MAXN], Inv[MAXN * MAXN]/*Co[MAXN][MAXN], */, dp[MAXN][MAXN] ;



ll expow(ll a, int b){

	ll res = 1 ; 

	while (b){

		if (b & 1) res = res * a % Mod ;

		a = a * a % Mod, b = b >> 1 ;

	}

	return res ;

} 

ll Co(int n, int m){

	if (n < m) return 0 ; 

	return Fac[n] * Inv[m] % Mod * Inv[n - m] % Mod ; 

}

int main(){

	cin >> N >> M ; /*Co[0][0] = 1 ; */	 Inv[0] = 1 ;

	for (i = 0 ; i <= N ; ++ i) dp[i][0] = 1 ; Fac[0] = 1 ;

	for (i = 1 ; i <= N * M ; ++ i) Fac[i] = Fac[i - 1] * i % Mod ;

	for (i = 1 ; i <= N * M ; ++ i) Inv[i] = expow(Fac[i], Mod - 2) ;  

	/*for (i = 1 ; i <= N ; ++ i){

        Co[i][0] = 1 ;

        for (j = 1 ; j <= N ; ++ j) Co[i][j] = (Co[i - 1][j - 1] + Co[i - 1][j]) % Mod ;

    }*/

	for (i = 1 ; i <= N ; ++ i)

		for (j = 1 ; j <= i ; ++ j)

			dp[i][j] = (dp[i - 1][j]  + dp[i][j - 1] * (N - j + 1) % Mod * Co(N * M - i - (j - 1) * (M - 1) - 1, M - 2) % Mod) % Mod ;

	cout << (M <= 1 ? 1 : dp[N][N]) << endl ; return 0 ; 

}