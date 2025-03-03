#include "stdc++.h"

#define il inline

#define rg register

using namespace std;

typedef long long LL;

const LL m_63=1061109567;

const LL m_127=2139062143;

const int inf=2147483647;

const double pi=atan(1.0)*4.0;

const LL llf=9223372036854775807;

const LL N=1e6+7;

const int M=1e6;

int n,d[N],flag[N];

int num,b[N],w[N],p[N],nt[N];

il LL read(){

    LL x(0),ff(1);char ch=getchar();

    while(ch<'0'||ch>'9'){

        if(ch=='-')ff=-1;

        ch=getchar();

    }

    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();

    return x*ff;

}

il void fre(){

	freopen("6.in","r",stdin);

//	freopen("magic.out","w",stdout);

}

il void spfa(){

	queue<int>q;

	memset(d,127,sizeof(d));

	memset(flag,0,sizeof(flag));

	q.push(1);d[1]=0;

	while(!q.empty()){

		int k=q.front();q.pop();

		int e=p[k];flag[k]=0;

		while(e){

			int kk=b[e];

			if(d[kk]>d[k]+w[e]){

				d[kk]=d[k]+w[e];

				if(!flag[kk]){

					flag[kk]=1;

					q.push(kk);

				}

			}

			e=nt[e];

		}

	}

}

il void add(int x,int y,int z){b[++num]=y,w[num]=z,nt[num]=p[x],p[x]=num;}

int main(){

//	fre();

//	cout<<sum(112)<<endl;return 0;

//https://www.luogu.org/problemnew/solution/AT3621

//https://blog.csdn.net/winter2121/article/details/81393967

//Ã¿Ò»¸öÊý¶¼¿ÉÒÔÓÉ1Í¨¹ýÒÔÏÂÁ½ÖÖÊµÏÖ

//*10 Î»ÊýºÍ²»±ä

//+1 Î»ÊýºÍ+1

//	n=read();

//	for(rg int i=1;i<=n;++i){

		int k=read();

		for(rg int j=0;j<k;++j){

			add(j,(j+1)%k,1);

			add(j,(j*10)%k,0);

//			cout<<i<<' '<<(i+1)%k<<" 1"<<endl;

//			cout<<i<<' '<<(i*10)%k<<" 0"<<endl;

		}

		spfa();

		printf("%d\n",d[0]+1);

//		memset(p,0,sizeof(p));num=0;

//	}

	return 0;

}

/*

5 6 10

1 2 4

1 4 1

4 3 1

2 5 1

4 5 2

3 2 1

1

3

1

2 2



*/