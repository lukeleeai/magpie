# include "stdc++.h"

  using namespace std;



typedef long long int int64;

typedef unsigned long long int uint64;

typedef vector<int64> vi;

typedef vector<bool> vb;

typedef vector<char> vc;

typedef pair<int64,int64> pi; 

bool doubleSame(double a, double b)

{ const double eps = 1e-15; return ( abs(a-b)<= eps*abs(a) ); }

 

int main()

{

	int64 n,k;

	cin>>n>>k;

 

	vector<int64> h(n);

	for(int64 i = 0 ; i<n ; i++)

		cin>>h[i];

 

	vector<int64> ans(n);

	ans[0] = 0;

	ans[1] = abs(h[1]-h[0]);

 

	for(int64 i = 2 ; i<n ; i++)

	{

		ans[i] = abs(h[i]-h[i-1])+ans[i-1];

		for(int64 j = 2 ; j<=i && j<=k ; j++)

			ans[i] = min(ans[i],abs(h[i]-h[i-j])+ans[i-j]);	

	}

	cout<<ans[n-1];

}