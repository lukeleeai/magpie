#include"stdc++.h"

using namespace std;

const int maxn = 1e6+5;

const long long mod = 1e9+7;

long long Sort[maxn];

long long ans[maxn];

int dir[9][2]={-2,-2,-2,-1,-2,0,-1,-2,-1,-1,-1,0,0,-2,0,-1,0,0};

int tot;

int main()

{

	long long H,W,N;

	scanf("%lld%lld%lld",&H,&W,&N);

	long long Ans=(long long)(H-2)*(long long)(W-2);

	for(int i=0;i<N;i++)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		for(int j=0;j<9;j++)

		{

			int xx=x+dir[j][0];

			int yy=y+dir[j][1];

			if(xx>=1 && xx<=H-2 &&yy>=1 && yy<=W-2)

			{

				Sort[tot++] = xx * mod + yy;

			}

		}

	}

	sort(Sort,Sort+tot);

	int cnt=1;

	for(int i=0;i<tot;i++)

	{

		if(Sort[i]==Sort[i+1])

			cnt++;

		else

		{

			ans[cnt]++;

			cnt=1;

			Ans--;

		}

	}

	printf("%lld",Ans);

	for(int i=1;i<10;i++)

		printf(" %lld",ans[i]);

	printf("\n");

	

	

	return 0;

}