#include<cstdio>

#include<algorithm>

using namespace std;

const int MAXN=(int)1e5+10;

int N,L,T,X,W;int a[MAXN],m;

int main (){

    scanf ("%d%d%d",&N,&L,&T);

    for (int tp=N-1;tp>=0;tp--){

        scanf ("%d%d",&X,&W);

        if (W==2) W=-1;

        int tpp=X+T*W;

        a[N-1-tp]=((tpp%L)+L)%L;

        m+=tpp/L;if (tpp%L<0)m--;

    }m=((m%N)+N)%N;sort(a,a+N);

    for (int i=m;i<N;i++){

        printf("%d\n",a[i]);

    }for (int i=0;i<m;i++){

        printf("%d\n",a[i]);

    }return 0;

}