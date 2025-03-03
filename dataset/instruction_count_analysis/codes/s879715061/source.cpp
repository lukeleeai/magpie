#include <vector>

#include <map>

#include <set>

#include <cmath>

#include <iostream>

#include <algorithm>

#include <queue>

#include <iomanip>

#include <list>

#include <string>



typedef char                SINT8;

typedef short               SINT16;

typedef int                 SINT32;

typedef long long           SINT64;

typedef double              DOUBLE;



#define MAX(a,b) ((a)>(b)?(a):(b))

#define MIN(a,b) ((a)<(b)?(a):(b))

#define ABS(a) ((a)>(0)?(a):-(a))

#define rep(i,a,b) for(SINT64 (i)=SINT64(a);(i)<SINT64(b);(i)++)

#define rrep(i,a,b) for(SINT64 (i)=SINT64(a);(i)>=SINT64(b);(i)--)



#define put(a) cout << (a) << endl

#define puts(a) cout << (a) << " "





#define INF 1000000001

#define MOD 1000000007

#define INF64 1000000000000000001



#define F first

#define S second



#define Pii  pair<SINT32,SINT32>

#define Pll  pair<SINT64,SINT64>

#define Piii pair<SINT32,pair<SINT32,SINT32>>

#define Plll pair<SINT64,pair<SINT64,SINT64>>



#define Vll(a,b,c)    vector<vector<SINT64>> (a)((b),vector<SINT64>((c))

#define Vlll(a,b,c,d) vector<vector<vector<SINT64>>> (a)((b),vector<vector<SINT64>>((c),vector<SINT64>((d)))





using namespace std;

class Comb {

	vector<SINT64> base;

	SINT64 N;

 

public:

	Comb (SINT64 n) {

		N = n+5;

		base.resize(N);

		base[0] = 1;

		rep(i,1,N) {

			base[i] = base[i-1]*i;

			base[i] %= MOD;

		}

	}

	

	SINT64 get_comb(SINT64 a, SINT64 b) {

		SINT64 ans = 0;

		SINT64 aa = 1;

		rep(i,0,b) {

			aa *= a;

			aa %= MOD;

			a--;

		}



		ans = aa * modpow(base[b], MOD - 2) % MOD;

		return ans;

	}



	SINT64 modpow(SINT64 a, SINT64 p) {

		if (p == 0) return 1;

		if (p % 2 == 0) {

			SINT64 halfP = p / 2;

			SINT64 half = modpow(a, halfP);

			return half * half % MOD;

		} else {

			return a * modpow(a, p - 1) % MOD;

		}

	}

};



SINT64 modpow(SINT64 a, SINT64 p) {

	if (p == 0) return 1;

	if (p % 2 == 0) {

		//pが偶数の時

		SINT64 halfP = p / 2;

		SINT64 half = modpow(a, halfP);

		//a^(p/2) をhalfとして、half*halfを計算

		return half * half % MOD;

	} else {

		//pが奇数の時は、偶数にするために1減らす

		return a * modpow(a, p - 1) % MOD;

	}

}



int main() {



	SINT64 N;	cin >> N;

	SINT64 a,b; cin >> a >> b;



	Comb com(200005);

	SINT64 aa,bb,ans;

	aa = com.get_comb(N,a);

	bb = com.get_comb(N,b);



	ans = modpow(2,N)-1;



	ans -= aa;

	ans -= bb;

	rep(i,0,10) {

		if (ans < 0) {

			ans += MOD;

		}

	}

	put(ans);



	return 0;

}





//	vector<vector<SINT64>> data(N,vector<SINT64>(N));										//2次元配列

//	vector<vector<vector<SINT64>>> data(N,vector<vector<SINT64>>(N,vector<SINT64>(N)));		//3次元配列



//	Vll(data,N,N);		//2次元配列

//	Vlll(data,N,N,N);	//3次元配列



//	sort(data.begin(),data.end());

//	sort(data.begin(),data.end(),std::greater<SINT64>());

//	__gcd(A,B);



//  reverse(data.begin(),data.end());



//関数へのvectorポインタ渡し

//void dfs(SINT64 poi, SINT64 d, vector<vector<Pll>>& data) {

//}



/* 複数条件ソート

bool sortcompare(Pll A, Pll B) {

    if(A.F == B.F){

        return A.S > B.S;

    } else {

        return A.F < B.F;

    }

}



sort(data.begin(),data.end(),sortcompare);

*/



// タプル

