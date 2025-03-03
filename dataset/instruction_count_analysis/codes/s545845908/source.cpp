#include "stdc++.h"

using namespace std;

const int MXN = 3e5+7;

long long FT[MXN];

void add(int idx,long long amt){

	while(idx < MXN){

		FT[idx] += amt;

		idx += idx & -idx;

	}

}

long long sum(int idx){

	long long ret = 0ll;

	while(idx > 0){

		ret += FT[idx];

		idx -= idx & -idx;

	}

	return ret;

}

int main(){

	#ifdef REDIRECT_IO

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

	#endif

	int n;

	scanf("%d",&n);

	vector<int> dat1,dat2,dat3,com;

	com.push_back(-1e9);

	for(int i = 0; i < n; i++){

		int x;

		scanf("%d",&x);

		dat1.push_back(x);

		com.push_back(x);

	}

	for(int i = 0; i < n; i++){

		int x;

		scanf("%d",&x);

		dat2.push_back(x);

		com.push_back(x);

	}

	for(int i = 0; i < n; i++){

		int x;

		scanf("%d",&x);

		dat3.push_back(x);

		com.push_back(x);

	}

	sort(com.begin(),com.end());

	com.resize(unique(com.begin(),com.end()) - com.begin());

	for(int i = 0; i < n; i++){

		int x = lower_bound(com.begin(),com.end(),dat1[i]) - com.begin();

		add(x,1);

	}

	vector<pair<int,long long> > v;

	for(int i = 0; i < n; i++){

		int x = lower_bound(com.begin(),com.end(),dat2[i]) - com.begin();

		v.emplace_back(x,sum(x-1));

	}

	memset(FT,0,sizeof(FT));

	for(int i = 0; i < n; i++){

		add(v[i].first,v[i].second);

	}

	long long ans = 0ll;

	for(int i = 0; i < n; i++){

		int x = lower_bound(com.begin(),com.end(),dat3[i]) - com.begin();

		ans += sum(x-1);

	}

	printf("%lld",ans);

	return 0;

}