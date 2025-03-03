#include<stdio.h>

int a[300008],b[2000008];

int main(){

    int n,t=0;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

        scanf("%d",a+i),b[i]=0;

    for(int i=n;i>=1;i--){

          int   s=b[i];

        for(int j=2;j*i<=n;j++){

            s+=b[i*j];

        }

        if(s%2!=a[i]){

            s++;

            t++;

            b[i]=1;

            if(s%2!=a[i]){

                printf("-1\n");

                return 0;

            }

        }

    }

    printf("%d\n",t);

    for(int i=1;i<=n;i++){

        if(b[i]){

            printf("%d ",i);

        }

    }

    printf("\n");

}