//vector<tuple<SINT64,SINT64,SINT64>> edges;

//edges.emplace_back(a,b,c);

//cout << get<0>(edges[i]);

//cout << get<1>(edges[i]);

//cout << get<2>(edges[i]);

//sort(begin(edges), end(edges)); //ソート





//	data.emplace_back(BUF);			//後ろに追加



//  data.erase(std::unique(data.begin(), data.end()), data.end());	//ソート後に使用 同じ値を消す



//	data.insert(data.begin() + X, 0);	//X番目の要素に0を挿入





//	隣接リスト

//	vector<vector<SINT64>> data(N);

//	data[ A ].emplace_back( B );





// 両端キュー

//deque<SINT64> data;

//data.emplace_front(buf);	//先頭挿入





// lower_boundは値がなければ最大値(.size())を返す

// posi = lower_bound(data.begin(),data.end(), X) - data.begin();				// X以上を探す

// posi = lower_bound(data.begin(),data.end(),make_pair(X,0)) - data.begin();	//pair





/* 文字列回転

	string N;

	cin >> N;

	N = N[N.length()-1] + N.substr(0,N.length()-1);



	s = to_string(i);	//ストリング変換

*/

/* 文字列合成

	string N,M;

	cin >> N >> M;

	SINT64 ans = 0;

	ans = stoi(N+M);

*/



/*  文字列変更

	string s;	cin >> s;

	rep(i,0,s.length()) {	

		s[i] = (((s[i]-'A' + N) % 26) + 'A');

	}

	put(s);

*/



/*

//ワーシャルフロイド

	vector<vector<SINT64>> dist(N,vector<SINT64>(N,INF64));

	rep(i,0,N) {

		dist[i][i] = 0;

	}

	rep(k,0,N) {

		rep(i,0,N) {

			rep(j,0,N) {

				dist[i][j] = MIN(dist[i][j], dist[i][k]+dist[k][j]);

			}

		}

	}

*/



/*  優先度付きキュー

	priority_queue<SINT64, vector<SINT64>, greater<SINT64>> bufq;	//小さいほうから取り出せる

	priority_queue<SINT64, vector<SINT64>> bufq;					//大きいほうから取り出せる



	bufq.push(X);	//X を挿入

	bufq.top();		//先頭データ読み

	bufq.pop();		//先頭データ削除

*/



/* キュー

	queue<SINT64> bufq;	//宣言

	bufq.push(0);	//挿入

	bufq.front();	//先頭データ読み

	bufq.pop();		//先頭データ削除

*/











/* SET コンテナ

	set<SINT64> data;

	data.insert(X);				//X を挿入

	data.erase(data.begin());	//先頭を削除

	data.erase(--data.end());	//末尾を削除

	*data.begin();				//先頭要素にアクセス

	*data.rbegin();				//末尾要素にアクセス



	//全表示

    set<SINT64>::iterator it; //イテレータを用意

    for(it = data.begin(); it != data.end(); it++) {

        cout << *it << " ";

    }

	cout << endl;



	//N番目を一部表示

	set<SINT64>::iterator it; //  イテレータを用意

	it = data.begin();

	rep (i,0,N) {

		it++;

	}

	cout << *it << endl;

*/



/* map

	map<string,SINT32> mp;

	SINT32 N = 0;

	SINT32 mx = 0;



	cin >> N;

	for (SINT32 i = 0; i < N; i++) {

		string s;

		cin >> s;

		mp[s]++;

	}

	for(auto it=mp.begin();it!=mp.end();it++) {

		mx=max(mx,it->second);

	}



	//abc146E

	map<SINT64,SINT64> mp;

	rep(i,0,N+1) {

		ans += mp[rui[i]];

		mp[rui[i]]++;

		bufq.push(rui[i]);

		if (bufq.size() == M) {

			mp[bufq.front()]--;

			bufq.pop();

		}

	}

*/



/*

	//順列全表示

	//sortしてからでないと全列挙にならない

	sort(data.begin(),data.end());

	do {

		cout << buf << endl;

		rep(i,0,R) {

			cout << data[i] << " ";

		}

		cout << endl;



    } while (next_permutation(data.begin(),data.end()));

*/



/* bit数数え上げ

SINT64 bits64(SINT64 bits)

{

    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);

    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);

    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);

    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);

    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);

}

*/



//bitシフトのLONG対応

// ans += (1L<<50);







//  桁指定表示

//  ans = ans * M_PI;

