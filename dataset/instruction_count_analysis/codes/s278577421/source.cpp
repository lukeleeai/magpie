#include <stdio.h>

#include <algorithm>

using namespace std;



int main()

{

    int minv;

    int dmax=-2000000000;

    int var;

    int n;

    scanf("%d",&n);

    scanf("%d",&minv);

    for(int i=1;i<n;i++){

        scanf("%d",&var);

        dmax=max(var-minv,dmax);

        minv=min(var,minv);

    } 

    printf("%d\n",dmax);





    return 0;

}
