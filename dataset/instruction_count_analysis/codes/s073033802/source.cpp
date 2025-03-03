#include <algorithm>

#include <iostream>

#include <math.h>

#include <stdio.h>

#include <string>

#include <sstream>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <cmath>

#include <bitset>

 

using namespace std;

bool hasSearched[100][100000];

int dp[100][100000];

int v[100] = {0};

int w[100] = {0};

int N;



void init(){

	for(int i = 0; i < 100; i++){

		for(int j = 0; j < 100000; j++){

			hasSearched[i][j] = false;

		}

	}

}



int solve(int i,int U){

	if(i == N){

		return 0;

	}else if(U < w[i]){

		return solve(i+1,U);

	}

	if(hasSearched[i][U] == true) return dp[i][U];

	int res1,res2;

	res1 = solve(i+1,U-w[i]) + v[i];

	res2 = solve(i+1,U);

	dp[i][U] = max(res1,res2);

	hasSearched[i][U] = true;

	return max(res1,res2);

}



int main()

{

	init();

	int W;

	cin>>N>>W;

	for(int i = 0; i < N; i++){

		cin>>v[i]>>w[i];

	}

	cout<<solve(0,W)<<endl;

	return 0;

}
