// InterestingLSY

// codeforces&github: interestingLSY, qq: 2659723130

// 《幽灵公主》是真的好看！

#ifdef intLSY

#include <intlsy/stdc++.h>

#else

#include "stdc++.h"

#endif

#include <bits/c++0x_warning.h>

using namespace std;

#define il inline

#define elif else if



// Type

#define ld double

#define ll long long

#define ull unsigned ll



// Vector

#define vc vector

#define Pb push_back

#define Pf push_front

#define Eb emplace_back

#define All(x) x.begin(),x.end()

#define AllRev(x) x.rbegin(),x.rend()



// Memory

#define Ms(_data) memset(_data,0,sizeof(_data))

#define Msn(_data,_num) memset(_data,_num,sizeof(_data))



// Pair

#define F first

#define S second

#define pii pair<int,int>

#define pli pair<ll,int>

#define pil pair<int,ll>

#define pll pair<ll,ll>



// Loop

#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; ++(i) )

#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; ++(i) )

#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; ++(i) )

#define Forstep(i,j,k,st) for( int (i) = (j) ; (i) <= (k) ; (i) += (st) )

#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; --(i) )

#define fOR0(i,j) for( int (i) = (j)-1 ; (i) >= 0 ; --(i) )

#define fORx(i,j,k) for( int (i) = (k) ; (i) >= (j) ; --(i) )



// Read

struct InputReader{

	static constexpr int MAXSZ = 1048576;

	char buf[MAXSZ]; int p, ed;

	bool detectedEOF = false;

	il InputReader(){ p = MAXSZ; }

	il void Flush(){ p = 0; ed = fread(buf,1,MAXSZ,stdin); }

	il void GetChar( char &c ){

		if(p >= MAXSZ) Flush();

		if( p == ed ){ detectedEOF = true; }

		c = buf[p++];

	}

	il void ReadNum( char &c ){ GetChar(c); while( !isdigit(c) && c != '-' && !detectedEOF ) GetChar(c); }

	il void ReadAlpha( char &c ){ GetChar(c); while( !isalpha(c) && !detectedEOF ) GetChar(c); }

	il void ReadInt( int &ans ){

		ans = 0; int nega = 1;

		char c; ReadNum(c); if(detectedEOF) return;

		if( c == '-' ){

			nega = -1;

			GetChar(c);

		}

		while( isdigit(c) && !detectedEOF ){

			ans = ans*10 + c-'0';

			GetChar(c);

		}

		ans *= nega;

	}

	il void Readll( ll &ans ){

		ans = 0; int nega = 1;

		char c; ReadNum(c); if(detectedEOF) return;

		if( c == '-' ){

			nega = -1;

			GetChar(c);

		}

		while( isdigit(c) && !detectedEOF ){

			ans = ans*10 + c-'0';

			GetChar(c);

		}

		ans *= nega;

	}

