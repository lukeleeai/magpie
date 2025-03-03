#include <stdio.h>



int main() {

    int cc;

    scanf("%d", &cc);

    int AC=0, TLE=0, WA=0, RE=0;

    for(int i = 0; i < cc; i++){

   char k[100];

   scanf("%s", k);

    if(k[0] == 'A'){

        AC++;

     }

     if(k[0] == 'T'){

       TLE++;

     }

     if(k[0]== 'W'){

         WA++;

     }

     else if(k[0]== 'R'){

        RE++;

     }

   



    }



printf(" AC x %d\n WA x %d\n TLE x %d\n RE x %d\n", AC, WA, TLE, RE); 



     return 0;

}