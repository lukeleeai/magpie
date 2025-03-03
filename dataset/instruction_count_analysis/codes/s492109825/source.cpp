#include <cstdio>

int a,b,c;

int main() {

    scanf("%d%d%d",&a,&b,&c);

    if ((a==5&&b==7&&c==5)||(a==7&&b==5&&c==5)||

        (a==5&&b==5&&c==7))

        puts("YES");

    else 

        puts("NO");

    return 0;

}