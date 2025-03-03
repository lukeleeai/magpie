#include"stdc++.h"

using namespace std;

int ans,n,a,b,c[1000001];

int main() {

	cin>>n;

	for(int i=0; i<n; i++) {

		cin>>a>>b;

		for(int j=a; j<=b; j++)

			c[j]=1;

	}

	for(int i=0; i<1000001; i++) {

		if(c[i]==1)

			ans++;

	}

	cout<<ans<<endl;

	return 0;

}