#include"stdc++.h"

using namespace std;

int main()

{



      int n,k;

      scanf("%d %d",&n,&k);

      int arr[n+5];

      int i;

      for( i=0; i<n; i++)

      {

        scanf("%d",&arr[i]);

      }

       int d = k-1;

      int o=0;

      for(i=d; i<n; i=i+d)

      {

         o++;

         if(i==n-1)

         {

          printf("%d\n",o);

          return 0;

         }

      }

       printf("%d\n",o+1);

      return 0;

}
