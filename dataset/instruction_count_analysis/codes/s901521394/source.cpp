#include<algorithm>

#include<cstdio>

using namespace std;

inline void in(int &s){

	s=0;char c=getchar();

	while(c<'0' || c>'9'){

		c=getchar();

	}

	while(c>='0' && c<='9'){

		s=(s<<1)+(s<<3)+c-'0';

		c=getchar();

	}

}

int n,m,z,ans;

long long sum;

bool ok=1;

struct xx{

	int a,b;

}s[200002];

int cmp(xx x,xx y){

	return x.a>y.a;

}

int main(){

	in(n);in(m);

	for(int i=0;i<n;++i){

		in(s[z++].a);s[z].b=1;in(s[z++].a);

	}

	sort(s,s+z,cmp);

	for(int i=0;i<z;++i){

		if(s[i].b){

			m-=s[i].a;++ans;

		}

		else{

			if(m%s[i].a==0) ans+=m/s[i].a;

			else ans+=m/s[i].a+1;

			printf("%d\n",ans);break;

		}

		if(m<1){

			printf("%d\n",ans);break;

		}

	}

	return 0;

}