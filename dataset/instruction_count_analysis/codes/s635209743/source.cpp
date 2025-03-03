#include "stdc++.h"

using namespace std;



typedef unsigned long long ull;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;

const ull mod = 1e9 + 7;

#define REP(i,n) for(int i=0;i<(int)n;++i)



//debug

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



template < typename T >

void vprint(T &v){

	REP(i, v.size()){

		cout << v[i] << " ";

	}

	cout << endl;

}



int main(){

	ll N, K;

	cin >> N >> K;

	vector<pll> sushis(N);

	REP(i, N){

		cin >> sushis[i].second >> sushis[i].first;

	}

	sort(sushis.rbegin(), sushis.rend());

	ll sum = 0;

	vector<ll> syu(N+1, 0);

	REP(i, K){

		sum += sushis[i].first;

		syu[sushis[i].second] += 1;

	}

	ll total_syu = 0;

	REP(i, N+1){

		if(syu[i]>0)total_syu += 1;

	}



	ll ma = sum + total_syu*total_syu;



	vector<ll> maxs(101010, -1);

	for(int i=K;i<N;i++){

		maxs[sushis[i].second] = max(maxs[sushis[i].second], sushis[i].first);

	}

	REP(i, K){

		maxs[sushis[i].second] = -1;

	}



	vector<ll> cand;

	REP(i, 101010){

		if(maxs[i]>0) cand.push_back(maxs[i]);

	}

	sort(cand.rbegin(), cand.rend());



	vector<ll> mama[101010];

	vector<ll> ax;

	REP(i, K){

		mama[sushis[i].second].push_back(sushis[i].first);

	}

	REP(i, 101010){

		if(mama[i].size()>1) sort(mama[i].rbegin(), mama[i].rend());

	}

	REP(i, 101010){

		for(int j=1;j<mama[i].size();j++){

			ax.push_back(mama[i][j]);

		}

	}

	sort(ax.begin(), ax.end());



	//vprint(cand);

	//vprint(ax);



	REP(i, min(cand.size(), ax.size())){

		sum -= ax[i];

		sum += cand[i];

		total_syu += 1;

		ma = max(ma, sum + total_syu*total_syu);

	}



	cout << ma << endl;



    return 0;

}