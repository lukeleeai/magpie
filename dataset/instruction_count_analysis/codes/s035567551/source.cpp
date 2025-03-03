#include "cstdio"

#include "algorithm"

using namespace std;

int s[100005],i,j,n,k,c,ss;

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

int main(){

	n=A(),c=A(),k=A();

	for(i=1;i<=n;i++)

	s[i]=A();

	sort(s+1,s+1+n);

	for(i=1;i<=n;i++){

		for(j=i;j<=n&&j<=i+c-1&&s[j]<=s[i]+k;j++);i=j-1;

		ss++;

	}

	printf("%d\n",ss);

}