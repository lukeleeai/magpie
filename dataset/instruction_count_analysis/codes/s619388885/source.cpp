#include<iostream>

#include<algorithm>

#include<map>

using namespace std;

typedef long long ll;

long long mod=1e9+7;



int main()

{

	int n;

	cin>>n;

	int a[n];

	map<ll,ll>m;

	for(int i=0;i<n;i++)

		{

			cin>>a[i];

			m[a[i]]++;

		}

	

	  if(m.count(0))

	  {

    	if(n%2==0 || m[0] != 1){

     		 cout << 0 << endl;

      	return 0;

      	}

    	m.erase(0);

  	  }

  

  	  ll ans = 1;

  	for(auto ite:m){

    if(ite.second %2 != 0){

      cout << 0 << endl;

      return 0;

    }

    ans *= ite.second % mod;

    ans %= mod;

  }

  cout << ans%mod << endl;

  

  

	

	return 0;

}