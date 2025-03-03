#include <stdio.h>

#include <algorithm>

using namespace std;



int main()

{

    long int arr[200010]={0};

    long int arrmin;

    long int dmax;

    int n=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%ld",&arr[i]);

        if(i==0){

            arrmin=arr[0];

            continue;

        } 

        if(i==1) dmax=arr[1]-arr[0];

        if(arr[i-1]<=arr[i]){

            dmax=max(arr[i]-arrmin,dmax);

        }else{

            arrmin=min(arr[i],arrmin);

        }        

    } 

    printf("%ld\n",dmax);





    return 0;

}
