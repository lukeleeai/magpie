#include <stdio.h>



 int main(void){

 	int a, b, c;

 	scanf("%d%d%d", &a, &b, &c);



    int ispoor = 0;

    if (a == b && b != c) ispoor = 1;

    if (b == c && c != a) ispoor = 1;

    if (c == a && a != b) ispoor = 1;



    if (ispoor) {

        puts("Yes");

    } 

    else {

        puts("No");

   }

 

   return 0;

}