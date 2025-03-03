#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<algorithm>

#include<iostream>

using namespace std;

int main(){

	long long n,T,t[200000];

	long long sum=0;

	cin>>n>>T;

	for(long long i=1;i<=n;i++)

		cin>>t[i];

	for(long long i=2;i<=n;i++){

		if(t[i]-t[i-1]>=T)

			sum+=T;

		else

			sum+=t[i]-t[i-1];

	}

	sum+=T;

	cout<<sum<<endl;

}






