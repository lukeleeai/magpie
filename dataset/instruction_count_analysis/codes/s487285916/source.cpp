#include<iostream>

using namespace std;



#define ll long long



ll n,mx,a,b[100005],sum[10005],sum2[100005];



int main(int argc, char *argv[])

{

	cin>>n;cin>>a;sum[0]=a;

	for(int i=1;i<n;i++){cin>>a;sum[i]+=a+sum[i-1];}

	for(int i=0;i<n;i++){cin>>b[i];}

	sum2[n-1]=b[n-1];

	for(int i=n-2;i>=0;i--){sum2[i]+=b[i]+sum2[i+1];}

	for(int i=0;i<n;i++)

	{

		mx=max(mx,sum[i]+sum2[i]);

	}

	cout<<mx<<"\n";

	

}



/*



7

3 3 4 5 4 5 3

5 3 4 4 2 3 2



1

2

3



4

1 1 1 1

1 1 1 1



5

3 2 2 4 1

1 2 2 2 1



*/