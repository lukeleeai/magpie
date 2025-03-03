#include <stdio.h>

#include<string.h>

int main()

{

    char a[50],b[50],c[100],m,k,i,s;

    scanf("%s",a);

    scanf("%s",b);

    k=strlen(a);

    m=strlen(b);

    s = k > m ? k : m;

    printf("%c%c",a[0],b[0]);

    for(i=1;i<=s;i++)

    {

        c[2*i-1]=a[i];

        c[2*i]=b[i];

    }

    if(k>m)

    {

        for(i=1;i<=2*(k-1)-1;i++)

           printf("%c",c[i]);

    }

    else

    {

        for(i=1;i<=2*(s-1);i++)

           printf("%c",c[i]);

    }

    return 0;

}
