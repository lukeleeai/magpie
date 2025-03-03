// InterestingLSY

// 2659723130

// 《幽灵公主》是真的好看！

#include "stdc++.h"

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



// Template

#define _cl class

#define _tp template

#define _tyn typename



// Pair

#define Mp make_pair

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

	#define bs 1048576

	char buf[bs]; int p;

	il InputReader(){ p = bs; }

	il void Flush(){ p = 0; fread(buf,1,bs,stdin); }

	il char C(){ if(p >= bs) Flush(); return buf[p++]; }

	il char Readnum(){ char ch = C(); while( !isdigit(ch) && ch != '-' ) ch = C(); return ch; }

	il void Readalpha( char &c ){ c = C(); while( !isalpha(c) ) c = C(); }

	int operator() (){

		int ans = 0, fu = 1; char ch = Readnum();

		if( ch == '-' ) fu = -1, ch = C();

		while( ch >= '0' && ch <= '9' ){

			ans = ans*10 + ch-'0';

			ch = C();

		}

		return ans * fu;

	}

	ll Readll(){

		ll ans = 0LL, fu = 1LL; char ch = Readnum();

		if( ch == '-' ) fu = -1LL, ch = C();

		while( ch >= '0' && ch <= '9' ){

			ans = ans*10LL + ch-'0';

			ch = C();

		}

		return ans * fu;

	}

	il void Readstring( string &x ){

		x.clear(); char ch = C();

		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '#'  &&  ch != '.' ) ch = C();

		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '#'  ||  ch == '.' ){

			x += ch;

			ch = C();

		}

	}

	il void Readchstring( char s[] ){

		int len = 0; char ch = C();

		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) ch = C();

		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){

			s[len++] = ch;

			ch = C();

		}

		s[len] = '\0';

	}

	il void Specialread( char &c ){

		c = C();

		while( !isdigit(c) && !isalpha(c) && c != '#'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) c = C();

	}

	#undef bs

}In;

il void Read( int &x ){ x = In(); }

il void Read( int &x, int &y ){ x = In(); y = In(); }

il void Read( int &x1 , int &x2 , int &x3 ){ x1 = In(); x2 = In(); x3 = In(); }

il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ x1 = In(); x2 = In(); x3 = In(); x4 = In(); }

il void Read( ll &x ){ x = In.Readll(); }

il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }

il void Read( ll &x1 , ll &x2 , ll &x3 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); }

il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll(); }

_tp<_tyn T> void Read( T a[] , int st , int ed ){ Forx(i,st,ed) Read(a[i]); }

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

_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }



// Debug

#define B cerr << "BreakPoint" << endl;

#define O(x) cerr << #x << " " << (x) << endl;

#define o(x) cerr << #x << " " << (x) << "  ";

#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;

_tp<_tyn T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){

	if( s > t ) return;

	for( int i = s ; i < t ; i++ )

		cout << a[i] << sp;

	cout << a[t] << ed;

	cout.flush();

}

_tp<_tyn T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){

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

vc<int> Range( int l , int r ){

	vc<int> ret{};

	Forx(i,l,r) ret.Pb(i);

	return ret;

}

mt19937 Rand(0xe38195e38293);

// orz laofudasuan

// modified



namespace io{

	const int SIZE = (1 << 20) + 1;

	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;

	// print the remaining part

	inline void Flush(){

		fwrite(obuf,1,oS-obuf,stdout);

		oS = obuf;

	}

	// putchar

	inline void Putc(char x) {

		*oS ++ = x;

		if( oS == oT ) Flush();

	}

	// print a signed integer

	template <class I>

	inline void Print(I x) {

		if(!x){ Putc('0'); return; }

		// if( x < 0 ){ Putc('-'); x = -x; }

		while(x){

			qu[++ qr] = x % 10 + '0';

			x /= 10;

		}

		while(qr) Putc(qu[qr --]);

	}

	//no need to call flush at the end manually!

	struct Flusher_{~Flusher_(){Flush();}}io_flusher_;

}

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////

const int MAXN = 128;



int n,m;

pii a[MAXN][MAXN];



#define Row(x) (((x)-1)/m+1)

#define Col(x) (((x)-1)%m+1)

#define Dec(x) ((pii){Row(x),Col(x)})

#define Enc(p) (((p).F-1)*m+(p).S)



il void PrintAns(){

	For(i,n){

		For(j,m)

			printf("%d ",Enc(a[i][j]));

		putchar(10);

	}

}

il void Dbg(){

	#ifndef intLSY

		return;

	#endif

	printf("-----------------\n");

	For(i,n){

		For(j,m)

			printf("(%d,%d) ",a[i][j].F,a[i][j].S);

		putchar(10);

	}

	putchar(10);

}



const int MAXD = 256;



int gf[MAXD], bf[MAXD];

bool vis[MAXD];

multiset<int> e[MAXD];

vc<pii> nums[MAXN][MAXN];



bool Dfs( int pos ){

	vis[pos] = 1;

	for( auto v : e[pos] ){

		if(vis[bf[v]]) continue;

		if( !bf[v] or Dfs(bf[v]) ){

			bf[v] = pos;

			gf[pos] = v;

			return true;

		}

	}

	return false;

}



void Match(){

	Ms(gf); Ms(bf);

	For(i,n){

		Ms(vis);

		bool succeed = Dfs(i);

		assert(succeed);

	}

}



void SectionI(){

	For(i,n) For(j,m){

		e[i].insert(a[i][j].F);

		nums[i][a[i][j].F].Pb(a[i][j]);

	}

	For(col,m){

		Match();

		For(i,n){

			int use = gf[i];

			a[i][col] = nums[i][use].back();

			nums[i][use].pop_back();

			e[i].erase(e[i].find(use));

		}

		// Dbg();

	}

	PrintAns();

	Dbg();

}



void SectionII(){

	For(col,m){

		static vc<pii> tmp;

		tmp.clear();

		For(i,n) tmp.Eb(a[i][col]);

		sort(All(tmp),[]( const pii &a , const pii &b ){ return a.F < b.F; });

		For(i,n) a[i][col] = tmp[i-1];

	}

	PrintAns();

	Dbg();

}



int main(){

	FILEIO();



	Read(n,m);

	For(i,n) For(j,m){

		iRead(x);

		a[i][j] = Dec(x);

	}

	// Dbg();



	SectionI();



	SectionII();



	END();

}
