#include "stdc++.h" 

using namespace std;

 

int INF = 0x3f3f3f3f;

const int mod = 1000000007;

 

 

 

int main(){

	int prime[1005];

	long long int i,j;

	for(i=1;i<=1000;i++){

		prime[i]=1;

	}

	prime[1]=0;

	prime[2]=1;

	for(i=2;i<=1000;i++){

		if(prime[i]==1){

			for(j=2;j*i<=1000;j++){

				prime[j*i]=0;

			}

		}

	}

	long long int n;

	cin>>n;

	int num[1005];

	long long int namae;

	memset(num,0,sizeof(num));

	for(i=2;i<=n;i++){

		if(prime[i]==1){

			num[i]+=1;

		}else{

			for(j=2;j<=i;j++){

				namae = i;

				while(prime[j]==1 && namae%j==0){

					num[j]+=1;

					namae=namae/j;

				}

			}

		}

	}

	long long int ans=1;

	for(i=1;i<=n;i++){

		ans *= (num[i]+1);

		ans = ans%mod;

	}

	cout<<ans<<endl;

	return 0;

}