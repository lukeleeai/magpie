#include<stdio.h>

int main()

{

    long int a, sqr[100050];



    scanf("%ld", &a);



    long int m=a;



    long int max=0, v1=0, v2, cnt1=0;



    for(long int i=0; i<a; i++)

    {



        scanf("%ld", & sqr[i]);



        v2=sqr[i];



        if(v1>=v2)

        {

           cnt1++;

        }



        if(cnt1>max)

        {

            max=cnt1;

        }



        if(v1<v2)

        {

            cnt1=0;

        }



        v1=v2;

    }



    printf("%ld\n", max);





    return 0;

}
