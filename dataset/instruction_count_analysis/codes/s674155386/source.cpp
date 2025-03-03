#include <cstdio>

#include <algorithm>

using namespace std;

#define ri register int

typedef long long ll;

const int N=2000005,MAXBUF=5000005;

int n,m,a[N],b[N];

namespace io {

	const int SIZE = (1 << 21) + 1;

	char ibuf[SIZE], *iS, *iT, c;

	// getchar

	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)

	// input a signed integer

	template <class I>

	inline void gi (I &x) {

		for (c = gc(); c < '0' || c > '9'; c = gc()) ;

		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = (x << 1) + (x << 3) + (c & 15);

	}

}

using io :: gi;

inline int calc(ri mid){

	ri i,x,y;

	for(i=1;i<=n;++i) b[i]=a[i]<mid?0:1;

	for(x=m-1;x&&b[x]^b[x+1];--x);

	for(y=m+1;y<=n&&b[y]^b[y-1];++y);

	return !x&&y>n?b[1]:(m-x+1<y-m+1?b[x]:b[y]);

}

int main(){

	ri l,r,mid,i;

	gi(n);

	m=n;

	n=(n<<1)-1;

	for(i=1;i<=n;i++) gi(a[i]);

	l=1;r=n;

	while(l<=r) calc(mid=l+r>>1)?l=mid+1:r=mid-1;

	printf("%d",l-1);

	return 0;

}