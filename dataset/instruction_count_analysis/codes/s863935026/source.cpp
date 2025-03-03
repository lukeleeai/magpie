#include "stdc++.h"

using namespace std;

typedef long long ll;



template <typename _tp> inline void read(_tp&x){

	char ch=getchar(),ob=0;x=0;

	while(ch!='-'&&!isdigit(ch))ch=getchar();if(ch=='-')ob=1,ch=getchar();

	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(ob)x=-x;

}



const int N = 203, mod = 998244353;



struct pnt {

	int x, y;

	inline void in() {read(x), read(y);}

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

	read(n);

	bin[0] = 1;

	for(int i=1;i<=n;++i) bin[i] = (bin[i-1] << 1)%mod;

	for(int i=1;i<=n;++i) p[i].in();

	for(int i=1;i<n;++i) {

		for(int j=1;j<=n;++j) vs[j] = false;

		

		for(int j=i+1;j<=n;++j)

			if(!vs[j]) {

				bool flg = true;

				for(int k=1;k<i;++k)

					if(con(p[i], p[j], p[k]))

						flg = false;

				int ct = 2;

				for(int k=j+1;k<=n;++k)

					if(con(p[i], p[j], p[k]))

						vs[k] = true, ++ct;

				if(flg) Ans += bin[ct] - ct - 1;

			}

	}

	Ans = ((ll)mod*mod - Ans - n - 1 + bin[n])%mod;

	printf("%lld\n", Ans);

	return 0;

}