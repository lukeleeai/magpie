#include "stdc++.h"

using namespace std;

int n , a[1000000] , frog , memo[1000000];



int f(int n){

	if(n == 1)return 0;

	if(n == 2)return abs(a[1] - a[2]);

	if(memo[n] != -1)return memo[n];

	memo[n] = min(f(n-1) + abs(a[n] - a[n-1]) , f(n-2) + abs(a[n] - a[n-2]));

	return memo[n];

}

int main(){

	memset(memo , -1 , sizeof(memo));

	scanf("%d" , &n);

	for(int i = 1 ; i <= n ; i++){

		scanf("%d" , &a[i]);

	}

	printf("%d" , f(n));

}