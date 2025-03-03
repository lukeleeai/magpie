#include<cstdio>

#define N 110000

inline char gc(){

	static char now[1<<16],*T,*S;

	if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}

	return *S++;

}

inline int read(){

	int x=0;char ch=gc();

	while (ch<'0'||ch>'9') ch=gc();

	while (ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=gc();}

	return x;

}

int n,a[N],differ[N];

int main(){

	//freopen("box.in","r",stdin);

	n=read();long long sum=0;long long sum1=0;

	if (n==1){printf("YES");return 0;}

	sum1=(long long)n*(n+1)>>1;

	for (int i=1;i<=n;++i) a[i]=read(),sum+=a[i];a[n+1]=a[1];

	for (int i=1;i<=n;++i) differ[i]=a[i+1]-a[i];int k=sum/sum1;

	if (sum%sum1){printf("NO");return 0;}

	for (int i=1;i<=n;++i){

		double x=(differ[i]-k)/(-1.0*n);

		if (x<0){printf("NO");return 0;}

		int xx=x;if (xx!=x){printf("NO");return 0;}

	}

	printf("YES");

	return 0;

}