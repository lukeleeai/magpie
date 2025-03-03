#include <stdio.h>

#include <string.h>

#define R register

#define MN 200005

typedef long long ll;

namespace IO{

	inline int read(){

		R int x; R bool f; R char c;

		for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');

		for (x=c^'0'; (c=getchar())>='0'&&c<='9'; x=(x<<1)+(x<<3)+(c^'0'));

		return f?-x:x;

	}

}

namespace sol{

	int n,v[MN]={-1};ll ans;

	void main(){

		n=IO::read();

		for (R int i=1; i<=n; ++i)

			if (v[i-1]+1<(v[i]=IO::read())) return (void)(puts("-1"));

		for (R int i=1; i<=n; ++i)

			if (v[i]>=v[i+1]||i==n) ans+=v[i];

		printf("%lld\n",ans);

	}

}

int main(){sol::main();return 0;}