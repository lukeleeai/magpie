#include<cstdio>

#define MOD 1000000007

#define MAXS 200000

typedef long long LL;



int h,w,a,b,ans=0;

LL jc[MAXS+5],inv[MAXS+5];



LL Powm(LL x,LL M) {

	LL cf=x,ret=1;

	while(M) {

		if(M&1)

			ret=ret*cf%MOD;

		cf=cf*cf%MOD;

		M>>=1;

	}

	return ret;

}

void Prepare() {

	jc[0]=1;

	for(LL i=1;i<=MAXS;i++)

		jc[i]=jc[i-1]*i%MOD;

	inv[0]=1;

	inv[MAXS]=Powm(jc[MAXS],MOD-2);

	for(LL i=MAXS-1;i>0;i--)

		inv[i]=(i+1)*inv[i+1]%MOD;

}

LL C(LL a,LL b) {

	if(a<0||b<0) return 1;

	return jc[a]*inv[b]%MOD*inv[a-b]%MOD;

}

int main() {

	Prepare();

	scanf("%d %d %d %d",&h,&w,&a,&b);

	for(LL i=b+1;i<=w;i++)

		ans=(ans+C(h-a+i-2,i-1)*C(a+w-i-1,w-i)%MOD)%MOD;

	printf("%d\n",ans);

	return 0;

}