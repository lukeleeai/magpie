#include<cstdio>



#define MAXN 1000

int N,cnt;

int X[MAXN+5],Y[MAXN+5],d[35];



int abs(int x){

    return x>0?x:-x;

}



void Print(int x,int y){

    for(int i=1;i<=cnt;i++){

        if(abs(x)>abs(y)){

            if(x>0) putchar('R'),x-=d[i];

            else putchar('L'),x+=d[i];

        }

        else{

            if(y>0) putchar('U'),y-=d[i];

            else putchar('D'),y+=d[i];

        }

    }

}



int main(){

    scanf("%d",&N);

    bool p[2]={0};

    for(int i=1;i<=N;i++){

        scanf("%d%d",X+i,Y+i);

        p[(abs(X[i])+abs(Y[i]))&1]=1;

    }

    if(p[0]&&p[1])

        return puts("-1"),0;

    for(int i=30;i>=0;i--)

        d[++cnt]=1<<i;

    if(p[0])

        d[++cnt]=1;

    printf("%d\n%d",cnt,d[1]);

    for(int i=2;i<=cnt;i++)

        printf(" %d",d[i]);

    for(int i=1;i<=N;i++)

        puts(""),Print(X[i],Y[i]);

}

//