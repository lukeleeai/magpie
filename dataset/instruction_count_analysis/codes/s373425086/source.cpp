#include <stdio.h>

int main(void){

    int power_5[120] = {0};

    for(int i = 0; i < 120; i++){

        power_5[i] = i*i*i*i*i;

    }

    int x = 0;

    int flag = 0;

    scanf("%d",&x);

    for(int i = 0; i < 120; i++){

        for(int j = i; j < 120; j++){

            if(power_5[i]+power_5[j]==x){

                printf("%d %d",j,-i);

                flag = 1;

                break;

            }

            if(power_5[j] - power_5[i]==x){

                printf("%d %d",j,i);

                flag = 1;

                break;

            }

        }

        if(flag == 1){

            break;

        }

    }









    return 0;

}
