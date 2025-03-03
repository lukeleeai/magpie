#include<iostream>

using namespace std;

long N,K;

const long mod=1e9+7;

main()

{

	cin>>N>>K;

	long ans=0;

	for(long k=K;k<=N+1;k++)

	{

		long L=k*(k-1)/2,R=N*k-k*(k-1)/2;

		ans+=(R-L+1)%mod;

	}

	cout<<ans%mod<<endl;

}
