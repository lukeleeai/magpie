#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#define ll long long

using namespace std;

inline int read()

{

	int x = 0, f = 1; char ch = getchar();

	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}

	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}

	return x * f;

}

const int N = 1e6 + 1000;

int n,a[N];

ll tr[N];

ll A,P,Q;

int lowbit(int x){return x & -x;}

ll ask(int pos){ll res = 0; for(;pos;pos -= lowbit(pos)) res += tr[pos]; return res;}

void add(int pos,int v){for(;pos <= n;pos += lowbit(pos)) tr[pos] += v; return;}



int main()

{

	n = read(); for(int i = 1;i <= n;i ++) if((i & 1) != ((a[i] = read()) & 1)) {puts("No"); return 0;}

	for(int i = n;i >= 1;i --){A += ask(a[i]); add(a[i],1);}

	if(A % 3) {puts("No"); return 0;}

	for(int i = 1;i <= n;i ++) tr[i] = 0;

	for(int i = n;i >= 1;i -= 2){P += ask(a[i]); add(a[i],1);}

	for(int i = 1;i <= n;i ++) tr[i] = 0;

	for(int i = n - 1;i >= 1;i -= 2){Q += ask(a[i]); add(a[i],1);}

	if(P + Q != A / 3) {puts("No"); return 0;}

	else {puts("Yes"); return 0;}

}
