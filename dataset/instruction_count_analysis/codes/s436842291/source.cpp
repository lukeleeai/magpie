#include <map>  

#include <set>  

#include <cstdio>  

#include <cmath>  

#include <cstring>  

#include <vector>  

#include <queue>  

#include <iostream>  

#include <string>  

#include <sstream>  

#include <cstdlib>  

#include <ctime>  

#include <cctype>  

#include <algorithm>  

using namespace std;  

  

  

#define pb push_back  

#define mp make_pair  

#define fillchar(a, x) memset(a, x, sizeof(a))  

#define copy(a, b) memcpy(a, b, sizeof(a))  

#define S_queue<P> priority_queue<P, vector<P>,greater<P> >  

#define FIN freopen("D://imput.txt", "r", stdin)  

  

  

typedef long long LL;  

typedef pair<int, int > PII;  

typedef unsigned long long uLL;  

template<typename T>  

void print(T* p, T* q, string Gap = " "){int d = p < q ? 1 : -1;while(p != q){cout << *p;p += d;if(p != q) cout << Gap; }cout << endl;}  

template<typename T>  

void print(const T &a, string bes = "") {int len = bes.length();if(len >= 2)cout << bes[0] << a << bes[1] << endl;else cout << a << endl;}  

  

const int INF = 0x3f3f3f3f;  

const int MAXM = 2e1 + 5;  

const int MAXN = 1e2 + 5;  

const double eps = 1e-8;  

int A[MAXM], n;  

double M;  

  

bool DFS(int x, int id, double Max, double m){

    if(id >= n) {  

        M = min(Max, M); 

        return true;  

    }  

    bool flag = false;  

    int f = (int)(A[id] * m);  

    int cnt = 1,Ma = A[id] + f,Mi = A[id] - f > 1 ? A[id] - f: 1;  

    while(cnt * x <= Ma){  

        if(cnt * x < Mi) {  

            cnt ++;  

            continue;  

        }  

        if(cnt * x >= Mi && cnt * x <= Ma){  

            double f_t = fabs(cnt * x - A[id]) / A[id] * 1.0;  

            if(DFS(cnt * x, id + 1, max(Max, f_t), m)) {  

                    flag = true;  

            }  

        }  

        cnt ++;  

    }  

    return flag;  

}  

  

bool C(double m){  

    bool flag = false;  

    int f = (int)(A[0] * m);  

    int Mi = A[0] - f > 1? A[0] - f : 1, Ma = A[0] + f;  

    for(int i = Mi;i <= Ma;i ++){  

        if(DFS(i, 1, fabs(A[0] - i) / A[0] * 1.0, m)) {  

                flag = true;  

        }  

    }  

    return flag;  

}  

  

int main(){  

    //FIN;  

    while(cin >> n){  

        for(int i = 0;i < n;i ++){  

            cin >> A[i];  

        }  

        M = INF;  

        double lb = -1,ub = 1.0;  

        while(ub - lb > eps){  

            double mid = (ub + lb) / 2.0;  

            if(C(mid)) ub = mid;  

            else lb = mid;  

        }  

        printf("%.12lf\n", M);  

    }  

    return 0;  

}  