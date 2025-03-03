#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

int a,b,c,d;



int main()

{

    while (scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)

    {

        if (a+b==c+d) puts("Balanced");

        else if (a+b>c+d) puts("Left");

        else puts("Right");

    }

    return 0;

}


