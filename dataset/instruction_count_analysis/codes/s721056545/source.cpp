#include"stdc++.h"  

template <class T>  

inline bool rd(T &ret) {  

    char c; int sgn;  

    if(c=getchar(),c==EOF) return 0;  

    while(c!='-'&&(c<'0'||c>'9')) c=getchar();  

    sgn=(c=='-')?-1:1;  

    ret=(c=='-')?0:(c-'0');  

    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');  

    ret*=sgn;  

    return 1;  

}  

template <class T>  

inline void pt(T x) {  

    if (x <0) {  

        putchar('-');  

        x = -x;  

    }  

    if(x>9) pt(x/10);  

    putchar(x%10+'0');  

}  

using namespace std;  

typedef long long ll;  

const int MAXN = 55;  

double C[MAXN+1][MAXN+1];  

void Initial()  

{  

    memset(C, 0, sizeof C);  

    for(int i=0; i<=MAXN; ++i)  

    {  

        C[0][i] = 0.0;  

        C[i][0] = 1.0;  

    }  

    for(int i=1; i<=MAXN; ++i)  

    {  

        for(int j=1; j<=MAXN; ++j)  

        C[i][j] = C[i-1][j] + C[i-1][j-1];  

    }  

}  

const int N = 110;  

int n, m;  

int l, t[N], v[N];  

double p[N];  

double Pow(double x, int y){  

    double ans = 1.0;  

    while(y){  

        if(y&1)ans *= x;  

        x = x*x;  

        y >>= 1;  

    }  

    return ans;  

}  

double work(int x){  

    double ans = 0.0;  

    for(int i = 0; i <= m; i++)  

    {  

        double pp = C[m][i] * Pow(p[x], i) * Pow(1.0-p[x], m-i);  

        for(int j = 1; j <= n; j++)  

        {  

            if(j == x)continue;  

            double siz = 0;  

            for(int k = m; k >= 0; k--)  

            {  

                if(l*v[j] + i*t[x]*v[j]*v[x] < l*v[x] + k*t[j]*v[x]*v[j])  

                    siz += C[m][k] * Pow(p[j], k) * Pow(1.0-p[j], m-k);  

                else break;  

            }  

            pp *= siz;  

        }  

        ans += pp;  

    }  

    return ans;  

}  

void input(){  

    for(int i = 1; i <= n; i++)  

        {  

            rd(p[i]);rd(t[i]);rd(v[i]);  

            p[i] /= 100.0;  

        }  

}  

int main(){  

    Initial();  

    while(cin>>n>>m>>l){  

        input();  

        for(int i = 1; i <= n; i++)  

            printf("%.10f\n", work(i));  

    }  

    return 0;  

}  