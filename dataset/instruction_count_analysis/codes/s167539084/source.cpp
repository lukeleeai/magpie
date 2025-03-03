#include <cstdio>



using namespace std;



const int maxn = 1e5+5;

int n;

//f[i] = min(f[i-1]+abs(h[i],h[i-1]),f[i-2] + abs(h[i],h[i-2]));

int h[maxn],f[maxn];



int abs(int x,int y) {

	if (x - y < 0) return y - x;

	return x - y;

}



int min(int x,int y) {

	if (x < y) return x;

	return y;

}



int main() {

	scanf("%d",&n);

	for (int i = 1; i <= n; i++) {

		scanf("%d",&h[i]);

	}

	f[0] = f[1] = 0;

	f[2] = abs(h[1],h[2]);

	for (int i = 3; i <= n; i++) {

		f[i] = min(f[i-1]+abs(h[i],h[i-1]),f[i-2] + abs(h[i],h[i-2]));

	}

	printf ("%d\n",f[n]);

	return 0;

}