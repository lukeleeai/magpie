#include <iostream>

#include <cstdio>

#include <cmath>

#include <map>

#include <vector>

#include <algorithm>

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define per(i,a,b) for(itn i=a;i>=b;i--)

using namespace std;

const int Mod=1e9+7;

typedef long long ll;

ll ans,Ans,fib[105]={1,1},x,y;

vector<pair<ll,ll> >p[105];

map<pair<ll,ll>,bool> checker;

int main(){

	rep(i,2,90) fib[i]=fib[i-1]+fib[i-2];

	//rep(i,1,100) if(fib[i]>1e18) printf("Here %d\n",i);

	p[1].push_back(make_pair(1,2));

	p[1].push_back(make_pair(1,3));

	p[1].push_back(make_pair(1,4));

	rep(i,1,90){

		for(int j=0;j<p[i].size();j++){

			ll u=p[i][j].second,v=p[i][j].first+u;

			for(;v<=fib[i+3];v+=u){

				if(checker[make_pair(u,v)]) puts("fuck i am wrong!");

				checker[make_pair(u,v)]=1;

				p[i+1].push_back(make_pair(u,v));

			}

		}

	}

	int T;

	scanf("%d",&T);

	while(T--){

		scanf("%lld%lld",&x,&y);

		if(x>y) swap(x,y);

		for(ans=1,Ans=0;fib[ans+1]<=x&&fib[ans+2]<=y;ans++); printf("%d ",ans);

		if(ans==1){

			printf("%lld\n",x*y%Mod);

			continue;

		}

		for(int j=0;j<p[ans-1].size();j++){

			ll u=p[ans-1][j].first,v=p[ans-1][j].second;

			if(v<=x) Ans=(Ans+(y-u)/v%Mod)%Mod;

			if(v<=y) Ans=(Ans+(x-u)/v%Mod)%Mod;

		}

		printf("%lld\n",Ans);

	}

	return 0;

}