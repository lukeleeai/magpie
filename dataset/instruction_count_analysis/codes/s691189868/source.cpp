#include "stdc++.h"

using namespace std;

 

 string arr;

 long long dp[105][4][2];

int k;

 

long long back(int in, int nnzer, bool flag  ){

 

	 if(nnzer>k) return 0;

 	if(in> arr.size()) {  if(nnzer==k) return 1; else return 0;  }

	

	if(dp[in][nnzer][flag]!=-1) return dp[in][nnzer][flag];

	

 	 int limit = 9;

 	 if(!flag) limit=  arr[in-1]-'0';

	long long res =0;

	

	res+=	back(in+1,  nnzer,  flag || limit!=0);

		

 	for(int i=1; i<=limit; ++i){

 

	res+=	back(in+1,  nnzer+1, flag || i<limit);	

 	

 	}

 	

	return dp[in][nnzer][flag] = res;

 }

 

 

 

int main() {

 

	string a;

	cin>>a;

	cin>>k;

	memset(dp, -1, sizeof dp);

	 arr=a;

	 

	long long  c= back(1,0,false);

	 

	 cout<<(c)<<'\n';   

	return 0;

}

 