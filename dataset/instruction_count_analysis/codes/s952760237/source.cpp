#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 300000

#define INF 1000000000000000000LL

using namespace std;

typedef long long LL;

int N;

LL T[MAXN+5],sum[MAXN+5];

LL L[MAXN+5],R[MAXN+5];

int que[MAXN+5];

LL f[MAXN+5],h[MAXN+5],g[MAXN+5],ans[MAXN+5];

LL GetY(int j)

{

	return 1LL*f[j]+(1LL*j*j-1LL*j)/2LL+sum[j];

}

void Rev(LL seq[])

{

	for(int i=1;i<=N/2;i++)

		swap(seq[i],seq[N-i+1]);

}

void DP()

{

	int s=0,t=0;

	que[t++]=0;

	fill(f+1,f+1+N,-INF);

	for(int i=1;i<=N;i++)

	{

		while(s<t-1)

		{

			int j1=que[t-2],j2=que[t-1];

			LL y1=GetY(j1),y2=GetY(j2);

			if((y1-y2)>1LL*i*(1LL*j1-1LL*j2))

				t--;

			else

				break;

		}

		int j=que[t-1];

		f[i]=f[j]+((1LL*i-1LL*j)*(1LL*i-1LL*j+1LL))/2LL-(1LL*sum[i]-1LL*sum[j]);

		f[i]=max(f[i],f[i-1]);

		while(s<t-1)

		{

			int j1=que[t-2],j2=que[t-1];

			LL y1=GetY(que[t-2]),y2=GetY(que[t-1]),y3=GetY(i);

			if((1LL*y1-1LL*y2)*(1LL*j2-1LL*i)<(1LL*y2-1LL*y3)*(1LL*j1-1LL*j2))

				que[--t]=0;

			else

				break;

		}

		que[t++]=i;

	}

}

void MergeSort(int l,int r)

{

	if(l==r)

	{

		if(l!=0)

			g[l]=max(g[l],L[l-1]+R[l+1]+1LL-(sum[l]-sum[l-1]));

		else

			g[l]=0;

		return;

	}

	int mid=(l+r)/2;

	MergeSort(l,mid);

	int s=0,t=0;

	for(int i=l;i<=mid;i++)

	{

		f[i]=L[i];

		while(s<t-1)

		{

			int j1=que[t-2],j2=que[t-1];

			LL y1=GetY(que[t-2]),y2=GetY(que[t-1]),y3=GetY(i);

			if((1LL*y1-1LL*y2)*(1LL*j2-1LL*i)<(1LL*y2-1LL*y3)*(1LL*j1-1LL*j2))

				que[--t]=0;

			else

				break;

		}

		que[t++]=i;

	}

	for(int i=mid+1;i<=r;i++)

	{

		while(s<t-1)

		{

			int j1=que[t-2],j2=que[t-1];

			LL y1=GetY(j1),y2=GetY(j2);

			if((y1-y2)>1LL*i*(1LL*j1-1LL*j2))

				t--;

			else

				break;

		}

		int j=que[t-1];

		h[i]=f[j]+((1LL*i-1LL*j)*(1LL*i-1LL*j+1LL))/2LL-(1LL*sum[i]-1LL*sum[j])+R[i+1];

	}

	for(int i=r-1;i>=mid+1;i--)

		h[i]=max(h[i],h[i+1]);

	for(int i=mid+1;i<=r;i++)

		g[i]=max(g[i],h[i]);

	MergeSort(mid+1,r);

}

int main()

{

	fill(ans+1,ans+1+MAXN,-INF);

	scanf("%d",&N);

	for(int i=1;i<=N;i++)

		scanf("%lld",&T[i]);

	for(int i=1;i<=N;i++)

		sum[i]=sum[i-1]+T[i];

	//处理初始DP

	//处理前缀DP数组 

	DP();

	for(int i=1;i<=N;i++)

		L[i]=f[i];

	//处理后缀DP数组 

	Rev(T);

	for(int i=1;i<=N;i++)

		sum[i]=sum[i-1]+T[i];

	DP();

	for(int i=1;i<=N;i++)

		R[i]=f[N-i+1];

	Rev(T);

	for(int i=1;i<=N;i++)

		sum[i]=sum[i-1]+T[i];

	//处理完成 

	//开始CDQ分治(计算必须选择某个元素的最大值)

	//先从左往右算贡献

	fill(f+1,f+1+N,-INF);

	fill(h+1,h+1+N,-INF);

	fill(g+1,g+1+N,-INF);

	MergeSort(0,N);

	for(int i=1;i<=N;i++)

		ans[i]=max(ans[i],g[i]);

	//再从右往左算贡献 

	Rev(T);

	for(int i=1;i<=N;i++)

		sum[i]=sum[i-1]+T[i];

	for(int i=1;i<=N;i++)

		swap(L[i],R[N-i+1]);

	fill(f+1,f+1+N,-INF);

	fill(h+1,h+1+N,-INF);

	fill(g+1,g+1+N,-INF);

	MergeSort(0,N);

	for(int i=1;i<=N;i++)

		ans[i]=max(ans[i],g[N-i+1]);

	Rev(T);

	for(int i=1;i<=N;i++)

		sum[i]=sum[i-1]+T[i];

	for(int i=1;i<=N;i++)

		swap(L[i],R[N-i+1]);

	//预处理完成 

	//开始回答询问

	int M,P;

	LL X;

	scanf("%d",&M);

	for(int i=1;i<=M;i++)

	{

		scanf("%d %lld",&P,&X);

		LL ansn=max(L[P-1]+R[P+1],ans[P]-X+T[P]);

		printf("%lld\n",ansn);

	}

	return 0;

}

/*

4

3 5 1 6

5

2 1

4 2

3 1

1 1



*/