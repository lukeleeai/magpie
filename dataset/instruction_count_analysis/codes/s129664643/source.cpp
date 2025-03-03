#include <stdio.h>



#define endl '\n'



int main()

{

    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);



    a-=b;

    a&1? printf("Borys"): printf("Alice");



    return 0;

}
