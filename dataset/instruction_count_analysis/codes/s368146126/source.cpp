#include<stdio.h>

using namespace std;

int main()

{

    char a, b;

    scanf("%c %c", &a, &b);

    if(a=='H' || a=='D'){

            if(b=='H' || b=='D'){

        if(a==b){

            printf("H\n");

        }

        else{

            printf("D\n");

        }

    }

    }

   return 0;

}
