#include <stdio.h>

#include <string.h>

#define N 200002

#define M 26



char s[N], a[N], f[N];

int head[M] = {0}, last[N][M], c[N], l;



int dfs(int p, int d)

{

	int i, td = d + 1, tp;

	

	a[d] = s[p], f[d] = 1;

	for(i = 0; i < M; i++){

		if(d + c[tp = last[p][i]] < l){

			if(tp){

				if(td < l && dfs(tp, td)) return 1;

			}

			else{

				a[td] = i + 97, f[td] = 1;

				return 1;

			} 

		}

	}

	f[d] = 0;

	return 0;

}



int main()

{		

	int i, j, m, t, mp, tp;

		

	scanf("%s", s + 1);

	l = strlen(s + 1);

	for(i = l, c[0] = 0; i; i--){

		for(j = 0, m = l; j < M; j++){

			t = c[last[i][j] = head[j]];

			if(t < m) m = t;

		}

		c[i] = m + 1;

		head[s[i] - 97] = i;

	}

	

	for(i = 1, m = c[head[mp = 0]]; i < M; i++){

		if(c[head[i]] < c[head[mp]]) mp = i;

	}

	tp = head[mp];



	if(!tp){

		putchar(mp + 97);

		putchar(10);

		return 0;

	}

	l = c[tp];

	for(i = 0; i <= l; i++) f[i] = 0;	

	dfs(tp, 0);

	a[l + 1] = 0;

	for(i = l; !f[i]; i--) a[i] = 97;

	puts(a);

						

	return 0;

}