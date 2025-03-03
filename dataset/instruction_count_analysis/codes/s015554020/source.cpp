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

const std::vector<std::pair<int, int>> DXDY = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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

#define ALL(A) (A).begin(), (A).end()

// 座標圧縮 (for vector) : ソートしてから使うのが一般的 ; SORT(A) => COORDINATE_COMPRESSION(A)

#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())







template <class T> inline int argmin(std::vector<T> vec){return min_element(vec.begin(), vec.end()) - vec.begin();}

template <class T> inline int argmax(std::vector<T> vec){return max_element(vec.begin(), vec.end()) - vec.begin();}

template <class S, class T> inline void chmax(S &a, T b){if(a < b) a = b;}

template <class S, class T> inline void chmin(S &a, T b){if(a > b) a = b;}

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













int main(void){

    int h, w, n; scanf("%d%d%d", &h, &w, &n);

    int sx, sy; scanf("%d%d", &sx, &sy); sx--; sy--;

    char S[n], T[n]; scanf("%s\n%s", S, T);

    // 落ちる端 : 盤面 縦 : 0, 1, 2, ...., h-1 および 横 : 0, 1, 2, ..., w-1

    int l = -1, r = w, u = -1, d = h;

    rREP(i, n){

        // 落とされたくない側

        switch(T[i]){

            case 'L':

                if(r != w) r++;

                break;

            case 'R':

                if(l != -1) l--;

                break;

            case 'U':

                if(d != h) d++;

                break;

            case 'D':

                if(u != -1) u--;

                break;

        }

        // 落としたい側

        switch (S[i]) {

            case 'L':

                l++;

                break;

            case 'R':

                r--;

                break;

            case 'U':

                u++;

                break;

            case 'D':

                d--;

                break;

        }

        if(r-l <= 1 or d-u <= 1) break;

    }

    puts((l < sy and sy < r and u < sx and sx < d) ? "YES" : "NO");

    return 0;

}