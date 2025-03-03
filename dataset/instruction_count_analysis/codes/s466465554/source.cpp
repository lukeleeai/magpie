// Code by wty

#include "stdc++.h"





using namespace std;



const int N = 2e5 + 7;

const int Inf = 0x3f3f3f3f;

struct Pair{

	int l,r;

	bool operator < (const Pair& t)const{

		return l == t.l ? r < t.r : l < t.l;

	}

}p[N];

inline int Read(int x = 0,char ch = 0){

	while(!isdigit(ch = getchar()));

	x = ch - 48;

	while(isdigit(ch = getchar()))x = x * 10 + ch - 48;

	return x;

}

int n,m;

int b[N];

int f[N];

int sum[N];

struct Node{

	int f,s;

	Node(){f = s = -Inf;}

}st[N << 2];

#define ls (rt << 1)

#define rs (rt << 1 | 1)

#define Mid (L + R >> 1)

void Insert(int x,int f,int s,int L = 0,int R = n,int rt = 1){

	if(st[rt].f < f)st[rt].f = f;

	if(st[rt].s < s)st[rt].s = s;

	if(L == R)return;

	if(x <= Mid)Insert(x,f,s,L,Mid,ls);

	else Insert(x,f,s,Mid + 1,R,rs);

}

int tmp;

void Qmaxf(int l,int r,int L = 0,int R = n,int rt = 1){

	if(tmp >= st[rt].f)return;

	if(l <= L && r >= R)return tmp = st[rt].f,void();

	if(l <= Mid)Qmaxf(l,r,L,Mid,ls);

	if(r >  Mid)Qmaxf(l,r,Mid + 1,R,rs);

}

void Qmaxs(int l,int r,int L = 0,int R = n,int rt = 1){

	if(tmp >= st[rt].s)return;

	if(l <= L && r >= R)return tmp = st[rt].s,void();

	if(l <= Mid)Qmaxs(l,r,L,Mid,ls);

	if(r >  Mid)Qmaxs(l,r,Mid + 1,R,rs);

}

inline int Calc(int x){

	return 2 * sum[x] - x;

}

int main(){

#ifdef WTY

	freopen("in","r",stdin);

#endif

	cin >> n;

	for(int i = 1; i <= n; i++)b[i] = Read(),sum[i] = sum[i - 1] + !b[i];

	memset(f,0xcf,sizeof f);

	f[0] = sum[n];

	Insert(0,f[0],f[0] + Calc(0));

	cin >> m;

	for(int i = 1; i <= m; i++)

		p[i].l = Read(),p[i].r = Read();

	sort(p + 1,p + 1 + m);

	int ans = f[0];

	for(int i = 1; i <= m; i++){

		int asd = INT_MIN,k = p[i].l - 1;

		tmp = INT_MIN;

		Qmaxf(0,p[i].l - 1);

		asd = tmp + 2 * sum[k] - k;

		tmp = INT_MIN;

		Qmaxs(p[i].l,p[i].r);

		asd = max(asd,tmp) + p[i].r - 2 * sum[p[i].r];

		Insert(p[i].r,asd,asd + Calc(p[i].r));

		ans = max(ans,asd);

/*		for(int j = 0,t; j <= p[i].r; j++){

			int k = max(j,p[i].l - 1);

			if(asd < (t = f[j] + (p[i].r - k - 2 * (sum[p[i].r] - sum[k]))))asd = t;

		}

		f[p[i].r] = asd;*/

	}

	cout << n - ans << endl;



	return 0;

}