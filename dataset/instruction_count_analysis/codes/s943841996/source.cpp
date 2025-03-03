#include <iostream>

#include <cstring>

# define mod 1000000007

using namespace std;

typedef long long ll;

ll dp[100009][13];

int main(){

	string s;

	cin>>s;

	memset(dp,0,sizeof(dp));

	if(s[0]=='?')

		for(int i=0;i<10;i++)

			dp[0][i]=1;

	else

		dp[0][s[0]-'0']=1;

		int len=s.length();

	for(int i=1;i<len;i++)

	{

		if(s[i]=='?')

		{

			for(int j=0;j<13;j++)

				for(int k=0;k<10;k++)

				{

					dp[i][(j*10+k)%13]+=dp[i-1][j];

					dp[i][(j*10+k)%13]%=mod;

				}

		}

		else

		{

			for(int j=0;j<13;j++)

			{

				dp[i][(s[i]-'0'+j*10)%13]+=dp[i-1][j];

				dp[i][(s[i]-'0'+j*10)%13]%=mod;

			}

		}

	}

		 cout<<dp[len-1][5]<<endl;

	return 0;

} 