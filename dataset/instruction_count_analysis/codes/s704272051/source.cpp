#include <stdio.h>



int main()

{

    int apple;

    int piecesOfApple;



    scanf("%d %d", &apple, &piecesOfApple);



    int cut = apple * 3;



    piecesOfApple >= 2 || apple >= 1 ? printf("%d", (cut + piecesOfApple) / 2) : printf("0");

    

    return 0;

}