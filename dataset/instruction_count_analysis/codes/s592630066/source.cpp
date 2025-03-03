#include <cstdio>

#include <algorithm>



using namespace std;





typedef long long LL;



int main(){

    LL N,A,B;

    scanf("%lld%lld%lld",&N,&A,&B);

    LL sum = (B-A)*(N-2)+1;

    if(A>B){

        printf("0");

        return 0;

    }

    if(N == 1 && A != B){

        printf("0");

        return 0;

    }

    if(N == 1 && A == B){

        printf("1");

        return 0;

    }

    printf("%lld", sum);



}
