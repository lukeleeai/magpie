#include<stdio.h>



int main()

{



   int arr[1000],i,j,k,tc,cnt=0;



   scanf("%d",&tc);



   for(i=0;i<tc;i++)

   {



     scanf("%d",&arr[i]);



   }



   for(j=1;j<(tc-1);j++)

   {



    if((arr[j]>arr[j-1]&&arr[j]<arr[j+1])||(arr[j]<arr[j-1]&&arr[j]>arr[j+1]))

    {

        cnt++;

    }



   }



   printf("%d",cnt);



   return 0;

}
