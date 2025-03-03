#include<cstdio>

int n, a[100002], pre[100002], suf[100002];

int abs(int a){ return a < 0 ? -a : a;}

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), pre[i] = pre[i-1] + abs(a[i] - a[i-1]);

	for(int i = n; i >= 1; --i) suf[i] = suf[i+1] + abs(a[i] - a[i+1]);

	for(int i = 1; i <= n; ++i) printf("%d\n", pre[i-1] + suf[i+1] + abs(a[i-1] - a[i+1]));

}