#include"stdc++.h"

#define ll long long

using namespace std;

int n;

ll x,y;

ll gcd(ll x,ll y){

	return y?gcd(y,x%y):x;

}

int main(){

	scanf("%d%lld",&n,&x);

	for (int i=2;i<=n;i++)

		scanf("%lld",&y),x*=y/gcd(x,y);

	printf("%lld",x);

}