#include <iostream>

#include <cstring> 

#include <cmath>

#include <cstdio>

const long long mod=1e9+7;

using namespace std;

long long f(long long m,long long n){

	long long ans=1;

	while(n>0){

		if(n&1)

			ans=(ans*m)%mod;

		m=(m*m)%mod;

		n=(n/2)%mod;

	}

	return ans;

}

int main(){

	long long n;

	scanf("%lld",&n);	

		cout<<(f(10,n)%mod-(2*f(9,n))%mod+f(8,n)%mod+mod)%mod<<endl;	

	return 0;

}