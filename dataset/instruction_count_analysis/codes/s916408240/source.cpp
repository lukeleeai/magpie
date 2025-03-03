#define _USE_MATH_DEFINES

#include "stdc++.h"

using namespace std;



//template

#define rep(i,a,b) for(int i=(a);i<(b);i++)

#define rrep(i,a,b) for(int i=(a);i>(b);i--)

#define ALL(v) (v).begin(),(v).end()

typedef long long int ll; typedef pair<ll, ll> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}

const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;

const int mod = 998244353; //1e9+7;

struct Mint {

   int val;

   Mint inv() const {

       int tmp, a = val, b = mod, x = 1, y = 0;

       while(b) tmp = a / b, a -= tmp * b, swap(a, b), x -= tmp * y, swap(x, y);

       return Mint(x);

   }

public:

   Mint() :val(0) {}

   Mint(ll x) :val(x >= 0 ? x % mod : x % mod + mod) {}

   int mtoi() { return this->val; }

   Mint pow(ll t) { Mint res = 1,b=*this; while(t){if(t&1)res *= b;b *= b;t >>= 1;}return res; }

   Mint& operator+=(const Mint& x) { if ((val += x.val) >= mod) val -= mod; return *this; }

   Mint& operator-=(const Mint& x) { if ((val += mod - x.val) >= mod) val -= mod; return *this; }

   Mint& operator*=(const Mint& x) { val = (ll)val * x.val % mod; return *this; }

   Mint& operator/=(const Mint& x) { return *this *= x.inv(); }

   bool operator==(const Mint& x) const { return val == x.val; }

   bool operator!=(const Mint& x) const { return val != x.val; }

   bool operator<(const Mint& x) const { return val < x.val; }

   bool operator<=(const Mint& x) const { return val <= x.val; }

   bool operator>(const Mint& x) const { return val > x.val; }

   bool operator>=(const Mint& x) const { return val >= x.val; }

   Mint operator+(const Mint& x) const { return Mint(*this) += x; }

   Mint operator-(const Mint& x) const { return Mint(*this) -= x; }

   Mint operator*(const Mint& x) const { return Mint(*this) *= x; }

   Mint operator/(const Mint& x) const { return Mint(*this) /= x; }

};

struct factorial {

   vector<Mint> Fact, Finv;

public:

   factorial(int maxx) {

       Fact.resize(maxx+1,Mint(1)),Finv.resize(maxx+1); rep(i,0,maxx)Fact[i+1]=Fact[i]*Mint(i+1);

       Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*Mint(i);

   }

   Mint fact(int n,bool inv) { if(inv) return Finv[n]; else return Fact[n]; }

   Mint nPr(int n,int r) { if(n<0||n<r||r<0) return Mint(0); else return Fact[n]*Finv[n-r]; }

   Mint nCr(int n,int r) { if(n<0||n<r||r<0) return Mint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }

};

//template end



int bit[200010],n;

void add(int i,int x){

	i++;

	while(i<=n){

		bit[i]+=x;

		i+=(i&(-i));

	}

}

ll sum(int i){

	i++;ll s=0;

	while(i){

		s+=bit[i];

		i-=(i&(-i));

	}

    return s;

}



int main(){

   cin>>n;

   vector<int> x(n),y(n);

   vector<P> a(n);

   rep(i,0,n){

   	cin>>x[i]>>y[i];

   	a[i]={x[i],y[i]};

   }

   sort(ALL(x)); sort(ALL(y));

   rep(i,0,n){

   	int xidx=lower_bound(ALL(x),a[i].first)-x.begin();

   	int yidx=lower_bound(ALL(y),a[i].second)-y.begin();

   	a[i]={xidx,yidx};

   }

   sort(ALL(a));

   Fill(bit,0); int num[200010][4]={};

   rep(i,0,n){

   	int f=sum(a[i].second-1);

   	int g=i-sum(a[i].second);

   	num[i][0]=f;

   	num[i][1]=g;

   	add(a[i].second,1);

   }

   Fill(bit,0);

   rrep(i,n-1,-1){

   	int g=sum(a[i].second-1);

   	int f=(n-1-i)-sum(a[i].second);

     cerr<<sum(a[i].second)<<endl;

   	num[i][2]=f;

   	num[i][3]=g;

   	add(a[i].second,1);

   }

   Mint ans=0,base=2;

   rep(i,0,n){

     rep(j,0,4)cerr<<num[i][j];

   	ans+=base.pow(n)-1;

   	ans-=base.pow(num[i][0]+num[i][1]);

   	ans-=base.pow(num[i][0]+num[i][3]);

   	ans-=base.pow(num[i][1]+num[i][2]);

   	ans-=base.pow(num[i][2]+num[i][3]);

   	ans+=base.pow(num[i][0]);

   	ans+=base.pow(num[i][1]);

   	ans+=base.pow(num[i][2]);

   	ans+=base.pow(num[i][3]);

   }

  printf("%d\n",ans.mtoi()); 

   return 0;

}
