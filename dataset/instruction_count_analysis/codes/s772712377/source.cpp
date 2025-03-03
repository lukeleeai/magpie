#include "stdc++.h"

using namespace std;

typedef long long ll;

#define P pair<ll,ll>

#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)

#define FORR(I,A,B) for(ll I = ((B)-1); I >= (A); --I)

#define TO(x,t,f) ((x)?(t):(f))

#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9

#define REV(x) (reverse(x.begin(),x.end())) //reverse

ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}

ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu

#define NEXTP(x) next_permutation(x.begin(),x.end())

const ll INF=1e18+7;

const ll MOD=1e9+7;

#define pri(a) cout << (a) << endl





int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);

	ll N,K;

	cin >> N;

	bool there = false;

	FOR(i,1,100000){

		if((i*(i-1))==(2*N)){

			there=true;

			K = i;

		}

	}

	if(not there){

		cout << "No" << endl;

		return 0;

	}

	vector< vector<ll> > S;

	S.resize(K+1);

	bool same[K+1][K+1] = {};

	FOR(i,1,K+1){

		FOR(j,1,K+1){

			if(j==i)continue;

			if(not same[i][j]){

				same[i][j] = same[j][i] = true;

				S[i].push_back(N);

				S[j].push_back(N);

				N--;

			}

		}

	}

	cout << "Yes" << endl << K << endl;

	FOR(i,1,K+1){

		cout << S[i].size() << " ";

		FOR(j,0,S[i].size()){

			cout << S[i][j] << " ";

		}

		cout << endl;

	}

}