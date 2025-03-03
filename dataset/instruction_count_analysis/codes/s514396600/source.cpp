#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

#define all(c) c.begin(),c.end()

#define pb push_back

#define fs first

#define sc second

#define show(x) cout << #x << " = " << x << endl

#define chmin(x,y) x=min(x,y)

#define chmax(x,y) x=max(x,y)

using namespace std;

template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}

template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}



int inf = 1e9;

int dp[200010];

vector<int> from[200010];

int fromc[200010];

set<int> st[26];

bool ok[200010];

int main(){

	string s;

	cin>>s;

	int N = s.size();

	rep1(i,N+1) fromc[i] = 26;



	rep(i,N){

		st[s[i]-'a'].insert(i);

	}

	rep(i,26) st[i].insert(N);



	rep1(i,N+1) dp[i] = inf;

	rep(i,N+1){

		rep(c,26){

			int nxt = *st[c].lower_bound(i);

			int j = nxt+1;

			if(dp[j]>dp[i]+1){

				dp[j] = dp[i]+1;

				from[j] = {i};

			}else if(dp[j] == dp[i]+1){

				from[j].pb(i);

			}

		}

	}



	ok[N+1] = 1;

	for(int i = N;i>=0; i--){

		rep(c,26){

			int nxt = *st[c].lower_bound(i);

			int j = nxt+1;

			if(dp[j] == dp[i]+1 && ok[j]) ok[i] = 1;

		}

	}



	string ans;



	for(int i=0;i!=N+1;){

		rep(c,26){

			int nxt = *st[c].lower_bound(i);

			int j = nxt+1;

			if(dp[j] == dp[i]+1 && ok[j]){

				i = j;

				ans += 'a'+c;

				break;

			}

		}

	}

	cout<<ans<<endl;

}
