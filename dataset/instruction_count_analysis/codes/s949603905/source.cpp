#include<stdio.h>

#include<math.h>



int main()

{

    int a,b,c,d;

    int i,j,k,l,m,n;

    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)

    {

        if(b<=c||d<=a)

        {

            printf("0\n");

        }

        else

        {

            i=a<c?a:c;

            j=a+c-i;

            k=b<d?b:d;

            l=b+d-k;

            printf("%d\n",k-j);

        }

    }

    return 0;

}
