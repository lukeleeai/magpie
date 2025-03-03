#include "stdc++.h"

using namespace std;

int memo[200][200] , n , m , nxtr , nxtc;

char grid[200][200];

int dx[] = {1 , 0};

int dy[] = {0 , 1};

bool inside(int a , int b){

	return (a >= 1 && a <= n && b >= 1 && b <= m);

}

int dp(int r , int c){

	if(!inside)return 1e8;

	if(r == n && c == m){

		if(grid[r][c] == '#')return 1;

		else return 0;

	}

	if(memo[r][c] != 1e8)return memo[r][c];

	for(int i = 0 ; i <= 1 ; i++){

		if(!inside(r + dx[i] , c + dy[i]))continue;

		nxtr = r + dx[i];

		nxtc = c + dy[i];

		if(grid[r][c] == '.'){

			memo[r][c] = min(dp(nxtr , nxtc) , memo[r][c]);

		}

		else if(grid[r][c] == '#'){

			if(grid[nxtr][nxtc] == '#')memo[r][c] = min(dp(nxtr , nxtc) , memo[r][c]);

			else memo[r][c] = min(dp(nxtr , nxtc) + 1 , memo[r][c]);

		}

	}

	return memo[r][c];

}

int main(){

	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++){

		for(int j = 1 ; j <= m ; j++){

			cin >> grid[i][j];

			memo[i][j] = 1e8; 

		}

	}

	cout << dp(1 , 1) << endl;

}