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



int W,H,index[20][20],dp[10][1024],fin_state,from_start[10],min_distance[10][10];

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



			if(rangeCheck(to_row,to_col) == false || visited[to_row][to_col] == true || table[to_row][to_col] == 'x')continue;



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



int calc_distance(Info calc_start,Info calc_goal){

	int ret = BIG_NUM,calc_map[20][20],calc_row,calc_col;



	queue<Info> S;



	for(int i = 0; i < H; i++){

		for(int k = 0; k < W; k++)calc_map[i][k] = BIG_NUM;

	}



	Info first;

	first.row = calc_start.row;

	first.col = calc_start.col;

	first.cost = 0;



	calc_map[first.row][first.col] = 0;



	S.push(first);



	while(!S.empty()){



		if(S.front().row == calc_goal.row && S.front().col == calc_goal.col){

			ret = S.front().cost;

			break;

		}



		if(S.front().cost != calc_map[S.front().row][S.front().col]){

			S.pop();

			continue;

		}else{

			for(int i = 0; i < 4; i++){

					calc_row = S.front().row + diff_row[i];

					calc_col = S.front().col + diff_col[i];



					if(rangeCheck(calc_row,calc_col) == false || table[calc_row][calc_col] == 'x' ||

						calc_map[calc_row][calc_col] <= S.front().cost+1)continue;



					calc_map[calc_row][calc_col] = S.front().cost+1;

					S.push(Info(calc_row,calc_col,0,calc_map[calc_row][calc_col]));

			}

			S.pop();

		}

	}



	return ret;

}



int main(){



	int ans,tmp,limit;

	int POW[14] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

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



		for(int i = 0; i < target_count; i++){

			from_start[i] = calc_distance(start,Target[i]);

		}



		for(int i = 0; i < target_count-1; i++){

			for(int k = i+1; k < target_count;k++){

				if(i == k)continue;

				tmp = calc_distance(Target[i],Target[k]);

				min_distance[i][k] = tmp;

				min_distance[k][i] = tmp;

			}

		}



		limit = POW[target_count];



		for(int i = 0; i < target_count;i++){

			for(int k = 0; k < limit;k++){

				dp[i][k] = BIG_NUM;

			}

		}



		for(int i = 0; i < target_count; i++){

			tmp = POW[i];

			dp[i][tmp] = from_start[i];

		}







		for(int state = 0; state < limit; state++){

			for(int k = 0; k < target_count; k++){

				if(dp[k][state] == BIG_NUM)continue;

				for(int a = 0; a < target_count; a++){

					if(state & (1 << a)){

						//Do nothing

					}else{

						next_state = state+POW[a];

						dp[a][next_state] = min(dp[a][next_state],dp[k][state]+min_distance[k][a]);

					}

				}

			}

		}



		ans = BIG_NUM;

		tmp = POW[target_count]-1;



		for(int i = 0; i < target_count; i++){

			ans = min(ans,dp[i][tmp]);

		}



		printf("%d\n",ans);

	}



	return 0;

}