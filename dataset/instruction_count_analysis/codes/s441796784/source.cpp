#include "stdc++.h"

using namespace std; 

long long dp[500000]; 

inline long long stoii(string s)

{

	long long res=0;

	for(int i=0; i<s.size(); i++)

		res*=10, res+=(s[i]-'0');

	return res;	

}

int main() 

{  

    string s;

    cin>>s;

    memset(dp, 0, sizeof(dp));

    dp[0]=1, dp[1]=1, dp[2]=2, dp[3]=4, dp[4]=8, dp[5]=16, dp[6]=32, dp[7]=64, dp[8]=128, dp[9]=256, dp[10]=512;

    long long ans=0;

    int len=s.size();

    for(int i=1; i<=len; i++)

    	for(int j=0; (j+i)<=len; j++)

    		ans+=(long long)(stoii(s.substr(j, i))*dp[j]*dp[len-i-j]);

	cout<<ans;

    return 0;  

}  
