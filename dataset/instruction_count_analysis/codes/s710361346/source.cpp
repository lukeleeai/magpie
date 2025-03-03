#include <string.h>

#include <stdio.h>

#include <math.h>

int main ()

{

    int n, c=0;

    scanf ("%d", &n);

    int a[n];

    for (int i=0;i<n;i++) {

        scanf ("%d", &a[i]);

        if (a[i]!=i+1) c++;

    }

    if (c>2) printf ("NO");

    else printf ("YES");

}


