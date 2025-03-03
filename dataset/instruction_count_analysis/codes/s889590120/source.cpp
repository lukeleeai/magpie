#include"stdc++.h"

using namespace std;



#define INF 2000000000

#define ll long long



int N;

int X[200201], Y[200201];



int main()

{

	scanf("%d", &N);

	int mx1 = -INF, mx2 = -INF, mx3 = -INF, mx4 = -INF;

	for(int i=1; i<=N; i++)

	{

		scanf("%d %d", &X[i], &Y[i]);

		mx1 = max(mx1, -X[i]-Y[i]);

		mx2 = max(mx2, -X[i]+Y[i]);

		mx3 = max(mx3, +X[i]-Y[i]);

		mx4 = max(mx4, +X[i]+Y[i]);

	}

	int res = 0;

	for(int i=1; i<=N; i++)

	{

		res = max(res, mx1+X[i]+Y[i]);

		res = max(res, mx2+X[i]-Y[i]);

		res = max(res, mx3-X[i]+Y[i]);

		res = max(res, mx4-X[i]-Y[i]);

	}

	printf("%d", res);

	return 0;

}