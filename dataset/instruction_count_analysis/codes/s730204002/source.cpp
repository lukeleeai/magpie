#include<cstdio>

#include<algorithm>

using namespace std;

#define MOD 1000000007

#define MAXN 200005

#define LL long long

LL inv[MAXN],s[MAXN];

int N;

int n,m,x,y;

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



    scanf("%d%d",&n,&m);

    scanf("%d%d",&x,&y);

    N=n+m-2;

    Pre();

    LL ans=0;

    for(int i=y+1;i<=m;i++)

    {

        ans+=C(n-x+i-2,i-1)*C(x+m-i-1,x-1)%MOD;

        ans%=MOD;

    }

    printf("%lld\n",ans);

}