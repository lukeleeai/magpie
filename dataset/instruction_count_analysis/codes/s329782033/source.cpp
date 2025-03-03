#include <stdio.h>

#define MAX 10000



int main(){

    

    int x;

    

    for(int i = 1;i < MAX + 1;i++){

        scanf("%d",&x);

        if(x==0)

            break;

        printf("Case %d: %d\n",i,x);

    }

    return 0;

}