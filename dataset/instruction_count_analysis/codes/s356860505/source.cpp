#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>



using namespace std;

#define MOD 1000000007

#define ll long long

#define rint register int

#define gc() getchar()

inline ll read(ll ans = 0, rint sgn = ' ', rint ch = gc())

{

	for(; ch < '0' || ch > '9'; sgn = ch, ch = gc());

	for(; ch >='0' && ch <='9';(ans*=10)+=ch-'0', ch = gc());

	return sgn-'-'?ans:-ans;

}

int H, W, a, b, c, row, col; char s[1005][1005]; ll K;

inline int fastpow(int s, ll n){int a = 1; for(; n; n&1 ? a = 1ll*a*s%MOD : 0, s = 1ll*s*s%MOD, n >>= 1); return a;}

struct Matrix{int c[2][2]; Matrix(){} Matrix(int c00, int c01, int c10, int c11){c[0][0]=c00,c[0][1]=c01,c[1][0]=c10,c[1][1]=c11;}}U,S,A,I(1,0,0,1),F;

inline Matrix operator * (Matrix &A, Matrix &B)

{

	return Matrix((1ll*A.c[0][0]*B.c[0][0]+1ll*A.c[0][1]*B.c[1][0])%MOD,

				  (1ll*A.c[0][0]*B.c[0][1]+1ll*A.c[0][1]*B.c[1][1])%MOD,

				  (1ll*A.c[1][0]*B.c[0][0]+1ll*A.c[1][1]*B.c[1][0])%MOD,

				  (1ll*A.c[1][0]*B.c[0][1]+1ll*A.c[1][1]*B.c[1][1])%MOD);

}

inline Matrix operator ^ (Matrix S, ll n){for(A = I; n; S = S*S, n >>= 1) if(n&1) A = A*S; return A;}

int main()

{

	H = read(), W = read(), K = read(); if(!K){puts("1"); return 0;}

	for(rint i = 1; i <= H; scanf("%s",s[i]+1), c += s[i][1]=='#'&&s[i][W]=='#', i++); row = c;

	for(rint j = 1; j <= W; c += s[1][j]=='#'&&s[H][j]=='#', j++); col = c-row;

	for(rint i = 1, j; i <= H; i++)

		for(j = 1; j <= W; s[i][j]=='#' ? ++a, b += row?j<W&&s[i][j+1]=='#':i<H&&s[i+1][j]=='#' : 0, j++);

	if(row&&col){puts("1"); return 0;} if(!row&&!col){printf("%d\n",fastpow(a,~-K)); return 0;}

	U = Matrix(a,MOD-b,0,c), F = Matrix(1,0,1,0), S = U^~-K, F = S*F, printf("%d\n",F.c[0][0]); return 0;

}