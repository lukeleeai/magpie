#include"stdc++.h"

using namespace std;

typedef  long long int ll;

const ll mod = 1e9+7;

const ll mod1 = 998244353;

const ll inf = 9e18+5;

#define rep(i,a,b) for(ll i=a;i<b;i++)



void swap(ll &a , ll &b){

    ll t = a;

    a = b;

    b = t;

}



ll min(ll a, ll b){

    if(a<b)return a;

    return b;

}



ll max(ll a, ll b){

    if(a>b)return a;

    return b;

}



 ll pow(ll a, ll b) {

    a %= mod;

    ll ans = 1;

    while (b > 0) {

        if (b & 1)

            ans = ans * a % mod;

        a = a * a % mod;

        b /= 2;

    }

    return ans;

}





//*********Debugger template starts***********************//

#ifndef ONLINE_JUDGE

vector<string> vec_splitter(string s) {

	s += ',';

	vector<string> res;

	while(!s.empty()) {

		res.push_back(s.substr(0, s.find(',')));

		s = s.substr(s.find(',') + 1);

	}

	return res;

}

void debug_out(

vector<string> __attribute__ ((unused)) args,

__attribute__ ((unused)) int idx,

__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }

template <typename Head, typename... Tail>

void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {



	if(idx == 0) {

        cerr << "Line(" << LINE_NUM << ") ";

	}

	stringstream ss; ss << H;

	cerr << " [" << args[idx] << " = " << ss.str() <<"] ";

	debug_out(args, idx + 1, LINE_NUM, T...);



}

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

#else

#define debug(...)

#endif



#ifndef ONLINE_JUDGE

#define n_l '\n'

#define dbg(...) cerr <<"Line("<<__LINE__<<") " "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl

template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cerr << to_string(H) << " | "; dbgm(T...); }

#else

    #define dbg(...)

#endif





//*********Debugger template ends ***********************//





int main() {





  ios_base :: sync_with_stdio(0);

  cin.tie(0);

  ll X;

  ll st;

  cin>>X;

  st = X;

  ll ans = 0;

  ll temp;

  X = 100;

  while(1){

    temp = X/100;

    X += temp;

    ans++;

    if(X >=st)break;

  }

  cout<<ans;











  return 0;

}
