#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define ll long long

int H,W,N;

ll arr[1000005];

ll ans[10];

ll d=1e9+7;

int main()

{

    scanf("%d%d%d",&H,&W,&N);

    int x,y;

    int xx,yy;

    int count=0;

    for(int i=0;i<N;i++)

    {

       scanf("%d%d",&x,&y);

       for(int i=-1;i<=1;i++)

       {

           for(int j=-1;j<=1;j++)

           {

               xx=x+i;

               yy=y+j;

               if(xx>1&&xx<H&&yy>1&&yy<W)

                    arr[count++]=xx*d+yy;

           }

       }

    }

    sort(arr,arr+count);

    int c=1;

    ll z=(ll)(H-2)*(ll)(W-2);

    memset(ans,0,sizeof(ans));

    for(int i=0;i<count;i++)

    {

        if(arr[i]==arr[i+1])

            c++;

        else

        {

            z--;

            ans[c]++;

            c=1;

        }

    }

    printf("%lld\n",z);

    for(int i=1;i<10;i++)

        printf("%lld\n",ans[i]);

    return 0;

}
