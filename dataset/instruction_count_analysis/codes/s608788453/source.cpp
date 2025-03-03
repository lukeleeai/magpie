#include <cstdio>



typedef long long LL;



const int MAXN=100005;



void fix_down(int *h,int i,int n)

{

    int j=i,k,t=h[i];

    while ((j<<1)+1<n)

    {

        k=(j<<1)+1;

        if (k+1<n&&h[k+1]>h[k]) k=k+1;

        if (t>=h[k]) break;

        h[j]=h[k];

        j=k;

    }

    h[j]=t;

}



int main()

{

    int N,M,t;

    LL ans=0LL;

    static int h[MAXN];



    scanf("%d%d",&N,&M);

    for (int i=0;i<N;++i)

        scanf("%d",&h[i]);



    for (int i=N-1;i>=0;--i)

        fix_down(h,i,N);

    for (int i=0;i<M;++i)

    {

        if (h[0]==0) break;

        h[0]=h[0]>>1;

        fix_down(h,0,N);

    }

    for (int i=0;i<N;++i)

        ans=ans+h[i];

    printf("%lld",ans);



    return 0;

}


