#include <iostream> 

#include <cstdio> 

#include <cstdlib> 

#include <cstring> 

#include <cmath> 

#include <algorithm>  

using namespace std; 

const int MAX_N = 3e3 + 5; 

const int Mod = 1e9 + 7; 

int fpow(int x, int y) {

	int res = 1; 

	while (y) { 

		if (y & 1) res = 1ll * res * x % Mod; 

		x = 1ll * x * x % Mod; 

		y >>= 1; 

	} 

	return res; 

} 

const int inv = fpow(2, Mod - 2); 

int N, Q, a[MAX_N]; 

int f[MAX_N][MAX_N]; 

int main () { 

	scanf("%d %d", &N, &Q); 

	for (int i = 1; i <= N; i++) scanf("%d", a + i); 

	for (int i = 1; i <= N; i++) 

		for (int j = 1; j <= N; j++) f[i][j] = a[i] < a[j]; 

	for (int i = 1; i <= Q; i++) { 

		int x, y; scanf("%d %d", &x, &y); 

		f[x][y] = f[y][x] = 1ll * (f[x][y] + f[y][x]) * inv % Mod; 

		for (int j = 1; j <= N; j++) { 

			if (j == x || j == y) continue; 

			f[x][j] = f[y][j] = 1ll * (f[x][j] + f[y][j]) * inv % Mod; 

			f[j][x] = f[j][y] = 1ll * (f[j][x] + f[j][y]) * inv % Mod; 

		} 

	} 

	int ans = 0; 

	for (int i = 1; i <= N; i++) 

		for (int j = 1; j < i; j++) 

			ans = (ans + f[i][j]) % Mod; 

	printf("%lld\n", 1ll * ans * fpow(2, Q) % Mod); 

    return 0;  

} 