#include <stdio.h>

#include <cmath>

#include <algorithm>

#include <cfloat>

#include <stack>

#include <queue>

#include <vector>

#include <string.h>

typedef long long int ll;

typedef unsigned long long int ull;

#define BIG_NUM 2000000000

#define MOD 1000000007

#define EPS 0.000000001

using namespace std;



double ans = 0,P,E,T;

int K;



void recursive(double R,double L,double probability,int count){



	if(L < T-E || R > T+E)return;



	if(count == K){

		if(fabs(T-(R+L)/2.0) <= E){

			ans += probability;

		}

		return;

	}



	double H = (R+L)/2.0;



	double right_R,right_L,wrong_R,wrong_L;



	if(H > T){



		right_R = R,right_L = H;

		recursive(right_R,right_L,probability*(1-P),count+1);



		wrong_R = H,wrong_L = L;

		recursive(wrong_R,wrong_L,probability*P,count+1);



	}else{



		right_R = H,right_L = L;

		recursive(right_R,right_L,probability*(1-P),count+1);



		wrong_R = R,wrong_L = H;

		recursive(wrong_R,wrong_L,probability*P,count+1);

	}

}



int main(){



	double first_R,first_L;



	scanf("%d %lf %lf",&K,&first_R,&first_L);

	scanf("%lf",&P);

	scanf("%lf",&E);

	scanf("%lf",&T);



	recursive(first_R,first_L,1.0,0);



	printf("%.6lf\n",ans);



	return 0;

}