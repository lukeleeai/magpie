#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>

#define RG register

using namespace std;

const int N=1e5+10;

int n,m,num[N],ans,cnt[N],bck[N],cs[N],maxx[N];

inline int read(){

	char ch=getchar(); int x=0, f=1;

	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}

	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}

	return x*f;}

inline bool cmp(int a,int b){return a%m<b%m;}

inline int mx(int a,int b){return a>b ? a : b ;}

inline int mi(int a,int b){return a<b ? a : b ;}

int main()

{

//	freopen("Pair Cards.in","r",stdin);

	//freopen(".out","w",stdout);

	n=read(); m=read();

	for(int i=1;i<=n;i++) 

	{

		num[i]=read();//%m;

		cnt[num[i]%m]++;

		bck[num[i]]++;

	}

	ans+=cnt[0]/2;//printf("%d\n",ans);

	for(int i=1;i<m;i++)

	{

		if(i==m-i) 

		{

			ans+=cnt[i]/2;

			cnt[i]=1;

			continue;

		}

		int minn=mi(cnt[i],cnt[m-i]);

		ans+=minn;

		cnt[i]-=minn; cnt[m-i]-=minn;

	}

	for(int i=1;i<m;i++)

	{

		cnt[i]/=2;

		for(int j=i;j<=100000 && cnt[i]>0;j+=m)

		{

			ans+=mi(cnt[i], bck[j]/2);

			cnt[i]-=bck[j]/2;

		}

	}

	printf("%d\n",ans);

	//fclose(stdin); fclose(stdout);

	return 0;

}