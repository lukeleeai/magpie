#include<cmath>

#include<cstdio>

using namespace std;

int a,b,c,len;

int main()

{

    scanf("%d%d",&a,&b);

    c=b;

    while(c>0)

    {

        c/=10;

        len++;

}

    a=a*pow(10,len)+b; 

    if(sqrt(a)==floor(sqrt(a)))printf("Yes");

    else printf("No");

}
