#include <stdio.h>



#define endl '\n'



int main()

{

    int n, i, s=0;

    scanf("%d", &n);

    int a[n], b[n];



    for(i=0; i<n; i++) scanf("%d", &a[i]);



    for(i=0; i<n; i++)

    {

        scanf("%d", &b[i]);

        b[i]=a[i]-b[i];



        if(b[i]>0) s+=b[i];

    }



    printf("%d", s);



    return 0;

}
