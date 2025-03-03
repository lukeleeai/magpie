#include<iostream>

#include<cstdio>

#include<cmath>

#include<string>

#include<cstdlib>

#include<algorithm>

#include<fstream>

using namespace std;

int main()

{

    int i,j,x,y,l;

//    while(777)

//    {

        scanf("%d%d",&x,&y);

    int ss=0;

    if(x<0&&y<0&&x>y)

    {

        x=fabs(x);

        y=fabs(y);

        x=y-x;

        x+=2;

        printf("%d\n",x);

           exit(0);

    }

   else if(x<y)

    {

        if(x>=0||y==0)printf("%d\n",y-x);

        else if(y<0)printf("%d\n",y-x);

        else if(x<0&&-x<y)printf("%d\n",y+x+1);

        else if(x<0&&-x>y)

        {

           printf("%d\n",-x-y+1);

        }

        else if(x<0&&-x==y)printf("%d\n",1);

        else printf("%d\n",y-x);

        exit(0);

    }

    else if(x>y)

    {

        if(y>0)

        {

            ss+=2;

            printf("%d\n",ss+x-y);

        }

        else

        {

            if(-y>x)

            {

                printf("%d\n",-x-y+1);

            }

            else

            {

                printf("%d\n",x+y+1);

            }

        }

         exit(0);

    }

//    }

    return 0;

}
