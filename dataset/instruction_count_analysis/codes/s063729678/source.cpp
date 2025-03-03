#include<cstdio>

#include<cstring>

#include<algorithm>

#include<deque>

using namespace std;

typedef long long ll;

const int N=1e5+5;

const ll mod=1e9+7;

int n,m;

int x[N];

struct mat{

    ll a[3][3];

    mat(){memset(a,0,sizeof a);}

}A,C,e;

void debug(mat x){

    for(int i=0;i<3;i++,puts(""))

        for(int j=0;j<3;j++)

            printf("%d ",x.a[i][j]);

    puts("");

}

mat operator *(mat x,mat y){

    mat z;

    for(int i=0;i<3;i++)

        for(int j=0;j<3;j++)

            for(int k=0;k<3;k++){

                z.a[i][j]+=x.a[i][k]*y.a[k][j];

                z.a[i][j]%=mod;

            }

    return z;

}

mat operator ^(mat x,int y){

    mat res=e;

    while(y){

        if(y&1)

            res=res*x;

        //debug(x);

        x=x*x;

        //debug(res);

        //debug(x);

        y>>=1;

    }

    return res;

}

ll f[3],g[3];

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)

        scanf("%d",&x[i]);

    A.a[0][0]=1,A.a[0][1]=2,A.a[0][2]=1;

    A.a[1][0]=0,A.a[1][1]=1,A.a[1][2]=1;

    A.a[2][0]=0,A.a[2][1]=0,A.a[2][2]=1;

    C.a[0][0]=2,C.a[0][1]=2,C.a[0][2]=1;

    C.a[1][0]=1,C.a[1][1]=1,C.a[1][2]=1;

    C.a[2][0]=1,C.a[2][1]=0,C.a[2][2]=1;

    e.a[0][0]=1,e.a[0][1]=0,e.a[0][2]=0;

    e.a[1][0]=0,e.a[1][1]=1,e.a[1][2]=0;

    e.a[2][0]=0,e.a[2][1]=0,e.a[2][2]=1;

    f[0]=1;

    x[++m]=n;

    for(int t=1,pos=0;t<=m;t++){

        int k=x[t]-pos-1;

        mat z=C^k;

        z=z*A;

        for(int i=0;i<3;i++){

            g[i]=0;

            for(int j=0;j<3;j++)

                g[i]=(g[i]+f[j]*z.a[j][i]%mod)%mod;

        }

        for(int i=0;i<3;i++)

            f[i]=g[i];

        pos=x[t];

    }

    printf("%lld\n",f[2]);

}
