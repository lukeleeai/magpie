/*

  mail: mleautomaton@foxmail.com

  author: MLEAutoMaton

  This Code is made by MLEAutoMaton

*/

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#include<algorithm>

#include<queue>

#include<set>

#include<map>

#include<iostream>

using namespace std;

#define ll long long

#define re register

#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

inline int gi(){

	int f=1,sum=0;char ch=getchar();

	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}

	return f*sum;

}

const int N=200010,M=20,Inf=2e9;

int n,a[N],cnt[M],ans,f[1<<M];

void chkmin(int &x,int y){x=min(x,y);}

int main(){

	n=gi();

	for(int i=1;i<n;i++){

		int u=gi()+1,v=gi()+1,w=gi();

		a[u]^=w;a[v]^=w;

	}

	int now=0;

	for(int i=1;i<=n;i++)cnt[a[i]]++;

	for(int i=1;i<=15;i++){ans+=cnt[i]/2;cnt[i]&=1;now+=cnt[i]<<(i-1);}

	memset(f,127,sizeof(f));f[now]=0;

	for(int i=(1<<15)-1;i;i--)

		if(f[i]<Inf)

			for(int j=1;j<=15;j++)

				if(i&(1<<j-1))

					for(int k=1;k<=15;k++)

						if(i&(1<<k-1) && j!=k){

							int x=j^k;

							if(i&(1<<x-1))chkmin(f[i-(1<<j-1)-(1<<k-1)-(1<<x-1)],f[i]+2);

							else chkmin(f[i-(1<<j-1)-(1<<k-1)+(1<<x-1)],f[i]+1);

						}

	printf("%d\n",f[0]+ans);

	return 0;

}
