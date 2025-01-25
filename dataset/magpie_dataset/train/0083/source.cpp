#include <stdio.h>

#include <cmath>

#include <algorithm>

#include <stack>

#include <queue>

#include <vector>



using namespace std;



int**dp;



void func(int N,int C){

	int beat[N][16],push[C][16];



	int maximum = 0;



	for(int i = 0; i < N; i++){

		for(int k = 0; k < 16; k++)scanf("%d",&beat[i][k]);

	}



	for(int i = 0; i < C; i++){

		for(int k = 0; k < 16; k++)scanf("%d",&push[i][k]);

	}



	int tmp,S,code;



	int work[C][16];



	S = 1;

	code = 0;

	for(int i = 0; i < 16; i++){

		code += S*beat[0][i];

		S *= 2;

	}

	dp[1][code] = 0;





	for(int k = 0; k < C; k++){

		tmp = 0;

		for(int p = 0; p < 16; p++){

			work[k][p] = beat[0][p];

			if(work[k][p] == 1){

				if(push[k][p] == 1){

					work[k][p] = 0;

					tmp++;

				}

			}

		}



		S = 1;

		code = 0;

		for(int i = 0; i < 16; i++){

			code += S*work[k][i];

			S *= 2;

		}

		dp[1][code] = max(dp[1][code],tmp);

		maximum = max(maximum,dp[1][code]);

	}



	for(int i = 1; i < N; i++){

		for(int state = 0; state < 65536; state++){

			if(dp[i][state] != -1){



				S = 1;

				code = 0;

				for(int loop = 0; loop < 16; loop++){

					if(state & (1 << loop)){

						code += S;

					}else{

						code += S*beat[i][loop];

					}

					S *= 2;

				}

				dp[i+1][code] = dp[i][state];



				for(int k = 0; k < C; k++){

					tmp = 0;

					for(int p = 0; p < 16; p++){

						if(state & (1 << p)){

							if(push[k][p] == 1){

								work[k][p] = 0;

								tmp++;

							}else{

								work[k][p] = 1;

							}



						}else{

							work[k][p] = beat[i][p];

							if(work[k][p] == 1){

								if(push[k][p] == 1){

									work[k][p] = 0;

									tmp++;

								}

							}

						}

					}



					S = 1;

					code = 0;

					for(int a = 0; a < 16; a++){

						code += S*work[k][a];

						S *= 2;

					}

					dp[i+1][code] = max(dp[i+1][code],tmp+dp[i][state]);

				}

			}

		}

	}



	for(int i = 0; i < 65536; i++)maximum = max(maximum,dp[N][i]);



	printf("%d\n",maximum);

}



int main(){



	int N,C;

	dp = new int*[31];

	for(int i = 0; i < 31; i++){

		dp[i] = new int[65536];

	}



	while(true){

		scanf("%d %d",&N,&C);

		if(N == 0 && C == 0)break;



		for(int i = 0; i <= N; i++){

			for(int k = 0; k < 65536; k++)dp[i][k] = -1;

		}



		func(N,C);

	}



    return 0;

}