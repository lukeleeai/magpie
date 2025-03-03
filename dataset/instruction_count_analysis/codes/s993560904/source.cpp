#include <cstdio>

#include <iostream>

#include <cstring>



using namespace std;



typedef long long ll;

const int MAXN = 10010;

const int MAXD = 110;

const int MOD = 1e9+7;



char s[MAXN];

int n, d;



inline int add(int x, int y){return (x += y) >= MOD ? x - MOD : x;}

inline int sub(int x, int y){return (x -= y) < 0 ? x+MOD : x;}



int f[MAXN][MAXD][2];

bool vis[MAXN][MAXD][2];



int dfs(int x, int y, bool lim)

{

	if(x > n) return (y == 0);

	if(vis[x][y][lim]) return f[x][y][lim];

	int maxd = lim ? s[x] - '0' : 9;

	for(int i = 0; i <= maxd; i++){

		f[x][y][lim] = add(f[x][y][lim], dfs(x + 1, (y + i) % d, ((i == maxd) && lim) ) );

	}

	vis[x][y][lim] = 1;

	return f[x][y][lim];

}



int main()

{

	scanf("%s%d",s+1 ,&d);

	n = strlen(s+1);

	printf("%d\n",sub(dfs(1, 0, 1), 1));

	return 0;

}