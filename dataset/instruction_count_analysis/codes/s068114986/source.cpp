#include <stdio.h>

#include <math.h>



typedef long long ll;



ll number2(ll N,ll K){

	if(N == K)

		return 0;

	while(1){

		if(N > K)

    		N = N - (N / K) * K;

    	else

    		return (labs(N - K) <= N ? labs(N - K) : N);

	}

	

}



int main(){

	ll N,K;

	while(~scanf("%lld %lld",&N,&K))

	    printf("%lld\n",number2(N,K));

	return 0;

}