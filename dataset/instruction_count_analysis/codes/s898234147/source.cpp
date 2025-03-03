#include <stdio.h>

int main(){

    int n,ans=0;

    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);

    }

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            for(int k=j+1;k<n;k++){

                if(arr[i]!=arr[j]&&arr[j]!=arr[k]&&arr[k]!=arr[i]&&arr[i]+arr[j]>arr[k]&&arr[j]+arr[k]>arr[i]&&arr[k]+arr[i]>arr[j]){

                    ans++;

                }

            }

        }

    }

    printf("%d\n",ans);

}