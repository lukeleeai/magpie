#include <stdio.h>

#define _USE_MATH_DEFINES

#include <math.h>

#include <vector>

#include <algorithm>



using namespace std;



int main(){

    long n;

    scanf("%ld", &n);

    char str[n+1];

    scanf("%s", str);

    

    long nCount = 0;

    for(long i = 0; i < n; i++){

        if(str[i] == 'R'){

            nCount++;

        }

    }

    long nAns = 0;

    for(long i = 0; i < nCount; i++){

        if(str[i] == 'W'){

            nAns++;

        }

    }

  

    printf("%ld", nAns);

    return 0;

}
