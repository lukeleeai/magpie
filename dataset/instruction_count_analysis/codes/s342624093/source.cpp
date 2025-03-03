#include <cstdio>

#include <algorithm>

using std::min;



#define MAXN 100003



int abs(int z)

{

    if (z<0)

        return -z;

    else

        return z;

}



int main(void)

{

    int N,i,j;

    int h[MAXN], p[MAXN];

    scanf("%d",&N);

    for (i=0;i<N;i++)

    {

        scanf("%d",h+i);

    }

    p[N-1]=0;

    p[N-2]=abs(h[N-2]-h[N-1]);

    for(i=N-3;i>=0;i--)

    {

        p[i]=min(p[i+1]+abs(h[i]-h[i+1]),p[i+2]+abs(h[i]-h[i+2]));

    }

    printf("%d\n",p[0]);



    return 0;

}