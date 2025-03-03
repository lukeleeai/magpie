#include <string>

#include "stdc++.h"

using namespace std;

typedef long long ll;

//typedef pair<long long,long long> P;

//typedef pair<long long,P> P1;

//typedef pair<P,P> P2;

#define pu push

#define pb push_back

#define mp make_pair

#define eps 1e-7

#define INF 1000000000

#define mod 1000000007

#define fi first

#define se second

#define rep(i,x) for(long long i=0;i<x;i++)

#define repn(i,x) for(long long i=1;i<=x;i++)

#define rrep(i,x) for(long long i=x-1;i>=0;i--)

#define rrepn(i,x) for(long long i=x;i>1;i--)

#define SORT(x) sort(x.begin(),x.end())

#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())

#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())

#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())





#define ALL(v)  (v).begin(),(v).end()

//#define MAX(a,b) if(a>b)

#define MAX(a,b) (((a)>(b))?(a):(b))

#define MIN(a,b) (((a)<(b))?(a):(b))









template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



#define pr printf

#define re return

#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)







ll N;

ll sum;

ll flg;

int main(){

	

	cin.tie(nullptr);

	ios::sync_with_stdio(false);

	

	

	cin >> N;

	

	vector<pair<long long, long long> > p(N);

	for(long long i=0; i<N; i++){

		long long a, b;

		cin >> a >> b;

		p[i] = make_pair(b, a);

	}

    

	

	sort(p.begin(), p.end());

	//sort(p.begin(), p.end(),greater<pair<long long,long long> >());

	

	

	//●●●	通常（ペア用）

	flg=0;

	sum=0;

	for(long long i=0; i<N; i++){

		

		sum+=p[i].se;

		if(sum>p[i].fi){

			flg=1;

			break;

		}

	}

	

	

	if(flg==0){

		puts("Yes");

	}

	else{

		puts("No");

	}

	re 0;

}
