#include <stdio.h>

#include <string.h>

#include <math.h>

int main ()

{

    int n, p=0;

    scanf ("%d", &n);

    int v[n], c[n];

    for (int i=0;i<n;i++) scanf ("%d", &v[i]);

    for (int j=0;j<n;j++) {

        scanf ("%d", &c[j]);

        if (c[j]<=v[j]) p=p+v[j]-c[j];

    }

    if (p>0) printf ("%d", p);

    else printf ("0");

    return 0;

}
