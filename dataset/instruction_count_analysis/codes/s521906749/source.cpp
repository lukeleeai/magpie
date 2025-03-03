#include"stdc++.h"

using namespace std;

bool dp[100005];

vector <int> a;

int N, K, temp;

int main(){

	scanf("%d%d", &N, &K);

	memset(dp, 0, sizeof(dp));

	for(int i = 0 ; i<N ; i++){

		scanf("%d", &temp);

		a.push_back(temp);

		dp[temp] = true;

	}

	for(int i = 1 ; i<=K ; i++){

		bool win = false;

		for(auto j : a){

			if(i - j < 0) continue;

			if(dp[i-j] == false){

				win = true;

				break;

			}

		}

		if(win) dp[i] = true;

	}

	if(dp[K]) cout <<"First"<<endl;

	else cout << "Second"<<endl;





}