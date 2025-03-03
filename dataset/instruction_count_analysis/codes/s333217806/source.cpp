#include"stdc++.h"

using namespace std;

#define MN 200005

#define LL long long

#define mp make_pair

#define fir first

#define sec second

#define pii pair<int,int>

inline void chkmax(int &a,int b){if(a<b)a=b;}

inline void chkmin(int &a,int b){if(a>b)a=b;}

inline int read(){

	   int a=0,fh=1;char c=getchar();

	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}

	   while('0'<=c&&c<='9'){

		   a=a*10+c-48;

		   c=getchar();

	   }

	   return a*fh;

}

LL n,a[MN],f[MN][3];

int main(){

	n=read();

	for(int i=1;i<=n;++i){

		a[i]=read();

	}

	if(n%2==0){

		LL tmp=0,tmp1=0;

		for(int i=2;i<=n;i+=2)tmp+=a[i];

		for(int i=1;i<=n;i+=2)tmp1+=a[i];

		tmp=max(tmp,tmp1);

		memset(f,-0x3f,sizeof(f));

		f[1][0]=a[1];f[1][1]=0;

		f[0][0]=0;

		f[2][1]=a[2];f[2][2]=0;

		for(int i=3;i<=n;++i){

			f[i][0]=f[i-2][0]+a[i];

			f[i][1]=f[i-3][0]+a[i];

			f[i][1]=max(f[i][1],f[i-2][1]+a[i]);

			f[i][2]=max(f[i-2][2]+a[i],f[i-3][1]+a[i]);

		}

		printf("%lld\n",max(f[n][1],max(f[n][0],tmp)));

	}

	else{

		LL tmp=0;

		for(int i=2;i<=n;i+=2)tmp+=a[i];

		memset(f,-0x3f,sizeof(f));

		f[1][0]=a[1];f[1][1]=0;

		f[0][0]=0;

		f[2][1]=a[2];f[2][2]=0;

		for(int i=3;i<=n;++i){

			f[i][0]=f[i-2][0]+a[i];

			f[i][1]=f[i-3][0]+a[i];

			f[i][1]=max(f[i][1],f[i-2][1]+a[i]);

			f[i][2]=max(f[i-2][2]+a[i],f[i-3][1]+a[i]);

		}

		tmp=max(tmp,f[n-1][1]);tmp=max(tmp,f[n-1][0]);

		printf("%lld\n",max(f[n][1],max(tmp,f[n][2])));

	}

	return 0;

}