#include <stdio.h>

#include <cmath>

#include <algorithm>

#include <stack>

#include <queue>

#include <vector>

typedef long long int ll;

#define BIG_NUM 2000000000

#define MOD 1000000007

#define EPS 0.000001

using namespace std;



int W,H,index[20][20],dp[20][20][1024],fin_state;

char table[20][21];



struct Info{

	Info(){

		row = 0;

		col = 0;

		state = 0;

		cost = 0;

	}



	Info(int arg_row,int arg_col,int arg_state,int arg_cost){

		row = arg_row;

		col = arg_col;

		state = arg_state;

		cost = arg_cost;

	}

	int row,col,state,cost;

};



Info start,Target[10];

int diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0},target_count,next_state;



bool rangeCheck(int row,int col){

	if(row >= 0 && row <= H-1 && col >= 0 && col <= W-1)return true;

	else{

		return false;

	}

}



bool enable_check(int start_row,int start_col){

	bool visited[20][20];



	for(int i = 0; i < H; i++){

		for(int k = 0; k < W; k++)visited[i][k] = false;

	}



	queue<Info> S;

	visited[start_row][start_col] = true;



	S.push(Info(start_row,start_col,0,0));



	int to_row,to_col;



	while(!S.empty()){

		for(int i = 0; i < 4; i++){

			to_row = S.front().row + diff_row[i];

			to_col = S.front().col + diff_col[i];



			if(rangeCheck(to_row,to_col) == false || visited[to_row][to_col] == true || table[to_row][to_col] == 'x')continue; //?????????????????????????????£????????¨???????????????????????????????????????skip



			visited[to_row][to_col] = true;

			S.push(Info(to_row,to_col,0,0));

		}



		S.pop();

	}



	for(int i = 0; i < target_count; i++){

		if(visited[Target[i].row][Target[i].col] == false)return false;

	}



	return true;

}



int main(){



	int ans,next_row,next_col;

	queue<Info> Q;



	while(true){

		scanf("%d %d",&W,&H);

		if(W == 0 && H == 0)break;



		target_count = 0;



		for(int i = 0; i < H; i++){

			scanf("%s",table[i]);

			for(int k = 0; k < W; k++){

				switch(table[i][k]){

				case '.':

					//Do nothing

					break;

				case '*':

					index[i][k] = target_count;

					Target[target_count].row = i;

					Target[target_count].col = k;

					target_count++;

					break;

				case 'x':

					//Do nothing

					break;

				case 'o':

					start.row = i;

					start.col = k;

					start.state = 0;

					start.cost = 0;

					break;

				}

			}

		}



		if(!enable_check(start.row,start.col)){

			printf("-1\n");

			continue;

		}



		for(int i = 0; i < H; i++){

			for(int k = 0; k < W; k++){

				for(int p = 0; p < pow(2,target_count);p++)dp[i][k][p] = BIG_NUM;

			}

		}



		fin_state = pow(2,target_count)-1;



		while(!Q.empty())Q.pop();



		ans = BIG_NUM;



		dp[start.row][start.col][0] = 0;

		Q.push(start);



		while(!Q.empty()){



			if(Q.front().state == fin_state){

				ans = Q.front().cost;

				break;

			}



			if(Q.front().cost != dp[Q.front().row][Q.front().col][Q.front().state]){

				Q.pop();

				continue;

			}else{



				for(int i = 0; i < 4; i++){

					next_row = Q.front().row + diff_row[i];

					next_col = Q.front().col + diff_col[i];



					if(rangeCheck(next_row,next_col) == false || table[next_row][next_col] == 'x')continue;



					if(table[next_row][next_col] == '.' || table[next_row][next_col] == 'o'){

						if(dp[Q.front().row][Q.front().col][Q.front().state] + 1 < dp[next_row][next_col][Q.front().state]){

							dp[next_row][next_col][Q.front().state] = dp[Q.front().row][Q.front().col][Q.front().state] + 1;

							Q.push(Info(next_row,next_col,Q.front().state,dp[next_row][next_col][Q.front().state]));

						}

					}else{



						if(Q.front().state & (1 << index[next_row][next_col])){



							if(dp[Q.front().row][Q.front().col][Q.front().state] + 1 < dp[next_row][next_col][Q.front().state]){

								dp[next_row][next_col][Q.front().state] = dp[Q.front().row][Q.front().col][Q.front().state] + 1;

								Q.push(Info(next_row,next_col,Q.front().state,dp[next_row][next_col][Q.front().state]));

							}



						}else{

							next_state = Q.front().state + pow(2,index[next_row][next_col]);

							if(dp[Q.front().row][Q.front().col][Q.front().state] + 1 < dp[next_row][next_col][next_state]){

								dp[next_row][next_col][next_state] = dp[Q.front().row][Q.front().col][Q.front().state] + 1;

								Q.push(Info(next_row,next_col,next_state,dp[next_row][next_col][next_state]));

							}

						}

					}

				}

				Q.pop();

			}

		}



		if(ans == BIG_NUM)printf("-1\n");

		else{

			printf("%d\n",ans);

		}



	}



	return 0;

}