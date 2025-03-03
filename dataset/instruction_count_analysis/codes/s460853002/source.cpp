#include <stdio.h>

int main(void){

    // Your code here!

    int N,ans=0;

    scanf("%d",&N);

    for(int i = 0;i <= 25;i++){

        for(int j = 0;j <= 15;j++){

            if(4 * i + 7 * j == N)ans = 1;

        }

    }

    if(ans == 1)printf("Yes\n");

    else printf("No\n");

    return 0;

}