	il void ReadString( string &x ){

		x.clear(); char ch; GetChar(ch);

		while( !isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.' && !detectedEOF ) GetChar(ch); if(detectedEOF) return;

		while( (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') && !detectedEOF ){

			x += ch;

			GetChar(ch);

		}

	}

	il void ReadCString( char s[] ){

		int len = 0; char ch; GetChar(ch);

		while( !isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.' && !detectedEOF ) GetChar(ch); if(detectedEOF) return;

		while( (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') && !detectedEOF ){

			s[len++] = ch;

			GetChar(ch);

		}

		s[len] = '\0';

	}

	il void SpecialRead( char &c ){

		GetChar(c); if(detectedEOF) return;

		while( !isdigit(c) && !isalpha(c) && c != '#' && c != '.' && c != '=' && c != 'B' && !detectedEOF ) GetChar(c);

	}

}In;

il void Read( int &x ){ In.ReadInt(x); }

il void Read( int &x, int &y ){ In.ReadInt(x); In.ReadInt(y); }

il void Read( int &x1 , int &x2 , int &x3 ){ In.ReadInt(x1); In.ReadInt(x2); In.ReadInt(x3); }

il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ In.ReadInt(x1); In.ReadInt(x2); In.ReadInt(x3); In.ReadInt(x4); }

il void Read( ll &x ){ In.Readll(x); }

il void Read( ll &x, ll &y ){ In.Readll(x); In.Readll(y); }

il void Read( ll &x1 , ll &x2 , ll &x3 ){ In.Readll(x1); In.Readll(x2); In.Readll(x3); }

il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ In.Readll(x1); In.Readll(x2); In.Readll(x3); In.Readll(x4); }

template<typename T> void Read( T a[] , int st , int ed ){ Forx(i,st,ed) Read(a[i]); }

#define iRead(k) int k; Read(k);

#define iRead2(a,b) iRead(a); iRead(b);

#define iRead3(a,b,c) iRead2(a,b); iRead(c);

#define iRead4(a,b,c,d) iRead2(a,b); iRead2(c,d);

#define lRead(k) ll k; Read(k);

#define lRead2(a,b) lRead(a); lRead(b);

#define lRead3(a,b,c) lRead2(a,b); lRead(c);

#define lRead4(a,b,c,d) lRead2(a,b); lRead2(c,d);



// File

#define Fin(a) freopen(a,"r",stdin)

#define Fout(a) freopen(a,"w",stdout)

il void FILEIO(){

	#ifdef intLSY

		Fin("in.in");

	#endif

}

il void FILEIO( string pname ){

	#ifndef intLSY

		Fin((pname+".in").c_str());

		Fout((pname+".out").c_str());

	#else

		Fin("in.in");

	#endif

}

il void FILEIO_OICONTEST( string pname ){

	Fin((pname+".in").c_str());

	#ifndef intLSY

		Fout((pname+".out").c_str());

	#endif

}

void Printtime(){

	#ifdef intLSY

		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;

		fprintf(stderr,"\n\nTime usage:\n%.0lf ms\n",_timeuse);

	#endif

}

void END(){ Printtime(); exit(0); }

template<typename T>void END( T mes ){ cout << mes << endl; END(); }



// Debug

#define B cerr << "BreakPoint" << endl;

#define O(x) cerr << #x << " " << (x) << endl;

#define o(x) cerr << #x << " " << (x) << "  ";

template<typename T0>

void P( T0 t0 ){

	cerr << t0 << endl;

}

template<typename T0, typename... Ts>

void P( T0 t0 , Ts... ts ){

	cerr << t0 << " ";

	P(ts...);

}

#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;

template<typename T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){

	if( s > t ) return;

	for( int i = s ; i < t ; i++ )

		cout << a[i] << sp;

	cout << a[t] << ed;

	cout.flush();

}

template<typename T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){

	if( t == -1 ) t = a.size()-1;

	for( int i = s ; i <= t ; i++ )

		cout << a[i] << sp;

	cout << ed;

	cout.flush();

}



// Optimize

#define Max(a,b) ((a)>(b)?(a):(b))

#define Min(a,b) ((a)<(b)?(a):(b))

#define Mymax(a,b) (a) = max((a),(b))

#define Mymin(a,b) (a) = min((a),(b))

#define MyMax(a,b) (a) = Max((a),(b))

#define MyMin(a,b) (a) = Min((a),(b))

#define INF (0x3f3f3f3f)

#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))

#define Sqr(x) ((x)*(x))

#define Lowbit(a) ((a)&(-(a)))

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////

constexpr int MAXN = 131072;

constexpr int LOG = 18;



int n;

vc<int> e[MAXN];

bool col[MAXN]; // col = 0: ok



int in[MAXN];

void GetDfsOrder(){

	function<void(int,int)> Dfs = [&]( int pos , int fa ){

		static int nowTime = 0;

		in[pos] = ++nowTime;

		for( auto v : e[pos] )

			if( v != fa )

				Dfs(v,pos);

	};

	Dfs(1,0);

}



int up[MAXN][LOG];

int dep[MAXN];

void LCAInit(){

	function<void(int,int)> Dfs = [&]( int pos , int fa ){

		dep[pos] = dep[fa] + 1;

		up[pos][0] = fa;

		For(i,LOG-1) up[pos][i] = up[up[pos][i-1]][i-1];

		for( auto v : e[pos] ){

			if( v == fa ) continue;

			Dfs(v,pos);

		}

	};

	Dfs(1,0);

}

