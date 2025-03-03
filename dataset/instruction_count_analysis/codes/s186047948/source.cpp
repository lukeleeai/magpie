#include "stdc++.h"

#define maxn 500086



using namespace std;



const int p = 1e9 + 7;



inline void getNext(char *s, int *nxt){

	int n = strlen(s);

	for(int i = 1;i < n;i++){

		int j = nxt[i - 1];

		while(j && s[j] != s[i]) j = nxt[j - 1];

		if(s[j] == s[i]) j++;

		nxt[i] = j;

	} 

}



int n;

char s[2][maxn];

int nxt[2][maxn];

int ans;



int main(){

	scanf("%s", s[0]);

	int n = strlen(s[0]);

	strcpy(s[1], s[0]);

	reverse(s[1], s[1] + n);

	getNext(s[0], nxt[0]), getNext(s[1], nxt[1]);

	if(!nxt[0][n - 1] || n % (n - nxt[0][n - 1])) return printf("1\n1"), 0;

	if(n - nxt[0][n - 1] == 1) return printf("%d\n1", n), 0;

	for(int i = 0;i < n - 1;i++){

		if((!nxt[0][i] || (i + 1) % (i + 1 - nxt[0][i])) && (!nxt[1][n - i - 2] || (n - i - 1) % (n - i - 1 - nxt[1][n - i - 2]))) ans++;

	}

	printf("2\n%d", ans);

}
