/*

 　　　　　／＞　 フ

 　　　　　| 　_　 _|

 　 　　　／`ミ _x 彡

 　　 　 /　　　 　 |

 　　　 /　  ヽ　　 ?

 　／￣|　　 |　|　|

 　| (￣ヽ＿_ヽ_)_)

 　＼二つ

*/



#include <queue>

#include <vector>

#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#define MP make_pair

#define ll long long

#define fi first

#define se second

using namespace std;



template <typename T>

void read(T &x) {

    x = 0; bool f = 0;

    char c = getchar();

    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;

    for (;isdigit(c);c=getchar()) x=x*10+(c^48);

    if (f) x=-x;

}



template<typename F>

inline void write(F x, char ed = '\n') {

    static short st[30];short tp=0;

    if(x<0) putchar('-'),x=-x;

    do st[++tp]=x%10,x/=10; while(x);

    while(tp) putchar('0'|st[tp--]);

    putchar(ed);

}



template <typename T>

inline void Mx(T &x, T y) { x < y && (x = y); }



template <typename T>

inline void Mn(T &x, T y) { x > y && (x = y); }



%:define Pa pair<int, int> 

const int N = 105000;

const int inf = 1e9;

priority_queue<Pa> q1, q2, q3, q4;

int x[N], y[N], z[N];

int vis[N], A, B, C, n;



Pa get(priority_queue<Pa> &q) { while (vis[q.top().se]) q.pop(); return q.top(); }



int main() {

    read(A), read(B), read(C), n = A + B + C; ll ans = 0;

    for (int i = 1;i <= n; i++) {

        read(x[i]), read(y[i]), read(z[i]);

        ans += z[i], x[i] -= z[i], y[i] -= z[i];

        q1.push(MP(x[i], i)), q2.push(MP(y[i], i));

    }

    /* write(ans); */

    /* for (int i = 1;i <= n; i++) write(x[i], ' '), write(y[i]); */

    while (A || B) {

        Pa t1 = get(q1), t2 = get(q2);

        if (!A) { q3.empty() ? t1.fi = -inf : t1.fi += q3.top().fi; }

        if (!B) { q4.empty() ? t2.fi = -inf : t2.fi += q4.top().fi; }

        if (t1.fi > t2.fi) {

            vis[t1.se] = 1, ans += t1.fi;

            if (A) A--;

            else { B--; Pa t = q3.top(); q3.pop(); q4.push(MP(-t.fi, t.se)); }

            q3.push(MP(y[t1.se] - x[t1.se], t1.se));

        }

        else {

            vis[t2.se] = 1, ans += t2.fi;

            if (B) B--;

            else { A--; Pa t = q4.top(); q4.pop(); q3.push(MP(-t.fi, t.se)); }

            q4.push(MP(x[t2.se] - y[t2.se], t2.se));

        }

    }

    write(ans);

    return 0;

}