#include<stdio.h>



int main()

{

    int n, i, ans=1, j=1;



    scanf("%d", &n);



    int P[n+2];



    for(i=1; i<=n ; i++){

        scanf("%d", &P[i]);

        if(i != P[i]){

            if(j==3){

                ans=0;

                break;

            }

            j++;

        }

    }



    if(ans)

        printf("YES\n");

    else

        printf("NO\n");



    return 0;

}


