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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define ALL(a) (a).begin(),(a).end()

#define EXIST(s,e) ((s).find(e)!=(s).end())

#define SORT(c) sort((c).begin(),(c).end())



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



#define MAX_VAL 26



std::string ReplaceString(std::string& subject, const std::string& search,

                          const std::string& replace) {

    size_t pos = 0;

    while ((pos = subject.find(search, pos)) != std::string::npos) {

         subject.replace(pos, search.length(), replace);

         pos += replace.length();

    }

    return subject;

}



int main() {

    string expr;

    while (getline(cin, expr), expr != ".") {

        ReplaceString(expr, "--", "");



        string expr_copy = expr;

        int count = 0;

        for (int v = 0; v <= 26; v++) {

            expr = expr_copy;

            int w = v;

            int p = w % 3; w /= 3;

            int q = w % 3; w /= 3;

            int r = w % 3; w /= 3;



            REP(i, expr.size()) {

                switch (expr[i]) {

                case 'P':

                    expr[i] = '0' + p;

                    break;

                case 'Q':

                    expr[i] = '0' + q;

                    break;

                case 'R':

                    expr[i] = '0' + r;

                    break;

                }

            }



            while (expr.size() > 1) {

                stack<int> parens;

                REP(i, expr.size()) {

                    // NOT

                    ReplaceString(expr, "-0", "2");

                    ReplaceString(expr, "-1", "1");

                    ReplaceString(expr, "-2", "0");

                    if (expr[i] == '(') {

                        parens.push(i);

                        continue;

                    } else if (expr[i] == ')') {

                        int j = parens.top(); parens.pop();

                        int a = expr[j+1] - '0';

                        int b = expr[j+3] - '0';

                        string ret;

                        if (expr[j+2] == '+') {

                            // OR

                            if (a == b) ret = a + '0';

                            else ret = a + b >= 2 ? "2" : "1";

                        } else {

                            // AND

                            if (a == 2 && b == 2) ret = "2";

                            else ret = a * b > 0 ? "1" : "0";

                        }

                        string e = string(expr.begin() + j, expr.begin() + i + 1);

                        ReplaceString(expr, e, ret);

                        break;

                    }

                }

            }



            if (expr == "2") {

                count++;

            }

        }

        cout << count << endl;

    }

}