//	cout << setprecision(15) << ans << endl;



// 桁数0埋め

// cout << std::setfill('0') << std::right << std::setw(2) << 5; //05





//2次元累積和

/*

	vector<vector<SINT64>> data(H,vector<SINT64>(W));

	vector<vector<SINT64>> rui(H+1,vector<SINT64>(W+1));

	

	rep(i,0,H) {

		rep(j,0,W) {

			cin >> data[i][j];

		}

	}

	rep(i,1,H+1) {

		rep(j,1,W+1) {

			rui[i][j] = data[i-1][j-1] + rui[i][j-1];

		}

	}

	rep(i,1,H+1) {

		rep(j,1,W+1) {

			rui[i][j] += rui[i-1][j];

		}

	}

*/





// 逆元　コンビネーション

/*

SINT64 modpow(SINT64 a, SINT64 p) {

	if (p == 0) return 1;

	if (p % 2 == 0) {

		//pが偶数の時

		SINT64 halfP = p / 2;

		SINT64 half = modpow(a, halfP);

		//a^(p/2) をhalfとして、half*halfを計算

		return half * half % MOD;

	} else {

		//pが奇数の時は、偶数にするために1減らす

		return a * modpow(a, p - 1) % MOD;

	}

}



SINT64 calcComb(SINT64 a, SINT64 b) {

	SINT64 Mul = 1;

	SINT64 Div = 1;

	SINT64 ans = 0;



	if (b > a - b) {

		return calcComb(a, a - b);

	}

 

	rep(i,0,b) {

		Mul *= (a - i);

		Div *= (i + 1);

		Mul %= MOD;

		Div %= MOD;

	}

	ans = Mul * modpow(Div, MOD - 2) % MOD;

	return ans;

}

*/





/* UNION FIND

class UnionFind {

public:

	vector<SINT64> parent;



	UnionFind(SINT64 N) {

		parent = vector<SINT64>(N+10, -1);	//少し多めに

	}

	

	SINT64 root(SINT64 A) {

		if (parent[A] < 0) {

			return A;

		} else {

			parent[A] = root(parent[A]);

			return parent[A];

		}

	}



	SINT64 size(SINT64 A) {

		return parent[root(A)] * (-1);

	}



	bool judge(SINT64 A, SINT64 B) {

		A = root(A);

		B = root(B);

		if (A == B) {

			return true;	//同じグループ

		} else {

			return false;	//違うグループ

		}

	}



	void connect(SINT64 A, SINT64 B) {

		A = root(A);

		B = root(B);

		if (A != B) {

			if (size(A) < size(B)) {

				swap(A, B);

			}

			parent[A] += parent[B];

			parent[B] = A;

		}

	}

};

UnionFind uni(N);

 */



/*　セグ木

class SegTree {

private:

	SINT64 size;

	vector<SINT64> node;



	SINT64 jugdement(SINT64 a, SINT64 b) {

		SINT64 ans = 0;

		ans = a+b;

		return ans;

	}



public:



	//コンストラクタ

	SegTree(vector<SINT64> data) {

		SINT64 ori_size;

		ori_size = data.size();

		size = 1;

		while (size < ori_size) {

			size *= 2;

		}

		node.resize(2*size-1, 0);



		rep(i,0,ori_size) {

			node[size-1+i] = data[i];

		}

		rrep(i,size-2,0) {

			node[i] = jugdement(node[2*i+1], node[2*i+2]);

		}

	}



	//データ更新

	void update(SINT64 x, SINT64 val) {

		x += (size - 1);

    	node[x] = val+node[x];

    	while(x > 0) {

        	x = (x - 1) / 2;

        	node[x] = jugdement(node[2*x+1], node[2*x+2]);

		}

	}



	//データ取得 [a,b)

	SINT64 getdata(SINT64 a, SINT64 b, SINT64 k = 0, SINT64 l = 0, SINT64 r = -1) {

		if (r < 0) {

			r = size;

		}



		//要求範囲外

		if ((r <= a) || (b <= l)) {

			return 0;

		}

		//完全要求区間内

		if ((a <= l) && (r <= b)) {

			return node[k];

		}



    	SINT64 vl = getdata(a, b, 2*k+1, l, (l+r)/2);

    	SINT64 vr = getdata(a, b, 2*k+2, (l+r)/2, r);

    	return jugdement(vl, vr);

	}



	//表示

	void disp() {

		rep(i,0,size) {

			puts(node[size-1+i]);

		} cout << endl;

	}



	void alldisp() {

		SINT64 cnt = 0;

		SINT64 end = 2;

		

		while (1) {

			puts(node[cnt]);

			if (cnt == end-2) {

				end *= 2;

				cout << endl;

			}

			cnt++;

			if (cnt == size*2-1) {

				break;

			}

		}	

	}

};



SegTree seg(N);

 */



