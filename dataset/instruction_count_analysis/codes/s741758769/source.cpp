#include<algorithm>

#include<string>

#include<math.h>



using namespace std;



typedef long long ll;

const ll mod = 1e9 + 7;

ll N;



ll find(ll a,ll b){

	ll sum=1;

	while(b){

		if(b&1) sum=(sum*a)%mod;

		a=(a*a)%mod;

		b=b/2;

	}

	return sum;

}



int main(){

	scanf("%lld",&N);



	ll ans=find(10,N)-find(9,N)-find(9,N)+find(8,N);

	printf("%lld",(ans%mod+mod)%mod);



	return 0;

}