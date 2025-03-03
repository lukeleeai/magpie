#include<cstdio>

#include<algorithm>

using namespace std;

#define MOD 1000000007

#define MAXN 200005

#define LL long long

LL inv[MAXN],s[MAXN];

int N;

int H,W,A,B;

LL Pow(LL a,int b) 

{

    LL ans=1;

    while(b) 

	{

        if(b&1) ans=ans*a%MOD;

        a=a*a%MOD;

        b>>=1;

    }

    return ans;

}

void Pre() 

{

    s[0]=1;

    for(int i=1; i<=N; i++)

        s[i]=s[i-1]*i%MOD;

    inv[0]=1;

    inv[N]=Pow(s[N],MOD-2);

    for(int i=N-1; i>0; i--)

        inv[i]=inv[i+1]*(i+1)%MOD;

}

LL C(int a,int b) 

{

    if(a<0||b<0) return 1;

    return s[a]*inv[b]%MOD*inv[a-b]%MOD;

}

int main() 

{

    scanf("%d %d %d %d",&H,&W,&A,&B);

	N=H+W-2;

	Pre();

	LL ans=C(H+W-2,H-1);

	for(int i=1;i<=B;i++)

	{

		ans-=C(H-A+i-2,H-A-1)*C(A-1+W-i,A-1)%MOD;

		ans=(ans%MOD+MOD)%MOD;

	}

    printf("%lld\n",ans);

}