/* 最大フロー最小カット

class Dinic {

	struct EDGE {

		SINT64 to;

		SINT64 cap;

		SINT64 rev;

	};

	vector<vector<EDGE>> G;

	vector<SINT64> level;

	vector<SINT64> root;

	SINT64 N;

 

public:

	Dinic(SINT64 n) {

		N = n;

		G.resize(N);

		level.resize(N);

	}

	

	void add(SINT64 a, SINT64 b, SINT64 cap) {

		G[a].emplace_back((EDGE){b,cap,(SINT64)G[b].size()});

		G[b].emplace_back((EDGE){a,0,(SINT64)G[a].size()-1});

	}

 

	void bfs(SINT64 s) {

		level[s] = 0;

		queue<SINT64> q;

		q.push(s);

		while(q.size() != 0) {

			SINT64 buf = q.front();

			q.pop();

			rep(i,0,G[buf].size()) {

				EDGE now = G[buf][i];

				if ((now.cap > 0) && (level[now.to] == -1)) {

					level[now.to] = level[buf]+1;

					q.push(now.to);

				}

			}

		}

	}

 

	SINT64 dfs(SINT64 now, SINT64 g, SINT64 flow) {

		if (now == g) return flow;

		rep(i,root[now],G[now].size()) {

			EDGE buf = G[now][i];

			root[now] = i;							//dsf進捗更新

			if ((buf.cap > 0) && (level[buf.to] > level[now])) {

				SINT64 mi = MIN(buf.cap,flow);

				SINT64 nowf = dfs(buf.to,g,mi);

				if (nowf > 0) {

					G[now][i].cap -= nowf;			//順経路に容量削減

					G[buf.to][buf.rev].cap += nowf;	//逆経路に容量追加

					return nowf;					//今回探索のFLOW追加数

				}

			}

		}

		return 0;

	}

 

	SINT64 act(SINT64 s, SINT64 g) {

		SINT64 cnt = 0;								//最大FLOWカウント

		if (s == g) return cnt;						//スタート＝ゴールは例外

		while(1) {

			level.assign(N,-1);						//sからの最短距離初期化

			root.assign(N,0);						//dsf進捗初期化

			bfs(s);

			if (level[g] == -1) break;				//gへ到達不可

			while(1) {

				SINT64 flow;

				flow = dfs(s,g,INF64);

				if (flow == 0) break;

				cnt += flow;

			}

		}

		return cnt;

	}

};

*/



/* ダイクストラ

class Dijkstra {	

	vector<vector<Pll>> G;

	vector<SINT64> dist;

 

public:

	Dijkstra(SINT64 n) {

		G.resize(n);

		dist.resize(n, INF64);

	}

	

	void add(SINT64 a, SINT64 b, SINT64 cost) {

		G[a].emplace_back(Pll(b,cost));

	}



	void form(SINT64 s) {

		priority_queue<Pll, vector<Pll>, greater<Pll>> q;

		q.push(Pll(0,s));						//cost,位置

		while(q.size() != 0) {

			Pll now = q.top();

			q.pop();

			if (dist[now.S] == INF64) {

				dist[now.S] = now.F;

				rep(i,0,G[now.S].size()) {

					Pll buf = G[now.S][i];

					if (dist[buf.F] == INF64) {

						q.push(Pll(buf.S+now.F,buf.F));

					}

				}

			}

		}

	}

	

	//form()で構築したsからの距離を返す

	SINT64 get_dist(SINT64 a) {

		if (dist[a] == INF64) {

			return -1;			//到達不可

		} else {

			return dist[a];

		}

	}

};

*/



