#include <stdio.h>



int main()

{

    int i,n,m,a;

    int s=0;

    scanf("%d%d",&n,&m);

    for(i=1;i<=m;i++) {

        scanf("%d",&a);

        s+=a;

    }

    if(n-s>=0) { printf("%d\n",n-s); }

    else { printf("-1\n"); }



    return 0;

}