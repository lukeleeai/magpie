#include "stdc++.h"

using namespace std;



int memo[110][10010] = {};



int n;

int s[110];



int dp(int i, int num){

	if(i == n){

		return memo[i][num] = (num % 10 == 0 ? 0 : num);

	}

	if(memo[i][num] != -1) return memo[i][num];

	return memo[i][num] = max(dp(i+1, num), dp(i+1, num+s[i]));

}



int main(){

	cin >> n;

	for(int i = 0;i < n;i++) cin >> s[i];



	memset(memo, -1, sizeof(memo));



	cout << dp(0, 0) << endl;



	return 0;

}
