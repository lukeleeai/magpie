#include<iostream>

#include<algorithm>

#include<cmath>

#include<cstring>

#include<cstdlib>

#include<ctime>

#include<cstdio>

#include<string>

//#include<string>

//#include<sstream>

#include<iomanip>

using namespace std;

int main() {

	long long  n,a,b;

	long long x[100000],i;

	scanf("%lld%lld%lld",&n,&a,&b);

	for(i=0;i<n;i++){

		scanf("%lld",&x[i]);

	}

	long long sum=0;

	for(i=1;i<n;i++){

		sum+=min((x[i]-x[i-1])*a,b);

	}

	printf("%lld\n",sum);

}