#include <cstdio>

#include <algorithm>

#include <ctime>

using namespace std;



#define int long long



int n,a,b,c,d;



inline int read(){

	int s=0,t=1;

	char c=getchar();

	while((c<'0'||c>'9')&&c!='-')c=getchar(),t=-1;

	if(c=='-')c=getchar(),t=-1;

	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();

	return s*t;

}



signed main(void){

	n=read();

	a=read();

	b=read();

	c=read();

	d=read();

	for(int i=1;i<n;i++){

		if(i*c-(n-1-i)*d<=b-a&&b-a<=i*d-(n-1-i)*c){

			printf("YES");

			return 0;

		}

	}

	printf("NO");

} 