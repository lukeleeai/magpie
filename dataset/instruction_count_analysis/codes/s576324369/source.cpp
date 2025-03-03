#include "stdc++.h"



#define F first

#define S second

#define PB push_back



using namespace std;



typedef long long LL;

typedef pair<int, int> PII;

typedef priority_queue<int> HEAP;

typedef priority_queue<int, vector<int>, greater<int> > RHEAP;



const int N = 100010, M = 26;



int n, m;

int f[N][M];

char s[N], t[N];



int main()

{

	scanf("%s%s", s, t);

	n = strlen(s), m = strlen(t);

	

	for (int i = 0; i < M; i ++ ) f[n][i] = n;

	for (int i = n - 1; i >= 0; i -- )

	{

		for (int j = 0; j < M; j ++ ) f[i][j] = f[i + 1][j];

		f[i][s[i] - 'a'] = i;

	}

	

	int a = 0, b = 0;

	for (int i = 0; i < m; i ++ )

	{

		int c = t[i] - 'a';

		if (f[0][c] == n)

		{

			puts("-1");

			return 0;

		}

		

		if (f[b][c] >= n) a ++ , b = 0;

		b = f[b][c] + 1;

	}

	printf("%lld\n", (LL)a * n + (LL)b);

	return 0;

}