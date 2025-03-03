#include"stdc++.h"

using namespace std;

typedef pair<int,int> P;

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vll;

#define pb push_back

#define mp make_pair

#define eps 1e-9

#define INF 1000000000

#define sz(x) ((int)(x).size())

#define fi first

#define sec second

#define all(x) (x).begin(),(x).end()

#define sq(x) ((x)*(x))

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)

#define EQ(a,b) (abs((a)-(b))<eps)

template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}

template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}

int N,Ma,Mb;

int a[45],b[45],c[45],d[45];

map<int,int> m;

int main(){

	cin >> N >> Ma >> Mb;

	for(int i=0;i<N;i++){

		cin >> a[i] >> b[i] >> c[i];

		a[i]*=Mb;

		b[i]*=Ma;

		d[i]=a[i]-b[i];

	}

	int M = N/2;

	int ans = INF;

	for(int i=1;i<(1<<M);i++){

		int s = 0, cost = 0;

		for(int j=0;j<M;j++){

			if((i>>j)&1){

				s+=d[j];

				cost+=c[j];

			}

		}

		map<int,int>::iterator it = m.find(s);

		if(s==0)ans = min(ans,cost);

		if(it==m.end())m[s]=cost;

		else (it->sec)=min((it->sec),cost);

	}

	for(int i=1;i<(1<<(N-M));i++){

		int s = 0, cost = 0;

		for(int j=0;j<(N-M);j++){

			if((i>>j)&1){

				s+=d[j+M];

				cost+=c[j+M];

			}

		}

		int tar = -s;

		map<int,int>::iterator it = m.find(tar);

		if(tar==0)ans = min(ans,cost);

		if(it!=m.end()){

			ans = min(ans,cost+(it->sec));

		}

	}

	if(ans==INF)ans = -1;

	printf("%d\n",ans);

	return 0;

}