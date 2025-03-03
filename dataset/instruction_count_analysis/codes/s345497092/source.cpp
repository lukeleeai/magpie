#include"stdc++.h"

using namespace std;

const int N=100010;

int n,m;

double ans=0,power[N];

int main()

{

	cin>>n>>m;

	double tmp=0.5;

	for(int i=1;i<=100000;++i)

	{

		power[i]=tmp;

		tmp/=2.0;

	}

	for(int i=1;i<=n;++i)

	{

		int cnt=0,now=i;

		while(now<m)now*=2,++cnt;

		if(!cnt)ans+=1.0/n;

		else ans+=1.0/n*power[cnt];

	}

	printf("%.12lf\n",ans);

}