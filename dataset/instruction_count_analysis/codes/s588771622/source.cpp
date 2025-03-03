#include <algorithm>

#include <cmath>

#include <climits>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <fstream>

#include <iostream>

#include <list>

#include <map>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <vector>



using namespace std;



#define LOG(...) printf(__VA_ARGS__)

//#define LOG(...)

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

#define ALL(a) (a).begin(), (a).end()

#define RALL(a) (a).rbegin(), (a).rend()

#define EXIST(s, e) ((s).find(e) != (s).end())

#define SORT(c) sort((c).begin(), (c).end())

#define RSORT(c) sort((c).rbegin(), (c).rend())

#define CLR(a) memset((a), 0, sizeof(a))



typedef long long ll;

typedef unsigned long long ull;

typedef vector<bool> vb;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<vb> vvb;

typedef vector<vi> vvi;

typedef vector<vll> vvll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;



string expr;

int idx;

int p, q, r;



int form();



int paren() {

    int left = form();

    char op = expr[idx++];

    int right = form();

    idx++; // ')'



    if (left == right) {

        return left;

    }

    if (op == '+') {

        return (left + right >= 2) ? 2 : 1;

    } else {

        return (left * right > 0) ? 1 : 0;

    }

}



int form() {

    char c = expr[idx++];

    switch (c) {

    case '0':

    case '1':

    case '2':

        return c - '0';

    case 'P': return p;

    case 'Q': return q;

    case 'R': return r;

    case '-':

        return 2 - form();

    case '(':

        return paren();

    }

}



int main() {

    while (cin >> expr, expr != ".") {

        int cnt = 0;

        REP(i, 27) {

            idx = 0;

            int w = i;

            p = w % 3; w /= 3;

            q = w % 3; w /= 3;

            r = w % 3; w /= 3;

            int n = form();

            if (n == 2) cnt++;

        }

        cout << cnt << endl;

    }

}