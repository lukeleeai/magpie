#include<stdio.h>

#include<algorithm>

using namespace std;

char a[2005][2005];

int num[2005][2005];

int main()

{

    int h,w;

    scanf("%d%d",&h,&w);

    getchar();

    for(int i=0; i<h; i++)

    {

        scanf("%s",a[i]);

    }

    for(int i=0; i<h; i++)

    {

        for(int j=0; j<w; j++)

        {

            int cnt=0,k=j;



            while(1)

            {

                if(a[i][k]=='#'||k>w-1)

                {

                    break;

                }



                cnt++;

                k++;

            }

            int s=j;

            for(int l=j; l<j+cnt; l++)

            {

                num[i][s]+=cnt;

                s++;

            }

            j+=cnt;



        }

    }



    int maxx=0;

    for(int j=0; j<w; j++)

    {

        for(int i=0; i<h; i++)

        {

            int cnt=0,k=i;

            while(1)

            {

                if(a[k][j]=='#'||k>h-1) break;

                cnt++;

                k++;

            }

            int s=i;

            for( int l=i; l<i+cnt; l++)

            {

                num[s][j]+=cnt-1;

                s++;

            }

            i+=cnt;

        }

    }

    for(int i=0; i<h; i++)

    {

        for(int j=0; j<w; j++)

        {

            maxx=max(maxx,num[i][j]);

        }

    }

    printf("%d\n",maxx);

    return 0;

}
