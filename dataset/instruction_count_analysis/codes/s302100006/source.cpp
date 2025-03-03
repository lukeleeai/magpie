#include<iostream>

using namespace std;

int main(){

	int i;

	long long n,a[200005],ans=0,x,sum;

	cin>>n>>x;

	for(i=1;i<=n;i++)

		cin>>a[i];

	if(a[1]>x){

		sum=a[1]-x;

		ans+=sum;

		a[1]-=sum;

	}

	for(i=1;i<=n;i++){

		if(i!=n&&a[i]+a[i+1]>x){

			sum=a[i]+a[i+1]-x;

			ans+=sum;

			a[i+1]-=sum;

		}

	}

	cout<<ans;

	return 0;

}