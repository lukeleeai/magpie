#include <cstdio>

using namespace std;

#define FOR(i,a,n) for(int i=a;i<(n);++i)

inline void read(int &x){

	x=0;char ch=getchar();

	while(ch<'0')ch=getchar();

	while(ch>='0'){

		x=x*10+ch-48;

		ch=getchar();

	}

}

const int N=1e5;

int x[N];

int main(){

	int n,a,b;read(n);read(a);read(b);

	long ans=0;

	read(x[0]);

	FOR(i,1,n){

		read(x[i]);

		ans+=((long)a*(x[i]-x[i-1])>b)?b:(long)a*(x[i]-x[i-1]);

	}

	printf("%ld\n",ans);

    return 0;

}
