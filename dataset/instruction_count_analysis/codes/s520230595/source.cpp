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



struct Info{

	char name[21];

	int length;

};



void strcpy(char* to,char* str){

	for(int i=0;str[i] != '\0';i++){

		to[i] = str[i];

		to[i+1] = '\0';

	}

}



int main(){



	int N,cost[14][14],limit,count,tmp,state,ans,next_state,num_town;

	int*** dp = new int**[15];

	bool*** check = new bool**[15];

	for(int i = 1; i <= 14; i++){

		dp[i] = new int*[14];

		check[i] = new bool*[14];

		for(int k = 0; k < 14; k++){

			dp[i][k] = new int[16384];

			check[i][k] = new bool[16384];

		}

	}

	stack<int> S[15][14];



	Info first_info[14],info[14];

	bool FLG,part_sentence[14];



	while(true){

		scanf("%d",&N);

		if(N == 0)break;



		for(int i = 0; i < N; i++){

			scanf("%s",first_info[i].name);

			for(first_info[i].length = 0; first_info[i].name[first_info[i].length] != '\0';first_info[i].length++);

		}



		for(int i = 0; i < 14;i++)part_sentence[i] = false;



		for(int i = 0; i < N; i++){

			for(int k = 0; k < N; k++){

				if(i != k && first_info[i].length <= first_info[k].length){

					for(int left = 0; first_info[k].length-left >= first_info[i].length;left++){

						FLG = true;



						for(int a = 0; a < first_info[i].length; a++){

							if(first_info[i].name[a] != first_info[k].name[left+a]){

								FLG = false;

								break;

							}

						}



						if(FLG){

							part_sentence[i] = true;

							break;

						}

					}



				}

			}

		}



		num_town = 0;



		for(int i = 0; i < N; i++){

			if(part_sentence[i] == false){

				strcpy(info[num_town].name,first_info[i].name);

				info[num_town].length = first_info[i].length;

				num_town++;

			}

		}



		N = num_town;



		for(int i = 0; i < N; i++){

			for(int k = 0; k < N; k++){

				if(i == k)continue;



				count = 0;



				for(int left = 0; left < info[i].length;left++){

					FLG = true;

					for(int a = left; a < info[i].length && (a-left) < info[k].length;a++){

						if(info[i].name[a] != info[k].name[a-left]){

							FLG = false;

							break;

						}

					}

					if(FLG){

						count = info[i].length-left;

						break;

					}

				}



				cost[i][k] = count;

			}

		}



		limit = pow(2,N);



		for(int i = 1; i <= N;i++){

			for(int k = 0; k < N; k++){

				for(int p = 0; p < limit; p++){

					check[i][k][p] = false;

					dp[i][k][p] = BIG_NUM;

				}

			}

		}



		//?????????1???????????????

		for(int i = 0; i < N; i++){

			tmp = pow(2,i);

			dp[1][i][tmp] = info[i].length;

			S[1][i].push(pow(2,i));

		}



		for(int i = 2; i <= N; i++){

			for(int k = 0; k < N; k++){

				while(!S[i-1][k].empty()){

					state = S[i-1][k].top();

					S[i-1][k].pop();

					if(check[i-1][k][state])continue;

					check[i-1][k][state] = true;



					for(int a = 0; a < N; a++){

						if(state & (1 << a)){

							//Do nothing

						}else{

							next_state = state + pow(2,a);



							if(dp[i][a][next_state] > dp[i-1][k][state] + info[a].length - cost[k][a]){

								dp[i][a][next_state] = dp[i-1][k][state] + info[a].length - cost[k][a];

								S[i][a].push(next_state);

							}

						}

					}

				}

			}

		}



		ans = BIG_NUM;

		for(int i = 0; i < N; i++){

			ans = min(ans,dp[N][i][limit-1]);

		}



		printf("%d\n",ans);

	}



	return 0;

}