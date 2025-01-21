///d. one clue

#include <stdio.h>

#include <math.h>



int main()

{

    int k,x;

    scanf("%d %d",&k, &x);



    for(int i=x-k+1;i<=x+k-1;i++){

        printf("%d ",i);

    }

    return 0;

}