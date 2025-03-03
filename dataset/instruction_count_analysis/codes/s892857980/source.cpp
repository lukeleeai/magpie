#include <stdio.h>

#include <stdlib.h>



int main()

{

   int x, y, z;

   scanf ("%d %d",&x,&z);

   if(x>0 && x<10){

        y = (10-x)*100;

   }

   else{

        y = 0;

   }

   z = z + y;

   printf("%d",z);

}