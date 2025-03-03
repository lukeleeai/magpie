#include <stdio.h>



#define endl '\n'



int main()

{

    int n, i, m=0;

    scanf("%d", &n);

    int ara[n];



    for(i=0; i<n; i++)

    {

        scanf("%d", &ara[i]);

        if(ara[i]-i-1) m++;

    }



    !m || m==2? printf("YES"): printf("NO");



    return 0;

}
