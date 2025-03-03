#include<stdio.h>

#include<algorithm>

using namespace std;

   int n;

   int a[205];

   int main()

   {

   while(scanf("%d",&n)!=EOF)

      {

      n=n*2;	

      for(int i=0;i<n;i++)

         scanf("%d",&a[i]);

      sort(a,a+n); 

      int sum=0;

	  for(int i=0;i<n;i=i+2)

	     {

	     sum+=a[i];

		 }

	  printf("%d\n",sum);   

      }	

   } 