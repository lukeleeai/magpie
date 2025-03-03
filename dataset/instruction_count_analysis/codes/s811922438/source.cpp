#include <cstdio>

typedef long long ll;



const int N = 203, mod = 998244353;



struct pnt {

	int x, y;

	inline void in() {scanf("%d%d", &x, &y);}

	friend inline pnt operator - (const pnt&A, const pnt&B) {return (pnt) {A.x - B.x, A.y - B.y};}

	friend inline int operator * (const pnt&A, const pnt&B) {return A.x * B.y - A.y * B.x;}

} p[N];



inline bool con(const pnt&A, const pnt&B, const pnt&C) {

	return (C - A) * (B - A) == 0;

}



int n;

int bin[N];

bool vs[N];

ll Ans;



int main() {

	scanf("%d", &n);

	for(int i=bin[0]=1;i<=n;++i) bin[i] = (bin[i-1] << 1)%mod;

	for(int i=1;i<=n;++i) p[i].in();

	for(int i=1;i<n;++i) {

		for(int j=1;j<=n;++j) vs[j] = false;

		

		for(int j=i+1;j<=n;++j)

			if(!vs[j]) {

				int ct = 2;

				for(int k=j+1;k<=n;++k)

					if(con(p[i], p[j], p[k])) vs[k] = true, ++ct;

				

				bool flg = true;

				for(int k=1;k<i and flg;++k)

					if(con(p[i], p[j], p[k])) flg = false;

				if(flg) Ans += bin[ct] - ct - 1;

			}

	}

	Ans = ((ll)mod*mod - Ans - n - 1 + bin[n])%mod;

	printf("%lld\n", Ans);

	return 0;

}