#include<cstdio>

#include<cmath>

#include<cstring>

#include<algorithm>

using namespace std;

long long f[123456];

#define mod 1000000007;

int main(){

	int n,m;

	f[1]=1;

	for(int i=2;i<=100000;i++){

		f[i]=(i*f[i-1])%mod;

		

	}//printf("%lld\n",f[2]);

//	printf("%lld\n",f[100000]);

	while(~scanf("%d%d",&n,&m)){

		long long ans=0;

		if(abs(n-m)>2){

			printf("0\n");

		}

		else{

			if(abs(n-m)==1){

				ans+=f[n]*f[m]%mod;

			}

			if(abs(n-m)==0){

				ans+=f[n]*f[m]*2%mod;

			}

			printf("%lld\n",ans);

		}

		

		

	}

		

	

	return 0;

} 