#include <iostream>

#include <list>

#include <set>

#include <deque>

#include <queue>

#include <stack>

#include <vector>

#include <algorithm>

#include <map>

#include <chrono>

#include <math.h>

using namespace std;



using lli = long long int;

using Vint = std::vector<int>;

using Vlli = std::vector<lli>;

using Wint = std::vector<Vint>;

using Wlli = std::vector<Vlli>;

using Vbool = std::vector<bool>;

using Wbool = std::vector<Vbool>;

using pii = std::pair<int, int>;

using pll = std::pair<lli, lli>;

template <class T>

using Vec = std::vector<T>;



constexpr int MOD = 1e9 + 7;

constexpr int INFi = 2e9 + 1;

constexpr lli INFl = (lli)(9e18) + 1;

const vector<pii> DXDY = {std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)};

constexpr char BR = '\n';



#define DEBUG(x) std::cerr << #x << " = " << x << '\n';

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

#define FOReq(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))

#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); --(i))

#define FORstep(i, a, b, step) for(int (i) = (a); i < (b); i += (step))

#define REP(i, n) FOR(i, 0, n)

#define rREP(i, n) rFOR(i, 0, (n-1))

#define vREP(ele, vec) for(auto &(ele) : (vec))

#define vREPcopy(ele, vec) for(auto (ele) : (vec))

#define SORT(A) std::sort((A).begin(), (A).end())

#define RSORT(A) std::sort((A).rbegin(), (A).rend())

// 座標圧縮 (for vector) : ソートしてから使うのが一般的 ; SORT(A) => COORDINATE_COMPRESSION(A)

#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())







template <class T> inline int argmin(std::vector<T> vec){return min_element(vec.begin(), vec.end()) - vec.begin();}

template <class T> inline int argmax(std::vector<T> vec){return max_element(vec.begin(), vec.end()) - vec.begin();}

template <class T> inline void chmax(T &a, T b){if(a < b) a = b;}

template <class T> inline void chmin(T &a, T b){if(a > b) a = b;}

template <class T> inline void reverseSORT(Vec<T> &Array){

  std::sort(Array.begin(), Array.end(), std::greater<T>());

}

inline int BitI(int k){return 1 << k;}

inline lli BitL(int k){return 1LL << k;}

inline void putsDouble(double d){printf("%.16lf\n", d);}

inline int toInt(const string &s){int res = 0; for(char a : s) res = 10 * res + (a - '0'); return res;}

inline long long int toLong(const string &s){lli res = 0; for(char a : s) res = 10 * res + (a - '0'); return res;}

template <class T> inline std::string toString(T n){

  if(n == 0) return "0";

  std::string res;

  if(n < 0){n = -n;while(n != 0){res += (char)(n % 10 + '0'); n /= 10;}

  std::reverse(res.begin(), res.end()); return '-' + res;}

  while(n != 0){res += (char)(n % 10 + '0'); n /= 10;} std::reverse(res.begin(), res.end()); return res;

}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~







lli power(lli a, int n){

    if(n == 0) return 1;

    lli u = power(a, n / 2);

    u *= u; u %= MOD;

    if(n % 2 == 0) return u;

    return (u * a) % MOD;

}



lli inv(lli a){

    return power(a, MOD - 2);

}





int main(void){

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    const int N = n * m; const int KKK = max(N, 6);

    Vlli INVS(KKK + 1);

    INVS[0] = 1; INVS[1] = 1;

    for(int i = 2; i <= KKK; ++i) INVS[i] = inv(i);

    Vlli S(KKK + 1), R(KKK + 1);

    S[0] = 1; R[0] = 1;

    for(int i = 1; i <= KKK; ++i){

        S[i] = (i * S[i - 1]) % MOD;

        R[i] = (INVS[i] * R[i-1]) % MOD;

    }

    lli ans = S[N - 2];

    ans *= R[k - 2]; ans %= MOD;

    ans *= R[N - k]; ans %= MOD;

    lli u = (m * m) % MOD;

    u *= n-1; u %= MOD;

    u *= n; u %= MOD;

    u *= n+1; u %= MOD;

    lli v = (n * n) % MOD;

    v *= m-1; v %= MOD;

    v *= m; v %= MOD;

    v *= m+1; v %= MOD;

    ans *= ((u + v) % MOD); ans %= MOD;

    ans *= INVS[6]; ans %= MOD;

    printf("%lld\n", ans);

    return 0;

}