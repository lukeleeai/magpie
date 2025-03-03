#include <stdio.h>



int main(){

    

    int mula=1;

    int count=0;

    int brpKali;    //4

    scanf("%d", &brpKali);

    int tambahBrp;  //3

    scanf("%d", &tambahBrp);

    for(int i=0;i<(brpKali-count);i++){

        while(mula<=tambahBrp){

            if(count>=brpKali){

                break;

            }

            mula*=2;

//            printf("dikali 2 jadi %d\n", mula);

            count++;



        }

        if(count>=brpKali){

            break;

        }

        mula+=tambahBrp;

//        printf("ditambah 3 jadi %d\n", mula);

    }

printf("%d", mula);





    return 0;

}