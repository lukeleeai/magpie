#include <stdio.h>



int main() {

    int H,A;

    scanf("%d%d",&H,&A);

    H%A<=0?printf("%d",H/A):printf("%d",H/A +1);

    return 0;

}
