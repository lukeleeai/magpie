#include "stdc++.h"

using namespace std; 

const int N = 300010;

typedef long long ll; 

const ll LINF = 1e16; 

int n,m;

ll t[N],sum[N];

ll f[N],g[N],*dp;

int st[N],top;

int read()

{

	int x = 0, w = 1; char c = getchar(); 

	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }

	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar(); 

	return x * w; 

}

double X(int j) { return j; }

double Y(int j) { return dp[j] + ((ll)j * j - j) / 2 + sum[j]; }

double slope(int i,int j) { return (Y(i) - Y(j)) / (X(i) - X(j)); }

ll calc(int i,int j) { return dp[j] + ((ll)(i - j + 1) * (i - j)) / 2 - (sum[i] - sum[j]); }

void DP()

{

	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + t[i];

	st[top = 1] = 0;

	for(int i = 1;i <= n;i++)

	{

		while(top > 1 && calc(i,st[top]) <= calc(i,st[top - 1])) top--; 

		dp[i] = max(calc(i,st[top]),dp[i - 1]); 

		while(top > 1 && slope(st[top - 1],i) >= slope(st[top],st[top - 1])) top--;

		st[++top] = i;

	}

}



double X1(int j) { return j; }

double Y1(int j) { return f[j] + sum[j] + ((ll)j * j - j) / 2; }

double slope1(int i,int j) { return (Y1(i) - Y1(j)) / (X1(i) - X1(j)); }

ll calc1(int i,int j)

{ return g[i + 1] + ((ll)(i - j) * (i - j + 1)) / 2 - (sum[i] - sum[j]) + f[j]; }



double X2(int j) { return j; }

double Y2(int j) { return g[j + 1] + ((ll)j * j + j) / 2 - sum[j]; }

double slope2(int i,int j) { return (Y2(i) - Y2(j)) / (X2(i) - X2(j)); }

ll calc2(int i,int j)

{ return f[i] + ((ll)(j - i) * (j - i + 1)) / 2 - (sum[j] - sum[i]) + g[j + 1]; }



ll h[N];

void solve(int l,int r)

{

	if(l == r) { h[l] = 1 - t[l];return; }

	int mid = l + r >> 1;solve(l,mid),solve(mid + 1,r);

	top = 0;

	for(int i = l - 1;i < mid;i++)

	{

		while(top > 1 && slope1(i,st[top - 1]) >= slope1(st[top],st[top - 1])) top--;

		st[++top] = i;

	}int head = 1;ll maxx = -LINF;

	for(int i = r;i > mid;i--)

	{

		while(head < top && calc1(i,st[head]) <= calc1(i,st[head + 1])) head++;

		maxx = max(maxx,calc1(i,st[head]));

		h[i] = max(h[i],maxx);

	}top = 0;

	for(int i = mid + 1;i <= r;i++)

	{

		while(top > 1 && slope2(i,st[top - 1]) >= slope2(st[top],st[top - 1])) top--;

		st[++top] = i;

	}maxx = -LINF;

	for(int i = l - 1;i < mid;i++)

	{

		while(top > 1 && calc2(i,st[top]) <= calc2(i,st[top - 1])) top--;

		maxx = max(maxx,calc2(i,st[top]));

		h[i + 1] = max(h[i + 1],maxx);

	}

}

int main()

{

	n = read();for(int i = 1;i <= n;i++) t[i] = read();

	dp = f,DP();

	reverse(t + 1,t + 1 + n),dp = g,DP();

	reverse(t + 1,t + 1 + n),reverse(g + 1,g + 1 + n); 

	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + t[i];

	solve(1,n);m = read();

	while(m--)

	{

		int x = read(), y = read();

		printf("%lld\n", max(f[x - 1] + g[x + 1],h[x] + t[x] - y));

	}

	return 0;

}