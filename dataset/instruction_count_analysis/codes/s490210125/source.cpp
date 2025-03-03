#include "bits/stdc++.h"

using namespace std;

#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

#define rep(i,n) repr(i,0,n)

#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define reprev(i,n) reprrev(i,0,n)

#define all(a) (a).begin(),(a).end()

#define rall(a) (a).rbegin(),(a).rend()

#define mp make_pair

#define mt make_tuple

#define MOD 1000000007

#define PI 3.1415926535

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> Pi;

typedef pair<ll, ll> Pll;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<bool> vb;

typedef vector<char> vc;

typedef vector<string> vs;

typedef vector<double> vd;

typedef vector<Pi> vPi;

typedef vector<Pll> vPll;

typedef vector<vector<int>> vvi;

typedef vector<vector<bool>> vvb;

typedef vector<vector<ll>> vvll;

typedef vector<vector<char>> vvc;

typedef vector<vector<string>> vvs;

typedef vector<vector<double>> vvd;

typedef vector<vector<Pi>> vvPi;

typedef priority_queue<int, vector<int>, greater<int>> pqli;

typedef priority_queue<ll, vector<ll>, greater<ll>> pqlll;

typedef priority_queue<Pi, vector<Pi>, greater<Pi>> pqlP;

string YN(bool y) { return (y?"YES":"NO"); }

string yn(bool y) { return (y?"Yes":"No"); }

string ON(bool y) { return (y?"OK":"NG"); }

//重みなしグラフの場合

vi p(100000);

vector<vector<int>> L(100000);      //隣接リスト

vector<bool> Visited(100000, false);   //頂点が訪問済みか否かを格納

vvi connect(100000), pos(100000);

//頂点数n, 枝数mのグラフの入力(重みなし)

void Graph_Input(int n, int m)

{

	for(int i=0; i<m; i++){

		int from, to;

		cin>>from>>to;

		from--; to--;

		L[from].push_back(to);

		//無向グラフの場合以下も追加

		L[to].push_back(from);

	}

}

//深さ優先探索(現在位置をiとする)

void DFS(int i, int k)

{

	Visited[i]=true;

	connect[k].push_back(p[i]);

	pos[k].push_back(i);



	for(int j=0; j<(int)L[i].size(); j++){

		if(Visited[L[i][j]]) continue;

		DFS(L[i][j], k);

	}

}

int main(void)

{

	int n, m;



	cin>>n>>m;



	rep(i, n){

		cin>>p[i];

		p[i]--;

	}



	Graph_Input(n, m);



	int t=0;

	rep(i, n){

		if(!Visited[i]){

			DFS(i, t);

			t++;

		}

	}

	int ans=0;

	rep(i, t){

		sort(all(pos[i]));

		/*rep(j, connect[i].size()){

			cout<<connect[i][j]<<" ";

		}

		cout<<endl;*/

		rep(j, connect[i].size()){

			if(binary_search(all(pos[i]), connect[i][j])) ans++;

		}

	}

	cout<<ans<<endl;

}
