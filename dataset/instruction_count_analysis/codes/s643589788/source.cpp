#include<cstdio>



long long Solve(long long a,long long b){

    if(b%a==0)

        return b/a*a*2-a;

    return b/a*a*2+Solve(b%a,a);

}



int main(){

    long long N,X;

    scanf("%lld%lld",&N,&X);

    printf("%lld",N+Solve(X,N-X));

}
