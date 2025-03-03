#include <cstdio>

#include <cstring>

#include <algorithm>

#define R register

using namespace std;

const int MAXN=100100;

char s1[MAXN],s2[MAXN];

int pr1[MAXN][2],pr2[MAXN][2];



template<class T>void read(T &x)

{

	x=0;int ff=0;char ch=getchar();

	while(ch<'0'||ch>'9'){ff|=(ch=='-');ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}

	x=ff?-x:x;

}



int reads(char *st)

{

	int len=0;char ch=getchar();

	while(ch<'A'||ch>'B')ch=getchar();

	while(ch>='A'&&ch<='B')st[++len]=ch,ch=getchar();

	return len;

}



int main()

{

	int n1,n2;

	n1=reads(s1),n2=reads(s2);

	for(R int i=1;i<=n1;++i)

	{

		pr1[i][0]=pr1[i-1][0];

		pr1[i][1]=pr1[i-1][1];

		if(s1[i]=='A')++pr1[i][0];

		else ++pr1[i][1];

	}

	for(R int i=1;i<=n2;++i)

	{

		pr2[i][0]=pr2[i-1][0];

		pr2[i][1]=pr2[i-1][1];

		if(s2[i]=='A')++pr2[i][0];

		else ++pr2[i][1];

	}

	int m;

	read(m);

	int t1,t2,t3,t4;

	for(R int i=1;i<=m;++i)

	{

		read(t1),read(t2),read(t3),read(t4);

		int d1=(pr1[t2][0]-pr1[t1-1][0])-(pr1[t2][1]-pr1[t1-1][1]);

		int d2=(pr2[t4][0]-pr2[t3-1][0])-(pr2[t4][1]-pr2[t3-1][1]);

		int d=d1-d2;

		if(d<0)d=-d;

		if(d%3==0)puts("YES");

		else puts("NO");

	}

	return 0;

}