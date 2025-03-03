#include"stdc++.h"



#define mp make_pair

#define mt make_tuple

#define fi first

#define se second

#define pb emplace_back

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)



using namespace std;



typedef pair<int, int> pii;

typedef vector<int> vi;

typedef vector<pii> vpi;

typedef vector<vi> vvi;

typedef long long i64;

typedef vector<i64> vi64;

typedef vector<vi64> vvi64;

typedef pair<i64, i64> pi64;

typedef double ld;

 

template<typename T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<typename T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<typename T> bool Min(T a, T b) { return a > b ? b : a; }

template<typename T> bool Max(T a, T b) { return a < b ? b : a; }

template<typename T> void de(T a){ 

#ifdef LOCAL_DEFINE

	cout<< a << endl;

#endif

}

	

const int INF = 2e5+1;



int n,m;

vi graph[INF];

vector<bool>vis(INF,false);

vi dp(INF,0);

int complexx=0;

vi edges(INF,0);



void dfs(int v,int dis){

	assert(!vis[v]);

	vis[v]=true;

 	complexx++;

	for(int i:graph[v]){       

	 	uax(dp[i],dp[v]+1);

	 	edges[i]--;

	 	if(edges[i]==0)

	 		dfs(i,dis+1);      

	}



}



int main(){

        ios::sync_with_stdio(false);

        cin.tie(nullptr);

    	cout.precision(10);

    	cout << fixed;

#ifdef LOCAL_DEFINE

    freopen("input.txt", "rt", stdin);

#endif

                

	cin>>n>>m;

	int a,b;

	forn(i,m){

	 	cin>>a>>b;

	 	graph[a-1].pb(b-1);

	 	edges[b-1]++;

	}

        // imagine a fake vertex which is connected to every other vertex 

        forn(i,n){

        	graph[n].pb(i);

        	edges[i]++;

        }

#ifdef LOCAL_DEFINE

        forn(i,n+1){

         	for(auto j:graph[i]) cout<<j<<" ";

         	cout<<endl;

        }

#endif

        dfs(n,1);

        de(complexx);

        cout<<(*max_element(dp.begin(),dp.begin()+n+2))-1<<endl;

               

#ifdef LOCAL_DEFINE

    cerr << "Time elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";

#endif



	return 0;

}	


