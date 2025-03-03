#include"stdc++.h"

#define inf 0x7fffffff

#define RG register

#define maxn 500005

#define maxm 205

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

inline ll read(){

    ll x = 0, f = 1;

    char ch = getchar();

    while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}

    return x * f;

}

 

int n, k, ans;

int a[10005], tp;

bitset<5005> f, w;

int main(){

	int i, j, x, l, r, mid;

	n = read(), k = read();

	for(i = 1;i <= n;i++){

		 a[++tp] = read();

		 if(a[tp] >= k) tp--;

	}

	sort(a + 1, a + tp + 1);

	l = 1, r = tp; 

	for(i = tp + 1;i <= 2 * tp;i++) a[i] = a[i - tp];

	while(l <= r){

		f = w, f[0] = 1;

		mid = l + r >> 1;

		for(j = mid + 1;j <= mid + tp - 1;j++) 

			f |= f << a[j];

		bool flag = 0;

		for(j = k - a[mid];j < k;j++) if(f[j]) {flag = 1;break;}

		if(!flag) ans = mid, l = mid + 1; 

		else r = mid - 1;

	}

	printf("%d\n", ans);

	return 0;

}