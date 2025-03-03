#include "stdc++.h"

#define maxn 100086



using namespace std;



int n, m, x, y;

long long ans;



int main(){

	scanf("%d%d", &n, &m);

	for(int i = 1;i <= n;i++){

		scanf("%d", &x);

		if(i == 1){

			y = x;

			continue;

		} 

		int j = max(0, x + y - m);

		ans += j, y = max(0, x - j); 

	}	

	printf("%lld", ans);

}