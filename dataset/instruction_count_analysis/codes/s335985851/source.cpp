#include<stdio.h>

int main()

{

    int a,z=1,i,sum=0;

    scanf("%d",&a);

    int c[a];

    for(i=0;i<a;i++){

        scanf("%d",&c[i]);

    }

    for(i=0;i<a;i++,z++)

    {

       if(c[i]!=z) sum++;

    }

    if(sum<=2)printf("YES\n");

    else printf("NO\n");

    return 0;

}


