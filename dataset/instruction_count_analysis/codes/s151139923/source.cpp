#include<stdio.h>



int main()

{

    int N, L[101], max=-1, i, sum=0, count=0;



    scanf("%d", &N);





    for(i=0; i<N; i++){

        scanf("%d", &L[i]);



        if(L[i]>max)

            max=L[i];

    }



    for(i=0; i<N; i++){

        if(count==0)

            if(max==L[i]){

                count++;

                continue;

            }



        sum += L[i];

    }



    if(max < sum)

        printf("Yes\n");

    else

        printf("No\n");



    return 0;

}
