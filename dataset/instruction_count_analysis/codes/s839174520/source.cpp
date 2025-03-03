#include<cstdio>

#include<string.h>

#include<math.h>

using namespace std;

void move(int d, char ch)

{

    while(d)

    {

        printf("%c",ch);

        d--;

    }

}

int main()

{

    int x1,x2,y1,y2,x,y,i;

    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)!=EOF)

    {

        int x=x2-x1;

        int y=y2-y1;

        for(i=1;i<=4;i++)

        {

            if(i==1)

            {

                move(y,'U');

                move(x,'R');

            }

            else if(i==2)

            {

                move(y,'D');

                move(x,'L');

            }

            else if(i==3)

            {

                printf("L");

                move(y+1,'U');

                move(x+1,'R');

                printf("D");

            }

            else

            {

                printf("R");

                move(y+1,'D');

                move(x+1,'L');

                printf("U");

            }

        }

        printf("\n");

    }

    return 0;

}