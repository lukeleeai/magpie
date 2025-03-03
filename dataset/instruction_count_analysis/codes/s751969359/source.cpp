#include <iostream>

using namespace std;

int main()

{

    int a, b, c, x, y, com, ext,tot=0;

    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

    if (y > x)

    {

        int t = x;

        x = y;

        y = t;

        t = a;

        a = b;

        b = t;

    }

    com=y;ext=x-y;

    if(2*c<a+b)tot+=com*c*2;else tot+=com*(a+b);

    if(2*c<a)tot+=ext*2*c;else tot+=ext*a;\

    printf("%d",tot);

    return 0;

}