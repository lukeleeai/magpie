#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>

#include <map>

using namespace std;

const int maxn=1e5+5;

const int mod=1e9+7;

long long dp[maxn][13];

char s[maxn];

int main(){

	cin>>s+1;

	int n=strlen(s+1);

	dp[0][0]=1;

	for(int i=1;i<=n;i++){

		if(s[i]!='?'){

			s[i]-='0';

			for(int j=0;j<13;j++){

				dp[i][(j*10+s[i])%13]=(dp[i][(j*10+s[i])%13]+dp[i-1][j])%mod;

			}

		}else{

			for(int k=0;k<10;k++){

				for(int j=0;j<13;j++){

					dp[i][(j*10+k)%13]=(dp[i][(j*10+k)%13]+dp[i-1][j])%mod;

				}

			}

		}

	} 

	cout<<dp[n][5]<<endl; 

	return 0;

}