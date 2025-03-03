#include "algorithm"

#include "cstdio"

using namespace std;

int s[300005],i,j,n;long long ss;

int A(){

    int a=0,k=1;char c=getchar();

    while(c<'0'||c>'9'){

        if(c=='-') k=-1;c=getchar();

    }

    while(c>='0'&&c<='9'){

        a=a*10+c-'0';c=getchar();

    }

    return a*k;

}

bool cmp(int a,int b){

	return a>b;

}

int main(){

	n=A();

	for(i=1;i<=n*3;i++)s[i]=A();

	sort(s+1,s+1+3*n,cmp);

	for(i=1,j=3*n;i<=j;i+=2,j--){

		ss+=s[i+1];

	}

	printf("%lld\n",ss);

}