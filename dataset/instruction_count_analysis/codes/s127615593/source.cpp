#include "stdc++.h"

using namespace std; 

int main(){

//  freopen("test.in","r",stdin);

//  freopen("test.out","w",stdout);

	int n,sum=0;

	cin>>n;

	int a[n+1];

	memset(a,0,sizeof(a));

	for(int i =0;i<n;i++) cin>>a[i];

	for(int i =0 ;i<n;i++){

		for(int j=i+1;j<n;j++){

			sum+=a[i]*a[j];

		}

	}

	cout<<sum;

    return 0;

}