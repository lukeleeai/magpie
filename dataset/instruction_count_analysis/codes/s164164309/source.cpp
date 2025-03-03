#include <cstdio>

#include <algorithm>

using std::min;

using std::max;

using std::sort;

#define MAXN 103



int main(void)

{

    int N, K, R;

    int a[MAXN],plate[MAXN];

    scanf("%d%d",&N,&K);

    int i,j,res=0;

    

    for(i=0;i<N;i++)

    {

        scanf("%d",a+i);

    }



    R=min(N,K);

    for(int A=0;A<=R;A++)

    {

        for(int B=0;B<=R-A;B++)

        {

            for(i=0;i<A;i++)

            {

                plate[i]=a[i];

            }

            for(j=0;j<B;j++)

            {

                plate[i+j]=a[N-1-j];

            }

            sort(plate,plate+A+B);

            i=0;

            while(i<K-(A+B) && plate[i]<0)

            {

                i++;

            }

            int s = 0;

            for(;i<A+B;i++)

            {

                s+=plate[i];

            }

            res = max(s,res);

        }

    }

    printf("%d\n",res);

    return 0;

}