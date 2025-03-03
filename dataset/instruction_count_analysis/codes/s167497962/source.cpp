#include"stdc++.h"

using namespace std;

typedef long long ll;

int main(){

	int n,x; cin>>n;

	ll tot_a=0, tot_b=0;

	vector<int>a(n),b(n);

	for(int i=0;i<n;i++){

		cin>>a[i];

	}

	for(int i=0;i<n;i++){

		cin>>b[i];

		if(a[i]<b[i]){

			int diff=b[i]-a[i];

			if(diff%2){

				tot_a+=(diff+1)/2;

				tot_b++;

			}

			else tot_a+=(diff/2);

		}

		else 

			tot_b+= (a[i]-b[i]);

	}

	if(tot_a>=tot_b) 

		cout<<"Yes\n";

	else

		cout<<"No\n";

	return 0;

}