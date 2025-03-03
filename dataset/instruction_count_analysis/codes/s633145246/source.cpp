#include"stdc++.h"

using namespace std;

typedef long long ll; 

const ll Maxn = 200005;

const ll Mod = 998244353;

ll N;

struct Robot{

	ll X;

	ll D;

}a[Maxn];

ll Touch_Far_Robot[Maxn];

ll Touch_Far_Robot_Tree[4*Maxn];

ll dp[Maxn];

bool Have_Test_Poi[Maxn];

bool cmp(Robot a,Robot b)

{

	return a.X<b.X;

}

void UpData_Tree(ll poi,ll Left,ll Right,ll Poi,ll Value)

{

	if(Left >Poi || Right <Poi)	return;

	if(Left == Right &&Left == Poi) 

	{

		Touch_Far_Robot_Tree[poi]= Value;

		return;

	}

	ll Mid = Left + (Right - Left)/2;

	UpData_Tree(poi*2,Left,Mid,Poi,Value);

	UpData_Tree(poi*2+1,Mid+1,Right,Poi,Value);

	Touch_Far_Robot_Tree[poi] = max(Touch_Far_Robot_Tree[poi*2],Touch_Far_Robot_Tree[poi*2+1]);

}

ll Search(ll x)

{

	ll Left = 1;

	ll Right = N;

	ll ans;

	while(Left<=Right)

	{

		ll Mid = Left + (Right - Left)/2;

		if(!Have_Test_Poi[Mid])	//表示当前还没有测试到

		{

			Left = Mid + 1;

			continue;

		} 

		if(a[Mid].X <x)//表示可以 

		{

			ans = Mid;

			Left = Mid +1;

		}

		else

		{

			Right = Mid -1;

		}

	}

	return ans;

}

ll Search_Touch_Tree(ll poi,ll Left ,ll Right,ll L,ll R)

{

	ll ans = -1;

	if(Left > R ||Right < L)	return 0;

	if(L <=Left &&Right <=R)	return Touch_Far_Robot_Tree[poi];

	ll Mid = Left + (Right - Left)/2;

	ans = max(ans,Search_Touch_Tree(poi*2,Left,Mid,L,R));

	ans = max(ans,Search_Touch_Tree(poi*2+1,Mid+1,Right,L,R));

	return ans;

}

int main()

{

	scanf("%lld",&N);

	for(int i=1;i<=N;i++) scanf("%lld %lld",&a[i].X,&a[i].D);

	sort(a+1,a+N+1,cmp);

	Touch_Far_Robot[N] = N; //预处理一开始最先碰到自已

	UpData_Tree(1,1,N,N,N); 

	Have_Test_Poi[N] = true;

	for(int i = N-1;i>=1;i--)

	{

		Have_Test_Poi[i] = true;

		ll Dist = a[i].X + a[i].D;

		ll x = Search(Dist);

		Touch_Far_Robot[i] = max(x,Search_Touch_Tree(1,1,N,i,x));

		UpData_Tree(1,1,N,i,Touch_Far_Robot[i]);

	}

	dp[N] = 2;

	for(int i=N+1;i<Maxn;i++)	dp[i]= 1;	//因为空的也算一种 

	for(int i=N-1;i>=1;i--)

	{

		dp[i] = dp[i+1] + dp[Touch_Far_Robot[i]+1];

		dp[i]%=Mod;

	}

	cout<<dp[1];

	return 0;	

} 