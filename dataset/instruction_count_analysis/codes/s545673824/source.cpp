#include<stdio.h>

int main()

{

    int h,n,p,k,sum=0;

    scanf("%d%d",&h,&n);

    

    while(n--){

        scanf("%d",&p);

        

        k=p;

        sum=sum+p;

    }

    

    if(h<=sum)printf("Yes");

    else printf("No");

    

    return 0;

}