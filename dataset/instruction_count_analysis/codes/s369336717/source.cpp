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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



#define pr printf

#define re return

#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)





int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }



stack<long long> sta;   

queue<long long> que;

deque<long long> dque;



set <string> s_set;







ll dp[13][100010]={};

//ll dp[100010][3];





//最大公約数

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

//最小公倍数

int lcm(int x, int y) { return x / gcd(x, y) * y; }

//最大公約数 複数個

int gcd(const vector<int> &v) {

	int ret = v[0];

	for (int i = 1; i < v.size(); i++)

		ret = gcd(ret, v[i]);

	return ret;

}

//最小公倍数 複数個

int lcm(const vector<int> &v) {

	int ret = v[0];

	for (int i = 1; i < v.size(); i++)

		ret = lcm(ret, v[i]);

	return ret;

}



struct Student {

  string name;

  int no, point;

};



// a < b ならtrueを返す

bool comp(const Student& a, const Student& b) {

  if (a.name != b.name)

    return a.name < b.name; // 高い順に並べたいので演算子を逆に

  if (a.point != b.point)

    return a.point > b.point; // 同様に比較演算子を反転

  return a.no < b.no;

}



//	文字列置換

std::string replaceOtherStr(std::string &replacedStr, std::string from, std::string to) {

    const unsigned int pos = replacedStr.find(from);

    const int len = from.length();

 

    if (pos == std::string::npos || from.empty()) {

        return replacedStr;

    }

 

    return replacedStr.replace(pos, len, to);

}





//	素因数分解

void countPN(int n, std::vector<int> &count)//nを素因数に分解し、countを更新

{

	int m = n;

	for(int i=2 ; i*i<=n ; ++i)

	{

		while(m%i == 0)

		{

			m /= i;

			count[i]++;

		}

		if(m==1) break;

	}

	if(m!=1) count[m]++;



}



//	コンビネーション

const int MAX_N = 2000000;

ll inv[MAX_N + 10];

ll fac[MAX_N + 10], facInv[MAX_N + 10];

class MATH{

public:

    MATH(){

        inverse();

        factroial();

    }

    ll nCk(ll n, ll k){// n! / k!*(n-k)!

        if(k < 0 || k > n) return 0;

        ll ret = fac[n];

        (ret *= facInv[k]) %= mod;

        (ret *= facInv[n - k]) %= mod;

        return ret;

    }

    ll nHk(ll n, ll k){// nHk = n+k-1 C k = (n+k-1)! / k! * (n-1)!

        if(n == 0 && k == 0) return 1;

        ll ret = fac[n + k - 1];

        (ret *= facInv[k]) %= mod;

        (ret *= facInv[n - 1]) %= mod;

        return ret;

    }

    ll nPk(ll n, ll k){//nPk = n! / (n-k)!

        if(k < 0 || k > n) return 0;

        ll ret = fac[n];

        (ret *= facInv[n - k]) %= mod;

        return ret;

    }

private:

    void inverse(void){

        inv[1] = 1;

        for (int i = 2; i <= MAX_N; ++i){

            // inv[i] = mod - (mod / i) * inv[mod % i] % mod;

            inv[i] = inv[mod % i] * (mod - mod / i) % mod;

        }

    }

    void factroial(void){

        fac[0] = facInv[0] = 1;

        for (int i = 1; i <= MAX_N; ++i){

            fac[i] = (fac[i - 1] * i) % mod;

            facInv[i] = (facInv[i - 1] * inv[i]) % mod;

        }

    }

};



//	いもす法

std::vector<int> getCumSum(std::vector<int> baseImos){

    int baseSize = baseImos.size();

    std::vector<int> cumSum(baseSize, 0);

    

    cumSum[0] = baseImos[0];

    for(int i=1; i<baseSize; ++i){

        cumSum[i] = cumSum[i-1] + baseImos[i];

    }

    return cumSum;

}



typedef vector<int> vi;



//	DFS		(ABC026 A  高橋君の給料)

/*

int dfs(vector<vi> ch, int u){

	if(ch[u].empty()) return 1;

	int mi = INF, ma = 0;

	for(int v : ch[u]){

		int r = dfs(ch, v);

		mi = MIN(mi, r);

		ma = MAX(ma, r);

	}

	return mi + ma + 1;

}

*/



//	DFS		(ABC026 C  高橋君の給料)



void dfs(int n, string s) {

  if (n == 0) cout << s << endl;

  else {

    dfs(n-1, s + "a");

    dfs(n-1, s + "b");

    dfs(n-1, s + "c");

  }

}



//	DFS		(ABC029 C  Brute-force Attack)



vector<int> g[200020];

int s[200020];

bool used[200020];

void dfs(int x){

	used[x]=1;

	for(auto y:g[x]){

		if(used[y]) continue;

		s[y]+=s[x];

		dfs(y);

	}

}



long long A,B,C,D,E,F,G,H,I,J,L,N,M,K,O,P,Q,R,S,T,U,V,W,X,Y,Z;

long long sum,sum1,sum2,sum3,sum4;

long long flg,flg1,flg2,flg3,cnt,cnt1,cnt2,cnt3,cnt4;

long long wk,wk1,wk2,wk3,wk4;

long long ans;



bool f;



long long weight[110], value[110]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に

ll a[100010][3]; // a[i], b[i], c[i] をそれぞれまとめて a[i][0], a[i][1], a[i][2] にしてしまう

long long n,h[100005];

vector<long long> p, c;

int vis[200001];





int main(){

	

	cin.tie(nullptr);

	ios::sync_with_stdio(false);



	long long max,max1;

	long long min,min1;



	sum=sum1=sum2=sum3=sum4=0;

	flg=flg1=flg2=flg3=cnt=cnt1=cnt2=cnt3=cnt4=0;

	max=max1=0;

	wk=wk1=wk2=wk3=wk4=0;

	ans=0;

	min=min1=INF;



	

	

	//**************************ここからスタート******************************************

	std::cin >> N;

	//std::cin >> N >> M;

	//std::cin >> N >> M >> K;

	//std::cin >> N >> K;

	//std::cin >> A >> B;

	//std::cin >> A >> B >> C;

	

	//●●●  ペア関連

	

	vector<pair<long long, long long> > p(N);

	for(long long i=0; i<N; i++){

		long long a, b;

		cin >> a >> b;

		p[i] = make_pair(b, a);

	}

    

	sort(p.begin(), p.end());

	//sort(p.begin(), p.end(),greater<pair<long long,long long> >());

	

	//●●●	通常（ペア用）

	

	for(long long i=0; i<N; i++){

		sum+=p[i].se;

		if(sum>p[i].fi){

			puts("No");

			re 0;

		}

	}

	puts("Yes");

	re 0;

}	


