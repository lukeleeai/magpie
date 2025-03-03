#include "stdc++.h"

using namespace std;



const int rest = 1000001;

int dp[3][rest];

int ac[rest][3];

int it;



int va(int a, int i){

	if(i == it){

      return 0;

	}

	if(dp[a][i] != -1){

      return dp[a][i];

	}

	int& ans = dp[a][i];

	if(a==0){

		ans=max(ans, va(1, i+1)+ac[i][0]);

		ans=max(ans, va(2, i+1)+ac[i][0]);

	}

	if(a==1){

		ans=max(ans, va(0, i+1)+ac[i][1]);

		ans=max(ans, va(2, i+1)+ac[i][1]);

	}

	if(a==2){

		ans=max(ans, va(0, i+1)+ac[i][2]);

		ans=max(ans, va(1, i+1)+ac[i][2]);

	}



	return ans;

}

int main(){

	cin>>it;

	for(int i=0; i<it; i++){

        cin>>ac[i][0];

        cin>>ac[i][1];

        cin>>ac[i][2];

	}



	memset(dp, -1, sizeof dp);

	cout<<max(va(0,0),max(va(1,0),va(2,0)))<<"\n";

	return 0;

}
