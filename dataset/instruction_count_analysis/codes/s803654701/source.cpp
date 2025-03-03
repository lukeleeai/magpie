#include<stdio.h>

using namespace std;

int main()

{

   int w,a,b;

   scanf("%d %d %d",&w,&a,&b);



  if(a+w<b)

   {

    printf("%d\n",b-(a+w));

   }



    else if(a>b+w)

    {

      printf("%d\n",a-(b+w));

    }



  else

    {

     printf("0\n");

    }

return 0;

}


