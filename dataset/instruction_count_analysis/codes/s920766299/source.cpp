#pragma GCC optimize(3)

#pragma GCC optimize("Ofast")

#pragma GCC optimize("inline")

#pragma GCC optimize("-fgcse")

#pragma GCC optimize("-fgcse-lm")

#pragma GCC optimize("-fipa-sra")

#pragma GCC optimize("-ftree-pre")

#pragma GCC optimize("-ftree-vrp")

#pragma GCC optimize("-fpeephole2")

#pragma GCC optimize("-ffast-math")

#pragma GCC optimize("-fsched-spec")

#pragma GCC optimize("unroll-loops")

#pragma GCC optimize("-falign-jumps")

#pragma GCC optimize("-falign-loops")

#pragma GCC optimize("-falign-labels")

#pragma GCC optimize("-fdevirtualize")

#pragma GCC optimize("-fcaller-saves")

#pragma GCC optimize("-fcrossjumping")

#pragma GCC optimize("-fthread-jumps")

#pragma GCC optimize("-funroll-loops")

#pragma GCC optimize("-fwhole-program")

#pragma GCC optimize("-freorder-blocks")

#pragma GCC optimize("-fschedule-insns")

#pragma GCC optimize("inline-functions")

#pragma GCC optimize("-ftree-tail-merge")

#pragma GCC optimize("-fschedule-insns2")

#pragma GCC optimize("-fstrict-aliasing")

#pragma GCC optimize("-fstrict-overflow")

#pragma GCC optimize("-falign-functions")

#pragma GCC optimize("-fcse-skip-blocks")

#pragma GCC optimize("-fcse-follow-jumps")

#pragma GCC optimize("-fsched-interblock")

#pragma GCC optimize("-fpartial-inlining")

#pragma GCC optimize("no-stack-protector")

#pragma GCC optimize("-freorder-functions")

#pragma GCC optimize("-findirect-inlining")

#pragma GCC optimize("-fhoist-adjacent-loads")

#pragma GCC optimize("-frerun-cse-after-loop")

#pragma GCC optimize("inline-small-functions")

#pragma GCC optimize("-finline-small-functions")

#pragma GCC optimize("-ftree-switch-conversion")

#pragma GCC optimize("-foptimize-sibling-calls")

#pragma GCC optimize("-fexpensive-optimizations")

#pragma GCC optimize("-funsafe-loop-optimizations")

#pragma GCC optimize("inline-functions-called-once")

#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <cstdio>

#define ll long long

#define abs(a) ((a)>0?(a):(-a))

#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;

ll n,a[210000],tot,ans=922372036854775805;

inline int read()

{

    int x=0,f=1;char ch=getchar();

    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;

    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';

    return x*f;

}

int main()

{

	n=read();

	for(register ll i=1; i<=n; ++i) a[i]=read(),tot+=a[i];	 

	for(register ll i=1; i<=n-1; ++i)

		tot-=2*a[i],ans=min(ans,(ll)abs(tot));

	printf("%lld\n",ans);	

	return 0;

}