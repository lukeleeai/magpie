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



template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){

  os << "(" << v.first << ", " << v.second << ")"; return os;

}

template<class T> ostream& operator << (ostream& os, const vector<T> v){

  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;

}

template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){

  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);



    ll N, K;

    cin >> N >> K;

    vector<pll> sushi(N);

    REP(i, N){

    	cin >> sushi[i].second >> sushi[i].first;

    	sushi[i].second--;

    }



    ll sum = 0, type = 0;

    sort(sushi.begin(), sushi.end());

    vector<ll> cnt(N, 0);

    priority_queue<ll, vector<ll>, greater<ll> > pq;



    REP(i, K){

    	sum += sushi[N-1-i].first;

    	if(cnt[sushi[N-1-i].second] == 0) type++;

    	else pq.push(sushi[N-1-i].first);

    	cnt[sushi[N-1-i].second]++;

    }

    ll res = sum + type*type;

    for(int i=N-K-1;i>=0;i--){

    	if(pq.empty()) break;

    	if(cnt[sushi[i].second] == 0){

    		type++;

    		cnt[sushi[i].second]++;

    		ll tmp = pq.top();

    		pq.pop();

    		sum += sushi[i].first;

    		sum -= tmp;

    		res = max(res, sum + type*type);

    	}

    }

    cout << res << endl;

    return 0;

}