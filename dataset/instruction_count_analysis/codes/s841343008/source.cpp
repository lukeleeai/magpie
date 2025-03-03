#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>



using namespace std;

#define MOD 1000000007

#define rint register int

#define gc() getchar()

inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}

inline int fxp(int s, int n=MOD-2){int a=1; for(; n; n&1 ? a = 1ll*a*s%MOD : 0, s = 1ll*s*s%MOD, n >>= 1); return a;}

int A[20], fac[65537], efac[65537], f[20][65537], N, M, E, Ans; bool c[65537]; inline void Add(int &x, int v){(x+=v)<MOD?:x-=MOD;}

inline int C(int n, int k){return n<0||k<0||n<k?0:1ll*fac[n]*efac[k]%MOD*efac[n-k]%MOD;}

int main()

{

	N = read(), M = read(), E = 1<<N, f[0][0] = 1; for(rint i = 0; i < M; A[i++] = read()); reverse(A,A+M);

	for(rint i = fac[0] = 1; i <= E; fac[i] = 1ll*i*fac[i-1]%MOD, i++); efac[E] = fxp(fac[E]); for(rint i = E; i; efac[i-1] = 1ll*i*efac[i]%MOD, i--);

	for(rint i = 0, j, S, r; i < M; i++) for(S = 0; S < E; S++) if(f[i][S])

		for(Add(f[i+1][S],f[i][S]), r = E-A[i]-S, j = 1; j < E && j-1 <= r; !(S&j) ? Add(f[i+1][S|j],1ll*f[i][S]*C(r,j-1)%MOD*fac[j]%MOD),0 : 0, j <<= 1);

	for(rint S = 0; S < E; S?c[S]=c[S-(S&-S)]^1:0, Ans = (Ans+(c[S]?MOD-1ll:1ll)*f[M][S]%MOD*fac[E-S-1])%MOD, S++); printf("%d\n",1ll*Ans*E%MOD); return 0;

}