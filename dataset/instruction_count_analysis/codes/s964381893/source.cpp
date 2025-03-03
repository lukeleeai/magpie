#include<iostream>

using namespace std;

#define ll long long

int main(){

	ll n;

	cin>>n;

	ll a[100001]={0};

	for(int i=0;i<n;i++){

		cin>>a[i];

	}

	int f=1;

	for(int i=n-1;i>0;i--)

	{

		if(a[i]<a[i-1])

		{

			a[i-1]--;

			if(a[i]<a[i-1])

			{

				f=0;

				break;

			}

		}

	}

	if(f==1){

		cout<<"Yes"<<endl;

	}else{

		cout<<"No"<<endl;

	}

	return 0;

}