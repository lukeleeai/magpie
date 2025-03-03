#include <stdio.h>



int main(){



    int i;

    int brpkali;

    long long hasil=1;

    unsigned long long Data = 1000000000000000000u;

    scanf("%d", &brpkali);

    long long arr[1000000]={};

    for(i=0;i<brpkali;i++)

    {

        scanf("%lld", &arr[i]);

    }

    for(i=0;i<brpkali;i++)

    {

    

        if (arr[i]==0){

            printf("0\n");

            return 0;

        }

    }

    for(i=0;i<brpkali;i++)

    {

        if (arr[i]<=(Data/hasil))

        {   

            hasil*=arr[i];

            

        }

        else

        {

            printf("-1\n");

            return 0;

        }  

    }

    printf("%lld\n", hasil);



    return 0;

}