#include "stdc++.h"

using namespace std;



typedef pair <int, int> P;



const int N = 1e5 + 10;



int dp[N], p[N], deg[N];

priority_queue <P, vector <P>, greater <P> > pq;



int main(){

	int n, id;

	scanf("%d",&n);

	for (int i = 2; i <= n; i++){

		scanf("%d",&p[i]);

		deg[p[i]]++;

	}

	for (int i = 1; i <= n; i++){

		if (!deg[i]) pq.push({0, i});

	}

	while (!pq.empty()){

		id = pq.top().second; pq.pop();

		dp[p[id]] = max(dp[p[id]], dp[id]) + 1;

		if (--deg[p[id]] == 0) pq.push({dp[p[id]], p[id]});

	}

	printf("%d\n", dp[1]);

	return 0;

}