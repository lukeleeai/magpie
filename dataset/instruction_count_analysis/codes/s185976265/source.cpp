#include "stdc++.h"

 

using namespace std;

 

#define lli long long int

#define REP(i,s,l) for(lli i=s;i<l;i++)

#define DEBUG 0

#define INF (1LL<<50)

#define MOD 1000000007



vector<vector<lli>> v;

lli n,d;



lli distance(lli a,lli b){

	lli sum = 0;

	REP(i,0,d){

		lli d = v[a].at(i) - v[b].at(i);

		sum += d*d;

	}

	return sum;

}



signed main(){



	cin>>n>>d;

	v.resize(n);



	set<lli> s;



	REP(i,0,10000){

		s.insert(i*i);

	}



	REP(i,0,n)REP(j,0,d){

		lli tmp;

		cin>>tmp;

		v[i].push_back(tmp);

	}



	lli ans=0;

	for(lli i=0;i<n;i++){

		for(lli j=i+1;j<n;j++){

			lli d = distance(i,j);

			if(s.find(d)!=s.end())ans++;

		}

	}

	cout<<ans<<endl;



	return 0;

}