#include<cstdio>

int main(void)

{

    int n,sum=0,mi=1e9,p;

    scanf("%d" ,&n);

    while(n--){

        scanf("%d" ,&p);

        if(p<mi)

        {

            mi=p;

            sum++;

        }

    }

    printf("%d" ,sum);

    return 0;

}