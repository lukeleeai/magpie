//include

//------------------------------------------

#include <stdio.h>



template<class T,class U> void chmax(T&a,U b){if(a<b)a=b;}

template<class T,class U> void chmin(T&a,U b){if(b<a)a=b;}



//main code

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)

char buf[(1 << 22)], *p1 = buf, *p2 = buf;

inline int read() {

    char c = getchar(); int x = 0, f = 1;

    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}

    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();

    return x * f;

}

int ab[100001];

int main(int argc, char *argv[])

{

	int n = read(),m = read();

	for (int i = 0; i < m; i++) {

		int a = read(),b = read();

		chmax(ab[b], a);

	}

	int ans = 0;

	int k = 1;

	for (int i = 1; i <= n; i++) {

		if (k <= ab[i]) {

			k = i;

			ans++;

		}

	}

	printf("%d\n", ans);

	return 0;

}