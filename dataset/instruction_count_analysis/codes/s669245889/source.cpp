#include<cstdio>

#include<cctype>

#include<algorithm>

using namespace std;

const int N=1e5;

int n,a[N+1];

int read()

{

	int ret=0;

	char c=getchar();

	while(!isdigit(c)) {

		c=getchar();

	}

	while(isdigit(c)) {

		ret=ret*10+c-'0';

		c=getchar();

	}

	return ret;

}

int main()

{

	n=read();

	for(int i=1;i<=n;++i) {

		a[i]=read();

	}

	sort(a+1,a+n+1,[](const int x,const int y) {

		return x>y;

	});

	int x=0;

	while((x<n)&&(x+1<=a[x+1])) {

		++x;

	}

	if(a[x]-x&1) {

		puts("First");

	} else {

		int y=x;

		while((y<n)&&(x<=a[y+1])) {

			++y;

		}

		puts((y-x)&1?"First":"Second");

	}

	return 0;

}
