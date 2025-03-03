#include "stdc++.h"

using namespace std;



#define sysp system("pause")



typedef long long ll;



int n;

long long ans,fac;

vector<int> pl;



int main(){

	cin>>n;

	ans=1;

	pl.push_back(2);

	//if(n==3)pl.push_back(3);

	for(int i=3;i<=n;i+=2){

		int k=0;

		for(int j=3;j<=sqrt(i);j+=2){

			if(i%j==0){

				k=1;

				break;

			}

			

		}

		if(k==0)pl.push_back(i);

	}

	for(int i=0;i<pl.size();i++){

		int j=pl[i];

		for(;j<=n;j*=pl[i]){

			fac+=n/j;

		}

		ans*=fac+1;

		ans%=1000000007;

		fac=0;

	}

	cout<<ans<<endl;

	sysp;

} 