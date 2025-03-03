#include <algorithm>

#include <iostream>

#include <cstring>

#include <cstdio>

const int N = 3e5 + 5; 

typedef long long ll;

const ll INF = 1e16; 

using namespace std;



int n, m, stk[N], top; 

ll s[N], f[N], g[N], t[N], *dp; 



template < typename T >

inline T read()

{

	T x = 0, w = 1; char c = getchar();

	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }

	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();

	return x * w; 

}



double X(int j) { return j; }

double Y(int j) { return dp[j] + ((ll)j * j - j) / 2 + s[j]; }

double slope(int i,int j) { return (Y(i) - Y(j)) / (X(i) - X(j)); }

ll calc(int i,int j) { return dp[j] + ((ll)(i - j + 1) * (i - j)) / 2 - (s[i] - s[j]); }

void DP()

{

	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + t[i];

	stk[top = 1] = 0;

	for(int i = 1;i <= n;i++)

	{

		while(top > 1 && calc(i,stk[top]) <= calc(i,stk[top - 1])) top--; 

		dp[i] = max(calc(i,stk[top]),dp[i - 1]); 

		while(top > 1 && slope(stk[top - 1],i) >= slope(stk[top],stk[top - 1])) top--;

		stk[++top] = i;

	}

}



double X1(int j) { return j; }

double Y1(int j) { return f[j] + s[j] + ((ll)j * j - j) / 2; }

double slope1(int i,int j) { return (Y1(i) - Y1(j)) / (X1(i) - X1(j)); }

ll calc1(int i,int j)

{ return g[i + 1] + ((ll)(i - j) * (i - j + 1)) / 2 - (s[i] - s[j]) + f[j]; }



double X2(int j) { return j; }

double Y2(int j) { return g[j + 1] + ((ll)j * j + j) / 2 - s[j]; }

double slope2(int i,int j) { return (Y2(i) - Y2(j)) / (X2(i) - X2(j)); }

ll calc2(int i,int j)

{ return f[i] + ((ll)(j - i) * (j - i + 1)) / 2 - (s[j] - s[i]) + g[j + 1]; }



ll h[N];



void solve(int l,int r)

{

	if(l == r) { h[l] = 1 - t[l];return; }

	int mid = l + r >> 1;solve(l,mid),solve(mid + 1,r);

	top = 0;

	for(int i = l - 1;i < mid;i++)

	{

		while(top > 1 && slope1(i,stk[top - 1]) >= slope1(stk[top],stk[top - 1])) top--;

		stk[++top] = i;

	}int head = 1;ll maxx = -INF;

	for(int i = r;i > mid;i--)

	{

		while(head < top && calc1(i,stk[head]) <= calc1(i,stk[head + 1])) head++;

		maxx = max(maxx,calc1(i,stk[head]));

		h[i] = max(h[i],maxx);

	}top = 0;

	for(int i = mid + 1;i <= r;i++)

	{

		while(top > 1 && slope2(i,stk[top - 1]) >= slope2(stk[top],stk[top - 1])) top--;

		stk[++top] = i;

	}maxx = -INF;

	for(int i = l - 1;i < mid;i++)

	{

		while(top > 1 && calc2(i,stk[top]) <= calc2(i,stk[top - 1])) top--;

		maxx = max(maxx,calc2(i,stk[top]));

		h[i + 1] = max(h[i + 1],maxx);

	}

}



/*

void solve(int l, int r)

{

	if(l == r) return (void) (h[l] = max(h[l], 1ll - t[l])); 

	int mid = (l + r) >> 1; 

	solve(l, mid), solve(mid + 1, r), top = 0; 

	for(int i = l - 1; i < mid; i++)

	{

		while(top > 1 && slope1(stk[top - 1], stk[top]) <= slope1(stk[top - 1], i)) top--; 

		stk[++top] = i; 

	}

	ll mx = -INF, hd = 1; 

	for(int j, i = r; i > mid; i--)

	{

		while(hd < top && calc1(i, stk[hd]) <= calc1(i, stk[hd + 1])) hd++; 

		j = stk[hd], mx = max(mx, calc1(i, j)); 

		h[i] = max(h[i], mx); 

	}

	top = 0;

	for(int i = mid + 1; i <= r; i++)

	{

		while(top > 1 && slope2(stk[top - 1], stk[top]) <= slope2(stk[top - 1], i)) top--;

		stk[++top] = i; 

	}

	mx = -INF; 

	for(int j, i = l - 1; i < mid; i++)

	{

		while(top > 1 && calc2(i, stk[top]) <= calc2(i, stk[top - 1])) top--;

		j = stk[top], mx = max(mx, calc2(i, j));		

		h[i + 1] = max(h[i + 1], mx); 

	}

}

*/

int main()

{

	n = read <int> (); 

	for(int i = 1; i <= n; i++) t[i] = read <int> (); 

	dp = f, DP(), reverse(t + 1, t + n + 1), dp = g, DP(); 

	reverse(t + 1, t + n + 1), reverse(g + 1, g + n + 1); 

	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + t[i]; 

	solve(1, n), m = read <int> (); 

	for(int pos, v, i = 1; i <= m; i++)

	{

		pos = read <int> (), v = read <int> ();

		printf("%lld\n", max(f[pos - 1] + g[pos + 1], h[pos] + t[pos] - v)); 

	}

	return 0; 

}