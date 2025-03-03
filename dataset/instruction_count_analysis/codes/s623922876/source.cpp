#include<cstdio>



int N,X;



int main(){

    scanf("%d%d",&N,&X);

    if(X==1||X==2*N-1)

        return !puts("No");

    puts("Yes");

    if(N==2)

        return !puts("1\n2\n3");

    if(X==2){

        for(int i=1;i<=N-2;i++)

            printf("%d\n",4+i);

        printf("3\n2\n1\n4\n");

        for(int i=1;i<=N-3;i++)

            printf("%d\n",N+2+i);

        return 0;

    }

    int cnt=1;

    for(int i=1;i<=N-2;i++){

        if(cnt==X-2)

            cnt=X+2;

        printf("%d\n",cnt++);

    }

    printf("%d\n%d\n%d\n%d\n",X-1,X,X+1,X-2);

    for(int i=1;i<=N-3;i++){

        if(cnt==X-2)

            cnt=X+2;

        printf("%d\n",cnt++);

    }

}