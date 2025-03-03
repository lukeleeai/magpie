#include<stdio.h>

#include<math.h>

int main()

{

        char fuhao[4];



        int i;

        int n,nn;

        int a,b,c,d;

        scanf("%d",&n);

        nn=n;

        d=n%10;

        n/=10;

        c=n%10;

        n/=10;

        b=n%10;

        n/=10;

        a=n;

        if(a+b+c+d==7)

        {

                printf("%d+%d+%d+%d=7",a,b,c,d);

                return 0;

        }

        if(a+b+c-d==7)

        {

                printf("%d+%d+%d-%d=7",a,b,c,d);

                return 0;

        }

        if(a+b-c+d==7)

        {

                printf("%d+%d-%d+%d=7",a,b,c,d);

                return 0;

        }

        if(a+b-c-d==7)

        {

                printf("%d+%d-%d-%d=7",a,b,c,d);

                return 0;

        }

        if(a-b+c+d==7)

        {

                printf("%d-%d+%d+%d=7",a,b,c,d);

                return 0;

        }

        if(a-b+c-d==7)

        {

                printf("%d-%d+%d-%d=7",a,b,c,d);

                return 0;

        }

        if(a-b-c+d==7)

        {

                printf("%d-%d-%d+%d=7",a,b,c,d);

                return 0;

        }

        if(a-b-c-d==7)

        {

                printf("%d-%d-%d-%d=7",a,b,c,d);

                return 0;

        }

}