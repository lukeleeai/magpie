#include <stdio.h>

int main (){

    long long int N;

    long long int total=1;

    

    scanf("%lld",&N);

    long long int A[N]; 

    

    for(int i=0;i<N;i++){

        scanf("%lld", &A[i]);

    }

    for(int j=0;j<N;j++){

        if(A[j] == 0){  

            printf("0"); 

            return 0;

        }

    }

    for(int k=0;k<N;k++){

        if(A[k]<=1000000000000000000/total){

            total = total*A[k];

            

        } else {

            printf("-1");

            return 0;

        }

    }

    printf("%lld", total);

    

    

return 0;

}