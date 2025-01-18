#include"stdc++.h"

using namespace std;



#define INF 0x3f3f3f3f

#define ii pair<int,int >

#define MAXN 100005



int memo[MAXN], a[MAXN];

int n, k;



int f(int idx){



	if(idx == n) return 0;

	if(memo[idx] != -1) return memo[idx];

	int ans = INF;

	for(int i=1; i<=k; i++){

		if(idx+i <= n) ans = min(f(idx+i) + abs(a[idx] - a[idx+i]), ans);

	}

	return memo[idx] = ans;

}



int main(){



	while(cin >> n >> k){

		//cout << n << endl;

		memset(memo, -1, sizeof(memo));

		for(int i=1; i<=n; i++) cin >> a[i];

		cout << f(1) << endl;

	}	



	return 0;

}