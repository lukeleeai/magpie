#include<cstdio>



int main(){

    int N, arr[105], x;

    int sum = 0;

    scanf("%d",&N);



    for(int i=0;i<N;i++){

        scanf("%d",&arr[i]);

        sum+=arr[i];

    }

    int M, p;

    scanf("%d",&M);

    for(int i=0;i<M;i++){

        scanf("%d%d",&p,&x);

        printf("%d\n",sum-arr[p-1]+x);

    }

    return 0;

}
