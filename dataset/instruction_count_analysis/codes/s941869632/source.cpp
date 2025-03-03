#include "stdc++.h"

#define rep(i,n)for(int i=0;i<(n);i++)

using namespace std;



int p[300000][26];

vector<int>E[300000];

int dp[300000];



int main(){

	string s;cin>>s;

	rep(i,26)p[s.size()][i]=s.size()+1;

	for(int i=s.size()-1;i>=0;i--){

		rep(j,26){

			if(s[i]-'a'==j)p[i][j]=i+1;

			else p[i][j]=p[i+1][j];

			E[p[i][j]].push_back(i);

		}

	}

	memset(dp,0x3f,sizeof(dp));

	dp[s.size()+1]=0;

	for(int i=s.size()+1;i>0;i--){

		for(auto v:E[i]){

			dp[v]=min(dp[v],dp[i]+1);

		}

	}

	int pos=0;

	string ans;

	while(pos!=s.size()+1){

		rep(i,26){

			if(dp[p[pos][i]]==dp[pos]-1){

				ans+='a'+i;

				pos=p[pos][i];

				break;

			}

		}

	}

	cout<<ans<<endl;

}