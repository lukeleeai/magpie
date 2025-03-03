#include <cstdio>

#include <algorithm>

#include <cstdlib>



using std::max;  using std::abs;

using std::min;



const int MAXN=105;



int N,cx,cy,ch=0,c_point,min_abs;                     //c_point: calculable point

int x[MAXN],y[MAXN],h[MAXN];



int main()

{

    scanf("%d",&N);

    for (int i=1;i<=N;++i)

        scanf("%d%d%d",&x[i],&y[i],&h[i]);

    for (cx=0;cx<=100&&ch<=0;++cx)

    {

        for (cy=0;cy<=100&&ch<=0;++cy)

        {

            min_abs=MAXN<<1;

            for (c_point=1;c_point<=N&&h[c_point]==0;++c_point);

            if (c_point==N+1)

            {

                for (int i=1;i<=N;++i)

                    min_abs=min(min_abs,abs(x[i]-cx)+abs(y[i]-cy));

                if (min_abs==1) ch=1;

            }

            else

            {

                ch=h[c_point]+abs(x[c_point]-cx)+abs(y[c_point]-cy);

                int i;

                for (i=1;i<=N&&h[i]==max(ch-abs(x[i]-cx)-abs(y[i]-cy),0);++i);

                if (i<=N) ch=0;

            }

        }

    }

    printf("%d %d %d",--cx,--cy,ch);



    return 0;

}
