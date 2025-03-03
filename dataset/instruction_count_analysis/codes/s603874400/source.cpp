#include"stdc++.h"

using namespace std;

typedef long long ll;

int main(){

	long long  ans=0;

	ll n,m;

	cin>>n>>m;

	if(m==0){

		cout<<n*n<<endl;

		return 0;

	}

	for(int j=1,i=m+1;i<=n;i++,j++){

		ans=ans+n/i*j;

		ll tmp=0;

		tmp=max((ll)0,n%i-m+1);

		ans=ans+tmp;

	}

	cout<<ans<<endl;

	return 0;

}