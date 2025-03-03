#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vll;

#define pu push

#define pb push_back

#define mp make_pair

#define eps 1e-7

#define INF 1000000000

#define sz(x) ((int)(x).size())

#define sq(x) ((x)*(x))

#define fi first

#define sec second

#define SORT(x) sort((x).begin(),(x).end())

#define all(x) (x).begin(),(x).end()

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)

#define EQ(a,b) (abs((a)-(b))<eps)

int N,M;

int S[1010],k[1010];

vector<int> c[1010];

int mx[10010];

int mi[10010];

int solve(){

	cin >> N >> M;

	if(N+M==0)return 1;

	memset(mx,0,sizeof(mx));

	memset(mi,0,sizeof(mi));

	for(int i=0;i<1010;i++)c[i].clear();

	for(int i=0;i<M;i++){

		cin >> S[i] >> k[i];

		c[i].resize(k[i]);

		for(int j=0;j<k[i];j++){

			cin >> c[i][j];

			c[i][j]--;

			mx[c[i][j]]+=S[i];

			if(k[i]==1)mi[c[i][j]]+=S[i];

		}

	}

	/*for(int i=0;i<N;i++){

		printf("%d: mi %d, mx %d\n",i,mi[i],mx[i]);

	}*/

	multiset<int> ms;

	for(int i=0;i<N;i++)ms.insert(mx[i]);

	int ans = 0;

	for(int i=0;i<N;i++){

		multiset<int>::iterator it = ms.find(mx[i]);

		assert(it!=ms.end());

		ms.erase(it);

		ans = max(ans,(*ms.rbegin())-mi[i]);

		ms.insert(mx[i]);

	}

	cout << ans+1 << endl;

	return 0;

}

int main(){

	while(!solve()){}

	return 0;

}