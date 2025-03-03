#include <stdio.h>



int mult_2(int n) {

    int myNum = n;



    while(myNum % 2 != 0 || myNum % n != 0) {

        myNum++;

    }



    return myNum;

}





int main() {

    int n;



    scanf("%d", &n);



    printf("%d\n", mult_2(n));



    return 0;

}