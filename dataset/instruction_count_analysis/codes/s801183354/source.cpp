#include "bits/stdc++.h"

using namespace std;

#define MOD 1000000007

#define Nmax 200010

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)

#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)

#define REP(i,n)  FOR(i,0,n)

#define RREP(i,n) RFOR(i,0,n)

#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)

#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)

#define dump(x)  cout << #x << " = " << (x) << endl;

#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef long long ll;

typedef pair<ll,ll> P;

typedef vector<P> Graph;

 

int main() {//答え聞いた後版

	int N;

	cin >> N;

	ll A[Nmax]={};

	REP(i,N){

		cin >> A[i];

		A[i]-=i+1;

	}

  	sort(A,A+N);

	ll b=A[(N-1)/2];//med

	ll mina=0;//ans

	REP(i,N) mina+=abs(A[i]-b);



	cout << mina << endl;

	return 0;

}