/* LCA

class Lca {

	vector<vector<SINT64>> G;

	vector<vector<SINT64>> D;	//ダブリング

	vector<SINT64> depth;

	SINT64 N;

	SINT64 LOG_N;

 

public:

	Lca(SINT64 n) {

		N = n;

		LOG_N = floor(log2(N));

		G.resize(N);

		D.resize(N);

		depth.resize(N,-1);

	}

	

	void add(SINT64 a, SINT64 b) {

		G[a].emplace_back(b);

		G[b].emplace_back(a);

	}

 

	void bfs(SINT64 s) {

		depth[s] = 0;

		D[s].emplace_back(-1);

		queue<SINT64> q;

		q.push(s);

		while(q.size() != 0) {

			SINT64 now = q.front();

			q.pop();

			rep(i,0,G[now].size()) {

				SINT64 next = G[now][i];

				if (depth[next] == -1) {

					depth[next] = depth[now]+1;

					D[next].emplace_back(now);

					q.push(next);

				}

			}

		}

	}

 

	//頂点のsからのダブリング構築

	void form(SINT64 s) {

		bfs(s);

		rep(i,1,LOG_N+1) {

			rep(j,0,N) {

				SINT64 buf = D[j][i-1];

				if (buf == -1) {

					D[j].emplace_back(-1);

				} else {

					D[j].emplace_back(D[buf][i-1]);

				}

			}

		}

	}

 

	//aのx上の頂点を求める

	SINT64 get(SINT64 a, SINT64 x) {	

		rrep(i,LOG_N,0) {

			if (((x >> i) & 1) == 1) {

				a = D[a][i];

				if (a == -1) return -1;

			}

		}

		return a;

	}

 

	//aとbの共通祖先を求める

	SINT64 get_lca(SINT64 a, SINT64 b) {

		if (depth[a] < depth[b]) swap(a,b);

		SINT64 diff = depth[a] - depth[b];

		a = get(a,diff);					//aのx上の頂点を求める

		if (a == b) return a;

		rrep(i,LOG_N,0) {

			if (D[a][i] != D[b][i]) {

				a = D[a][i];

				b = D[b][i];

			}

		}	

		return D[a][0];

	}



	//aとbの共通祖先までの距離の合計を求める

	SINT64 get_dist(SINT64 a, SINT64 b) {

		SINT64 buf = get_lca(a,b);

		return depth[a] + depth[b] - depth[buf]*2;

	}

};

*/



/* ベルマンフォード

class Bellman {

	struct EDGE {

		SINT64 from;

		SINT64 to;

		SINT64 cost;

	};

	vector<EDGE> edges;

	vector<SINT64> dist;

	SINT64 N;

 

public:

	Bellman(SINT64 n) {

		N = n;

		dist.resize(n, INF64);

	}

	

	void add(SINT64 from, SINT64 to, SINT64 cost) {

		edges.emplace_back((EDGE){from,to,cost});

	}

 

	//sで構築したt迄の距離取得

	SINT64 get_dist(SINT64 t) {

		//到達不可はINF64

		return dist[t];

	}

 

	//構築

	//負の閉路無し : 0

	//負の閉路有り : 1

	//負の閉路有るが目的地gの更新は停止 : 2

	SINT64 form(SINT64 s, SINT64 g) {

		dist[s] = 0;

		SINT64 cnt = 0;

		SINT64 check = 0;

		while(1) {

			SINT64 renew = 0;

			rep(i,0,edges.size()) {

				EDGE e = edges[i];

				if (dist[e.from] != INF64) {

					if (dist[e.to] > dist[e.from] + e.cost) {

						renew = 1;

						dist[e.to] = dist[e.from] + e.cost;

					}

				}

			}

			if (renew == 0) return 0;



			//N回更新後のgの距離と 2N回更新後のgの距離を比較

			if (cnt == N) check = dist[g];

			if (cnt > 2*N) {

				if (check == dist[g]) return 2;

				return 1;

			}

			cnt++;

		}

	}

};

*/



/*コンビネーション

class Comb {

	vector<SINT64> base;

	SINT64 N;

 

public:

	Comb (SINT64 n) {

		N = n+5;

		base.resize(N);

		base[0] = 1;

		rep(i,1,N) {

			base[i] = base[i-1]*i;

			base[i] %= MOD;

		}

	}

	

	SINT64 get_comb(SINT64 a, SINT64 b) {

		SINT64 ans = 0;

		SINT64 aa = base[a] * modpow(base[a-b], MOD - 2) % MOD;

		ans = aa * modpow(base[b], MOD - 2) % MOD;

		return ans;

	}



	SINT64 modpow(SINT64 a, SINT64 p) {

		if (p == 0) return 1;

		if (p % 2 == 0) {

			SINT64 halfP = p / 2;

			SINT64 half = modpow(a, halfP);

			return half * half % MOD;

		} else {

			return a * modpow(a, p - 1) % MOD;

		}

	}

};

*/
