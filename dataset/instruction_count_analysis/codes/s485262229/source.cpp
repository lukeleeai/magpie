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



    ll N;

    cin >> N;



   	ll x = -1;

    REP(i, N+2){

    	if(i*(i-1) == 2*N) x = i;

    }

    if(x == -1){

    	cout << "No" << endl;

    	exit(0);

    }

    cout << "Yes" << endl;

    vector<ll> res[x];

    ll ind = 1;

    REP(i, x){

    	REP(j, x){

    		if(i >= j) continue;

    		res[i].push_back(ind);

    		res[j].push_back(ind);

    		ind++;

    	}

    }

    cout << x << endl;

    REP(i, x){

    	cout << res[i].size() << " ";

    	REP(j, res[i].size()) cout << res[i][j] << " ";

    	cout << endl;

    }

    return 0;

}