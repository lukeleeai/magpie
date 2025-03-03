#include<cstdio>

#include<cstring>

#define retrun return

#define cpnst const

typedef long long ll;

cpnst ll mod=998244353,inv2=(mod+1)>>1;

ll qpow(ll x,ll k)

{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}

ll N,A[1111111];

void FWT(ll*x,int op)

{

	for(register int i=1,ii,iii;i<N;i<<=1)

		for(ii=0;ii<N;ii+=(i<<1))

			for(iii=0;iii<i;iii++)

			{

				int px=ii+iii,py=px+i;

				ll vx=x[px]+x[py],vy=x[px]-x[py]+mod;

				if(op<0)vx*=inv2,vy*=inv2;

				x[px]=vx%mod,x[py]=vy%mod;

			}

}

ll C[1111111];

int main()

{

	scanf("%lld",&N),N=1<<N;

	register int i;

	ll S=0;

	for(i=0;i<N;i++)

		scanf("%lld",A+i),S+=A[i];

	S=qpow(S,mod-2);

	for(i=0;i<N;i++)(A[i]*=S)%=mod; 

	C[0]=N-1,A[0]=(mod-1+A[0])%mod;

	for(i=1;i<N;i++)C[i]=mod-1;

	FWT(C,1),FWT(A,1);

	for(i=0;i<N;i++)C[i]=qpow(A[i],mod-2)*C[i]%mod;

	FWT(C,-1);

	for(i=0;i<N;i++)printf("%lld\n",(C[i]-C[0]+mod)%mod);

}

/*

Just go for it.

*/