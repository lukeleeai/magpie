#include<stdio.h>

int x,y,z,s,ans;

template<typename TYPE>

inline void read(TYPE&x){

	x=0;int w=1;register char c=getchar();for(;c<'0'||c>'9';c=getchar()) if (c=='-') w=-1;

	for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=getchar());x*=w;

}

int main(){

	read(x);read(y);read(z);

	for(;s+z<=x;s=s+z+y) ans++;

	return printf("%d\n",--ans),0;

}