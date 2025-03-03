#include<iostream>

#include<cmath>

using namespace std;

typedef long long ll;





int main(){

	ll yu = 100;

	ll x;

	cin>>x;

	int ans = 0;

	while(yu < x)

	{

		yu += yu * 0.01;

		ans++;

	}

	

	cout<<ans<<endl;

	

	return 0;

}


