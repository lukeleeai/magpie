#include <cstdio>

int main () {

    int n,k,a,b,c;

    scanf("%d%d%d",&n,&k,&b);

    c=k=0,n--;

    while(n--){

        scanf("%d",&a);

        if (a-b==c) k++;

        else if (a-b>c) k=1,c=a-b;

        else if (a<b) b=a;

    }

    printf("%d\n",k);

    return 0;

}
