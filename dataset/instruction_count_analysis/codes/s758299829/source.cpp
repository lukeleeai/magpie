#include "stdc++.h"

#include <algorithm>

#include <queue>

using namespace std;

int main(){

	long long int N; 

	cin >> N; 

	long long int P = 1e9 + 7; 

	long long int dp[64][3] = {}; //dp[a,bの上位i桁まで決定済][上位i桁までの足し算でNがa+bよりどれだけ大きいか．負なら大小逆転，2以上なら追いつけないので確定でOK] = 場合の数 mod P

	dp[0][0] = 1; 

	for(int i = 1; i <= 60; i++){//Leading zerosを補って60桁と見なす．

		if((N >> (60-i)) & 1){

			dp[i][0] = dp[i-1][0]; 

			dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % P; 

          		dp[i][2] = (dp[i-1][1] * 2 + dp[i-1][2] * 3) % P; 

		}

		else{

			dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % P; 

            		dp[i][1] = dp[i-1][1]; 

            		dp[i][2] = (dp[i-1][1] + dp[i-1][2] * 3) % P; 

		}

	}

	cout << (dp[60][0] + dp[60][1] + dp[60][2]) % P << endl;

}