int LCA( int a , int b ){

	if( dep[a] < dep[b] ) swap(a,b);

	fOR0(i,LOG){

		int v = up[a][i];

		if( dep[v] >= dep[b] )

			a = v;

	}

	if( a == b ) return a;

	fOR0(i,LOG){

		int u = up[a][i], v = up[b][i];

		if( u != v ){

			a = u;

			b = v;

		}

	}

	return up[a][0];

}

il int GetDis( int a , int b ){

	int lca = LCA(a,b);

	return dep[a] + dep[b] - 2*dep[lca];

}



vc<int> whites;

ll GetInitAnswer(){

	For(i,n) if(col[i]) whites.Eb(i);

	if( whites.empty() ) END(0);

	if( whites.size() == 1 ) END(1);

	sort(All(whites),[]( int a , int b ){

		return in[a] < in[b];

	});

	// Print(whites);



	ll initAns = 0;

	int last;



	static bool flags[MAXN];

	auto UpdatePath = [&]( int a , int b ){

		int lca = LCA(a,b);

		if( lca == b ) swap(a,b);

		if( lca == a ){

			flags[up[a][0]] ^= 1;

			flags[b] ^= 1;

		}else{

			flags[a] ^= 1;

			flags[b] ^= 1;

			col[lca] ^= 1;

		}

	};



	last = whites.back();

	for( auto u : whites ){

		col[u] ^= 1;

		UpdatePath(last,u);

		initAns += GetDis(last,u);

		last = u;

	}



	function<void(int,int)> Dfs = [&]( int pos , int fa ){

		for( auto v : e[pos] ){

			if( v == fa ) continue;

			Dfs(v,pos);

			flags[pos] ^= flags[v];

		}

		col[pos] ^= flags[pos];

	};



	Dfs(1,0);



	// Print(flags,1,n);

	// Print(col,1,n);

	For(i,n) initAns += col[i];

	return initAns;

}



bool ban[MAXN];

int newRoot;

void InitBan(){

	static queue<int> q;

	static int deg[MAXN];

	For(i,n) deg[i] = e[i].size();

	For(i,n) if( deg[i] == 1 and !col[i] ){

		q.push(i);

		ban[i] = true;

	}

	while(!q.empty()){

		int u = q.front();

		q.pop();

		for( auto v : e[u] ){

			if( ban[v] or col[v] ) continue;

			--deg[v];

			if( deg[v] == 1 ){

				ban[v] = true;

				q.push(v);

			}

		}

	}

	// Print(ban,1,n);

	newRoot = [&](){ For(i,n) if(!ban[i]) return i; }();

}



ll FuckTheWorld(){

	ll tot = GetInitAnswer();

	// O(tot);

	static int cost[MAXN];

	For(i,n) cost[i] = col[i] ? -2 : 0;



	ll ans = LINF;

	function<int(int,int)> Dfs = [&]( int pos , int fa ){

		ll mi = 0, secMi = 0;

		for( int v : e[pos] ){

			if( ban[v] or v == fa ) continue;

			ll res = Dfs(v,pos);

			if( res <= mi ){

				secMi = mi;

				mi = res;

			}else

				Mymin(secMi,res);

		}

		Mymin(ans,mi+secMi+cost[pos]);

		return mi+cost[pos];

	};

	Dfs(newRoot,0);

	// O(ans);



	ans += tot;

	// Mymin(ans,tot);



	return ans;

}



int main(){

	FILEIO();



	Read(n);

	For(i,n-1){

		iRead2(a,b);

		e[a].Eb(b);

		e[b].Eb(a);

	}

	For(i,n){

		char c; In.ReadAlpha(c);

		col[i] = c == 'W';

	}

	// if( n <= 10 ) assert(0);



	InitBan();

	// For(i,n){

	// 	cout << i << " | ";

	// 	for( auto v : e[i] ) cout << v << " ";

	// 	cout << endl;

	// }



	GetDfsOrder();

	LCAInit();



	ll ans = FuckTheWorld();

	cout << ans << endl;



	END();

}
