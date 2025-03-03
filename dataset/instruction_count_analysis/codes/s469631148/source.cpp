#include"stdc++.h"

using namespace std;

#define mp(a,b) make_pair(a,b)

#define fi first

#define se second



priority_queue<pair<int,int> > LL,RR,L,R;

bool vis[100005];

long long ans1,ans2;

int n;



void PlanA(int now,long long &ans)

{

	while (!L.empty() && vis[L.top().se]) L.pop();

	while (!R.empty() && vis[R.top().se]) R.pop();

	if (!L.empty() && L.top().fi>now)

	{

		ans+=L.top().fi-now;

		now=L.top().fi;

		vis[L.top().se]=1;

		L.pop();

		PlanA(now,ans);

	}

	else if (!R.empty() && -R.top().fi<now)

	{

		ans+=now+R.top().fi;

		now=-R.top().fi;

		vis[R.top().se]=1;

		R.pop();

		PlanA(now,ans);

	}

	else ans+=abs(now);

}



void PlanB(int now,long long &ans)

{

	while (!L.empty() && vis[L.top().se]) L.pop();

	while (!R.empty() && vis[R.top().se]) R.pop();

	if (!R.empty() && -R.top().fi<now)

	{

		ans+=now+R.top().fi;

		now=-R.top().fi;

		vis[R.top().se]=1;

		R.pop();

		PlanB(now,ans);

	}

	else if (!L.empty() && L.top().fi>now)

	{

		ans+=L.top().fi-now;

		now=L.top().fi;

		vis[L.top().se]=1;

		L.pop();

		PlanB(now,ans);

	}

	else ans+=abs(now);

}



int main()

{

	scanf("%d",&n);

	for (int i=1,l,r;i<=n;i++)

	{

		scanf("%d%d",&l,&r);

		LL.push(mp(l,i));

		RR.push(mp(-r,i));

	}

	L=LL,R=RR;

	PlanA(0,ans1);

	memset(vis,0,sizeof(vis));

	L=LL,R=RR;

	PlanB(0,ans2);

	printf("%lld\n",max(ans1,ans2));

}