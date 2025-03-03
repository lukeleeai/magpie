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

 

int main() {

	int N;

	cin >> N;

	ll A[Nmax]={};

	ll sumA=0;

	REP(i,N){

		cin >> A[i];

		A[i]-=i+1;

		sumA+=A[i];

	}

	ll S[Nmax]={};

  	sort(A,A+N);

  	S[0]=A[0];

  	REP(i,N-1) S[i+1]+=S[i]+A[i+1];

  	//sort(S,S+N);

	ll b=round((double)(sumA/N)); //仮のb

	ll ans1=0,ans2=0;

	ll mina=0;

	REP(i,N) mina+=abs(A[i]-b);

	FOR(j,1,MOD){

		/*REP(i,N){

      	ans1+=abs(A[i]-b+j);//bを上下に1ずつ広げていく

	  	ans2+=abs(A[i]-b-j);

   		}*/

   		int a=upper_bound(A,A+N,b+j)-A;

   		int c=upper_bound(A,A+N,b-j)-A;

   		ans1=abs(S[a-1]-(b+j)*(a))+abs((S[N-1]-S[a-1])-(b+j)*(N-a));

   		ans2=abs(S[c-1]-(b-j)*(c))+abs((S[N-1]-S[c-1])-(b-j)*(N-c));

   		mina=min(mina,min(ans1,ans2));

   		if(mina!=ans1&&mina!=ans2){//単調増加に転じたらbreak

	   		break;

	   	}

   	}

	cout << mina << endl;

	return 0;

}